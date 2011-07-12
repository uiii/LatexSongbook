#! /usr/bin/env python
# -*- conding: utf-8 -*-

import sys
import re
import unicodedata
import os

class SyntaxError(Exception):
    def __init__(self, filename, lineNumber, error, line):
        self.filename = filename
        self.lineNumber = lineNumber
        self.error = error
        self.line = line

    def __str__(self):
        return "[" + self.filename + ":" + str(self.lineNumber) + "] Sytax error: " + self.error + ": " + self.line

def convert(inputfilename, outputfilename):
    infile = open(inputfilename)

    lineNumber = 0

    line = ""
    while line == "":
        line = infile.readline()
        line = line.replace("\n", "")
        lineNumber += 1

    headline = re.match("^(.*[^ ])[ ]*\((.+)\)", line)
    if headline == None:
        raise SyntaxError(inputfilename, lineNumber, "Invalid song headline", line)

    songtitle = headline.group(1)
    songauthor = headline.group(2)

    output = "\\begin{{song}}{{{0}}}{{{1}".format(songtitle, songauthor)

    chords = []

    for line in infile:
        line = line.replace("\n", "")
        if line == "":
            continue

        if line[0] == ":":
            # chord line 
            chordlist = re.findall("([ ]+|[^ ]+)", line[1:])

            skip = 1
            chords = []
            for item in chordlist:
                if item[0] == ' ':
                    skip += len(item)
                else:
                    chord = formatChord(item)
                    chords.append((skip, chord))
                    skip += len(item)

#print("chords: " + str(chords))

        else:
            line = applyChords(line, chords)

            if re.match("^[0-9]+\.[ ]*[^ ].*", line):
#print("verse: " + line)
                line = re.sub("^[0-9]+\.[ ]*([^ ].*)$", "\\1", line)
                output += "}}\n\t\\Verse {{{0}".format(line)

            elif re.match("^(Ref|Rec)( [0-9]+)?(\.|:).*", line):
#print("special: " + line)
                specialStr = re.sub("^([^\.:]+)(\.|:).*", "\\1", line)
                specialStr = re.sub("(Ref|Rec) ([0-9+])", "\\1[\\2]", specialStr)
                line = re.sub("^([^\.:]+)(\.|:)[ ]*(|[^ ].*)", "\\3", line)
                output += "}}\n\t\\{0} {{{1}".format(specialStr, line)

            elif re.match("^[^\.: ]+(\.|:).*", line):
                label = re.sub("^([^\.:]+)(\.|:).*", "\\1", line)
#label = re.sub("\*", "$\star$", label)
                line = re.sub("^([^\.:]+)(\.|:)[ ]*(|[^ ].*)", "\\3", line)
                output += "}}\n\t\\Label{{{0}}} {{{1}".format(label, line)

            else:
#print("normal: " + line)
                line = re.sub("^[ ]+([^ ].*)", "\\1", line)
                output += "\\n\n\t{0}".format(line)

    output += "}\n\\end{song}"

    output = re.sub("((\[:)|(:\]))", "$\\1$", output)
    output = re.sub("\*", "$\\star$", output)
    #output = re.sub("\|[ ]*\|", "\\;", output)
    output = re.sub("\"([^\"]*)\"", "\\uv{\\1}", output)
#print(output)

    if outputfilename == None:
        outputfilename = os.path.dirname(inputfilename)

    if os.path.isdir(outputfilename):
        outputfilename = os.path.join(outputfilename, makeFileName(songtitle + "." + songauthor + ".tex"))

    print("create song ... " + outputfilename)
    outfile = open(outputfilename, 'w')
    outfile.write(output)

    return (songtitle + " " + songauthor, makeFileName(songtitle + "." + songauthor))

def makeFileName(str):
    filename = unicodedata.normalize('NFKD', str).encode('ASCII', 'ignore').decode()
    filename = re.sub("[ \-/\\:,]", "_", filename)
    filename = re.sub("[^a-zA-Z0-9\.\_]", "", filename)
    filename = filename.lower()
    return filename
            
def formatChord(str):
#re.sub("^([A-H])(|#|b)(|[4,5,6,7,9,11,13]+(\+|\-)?(/[4,5,9](\+|\-)?)?)"
    chord = re.sub("^([a-hA-H])(|#|b)(|[0-9\+\-/]+)(|[a-z]+)(|[0-9\+\-/]+)$", "\\1^{\\2\\3}\\4^{\\5}", str)
    chord = re.sub("\^{}", "", chord)
    chord = re.sub("}\^{", "", chord)
    chord = re.sub("#", "\\sharp", chord)
    chord = re.sub("b", "\\flat", chord)
    return chord

def applyChords(line, chords):
    output = ""
    pos = 0
    chordBefore = False
    while chords:
        chord = chords.pop(0)
        output += line[:chord[0]-pos] + ("||" if chordBefore else "|") + chord[1] + "|"
        line = line[chord[0]-pos:]
        pos = chord[0]
        chordBefore = True
    return output + line + ("|" if chordBefore else "")

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("usage: python song2latex.py <input-file> [output-file]")
        sys.exit(1);
    else:
        inputfile = sys.argv[1]
        outputfile = sys.argv[1] + ".tex"

        if len(sys.argv) == 3:
            outputfile = sys.argv[2]

        try:
            convert(intputfile, outputfile)
        except Exception as e:
            print(e)
