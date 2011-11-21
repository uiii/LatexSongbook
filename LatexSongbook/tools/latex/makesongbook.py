#! /usr/bin/env python
# -*- conding: utf-8 -*-

import sys
import os
import song2latex
import shutil
import locale

def strxfrm(song):
    return (locale.strxfrm(song[0]), locale.strxfrm(song[1]), song[2])

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("usage: python makesongbook.py <input-dir> [output-dir]")
        sys.exit(1)
    else:
        inputdir = sys.argv[1]
        outputdir = sys.argv[1]

        if len(sys.argv) == 3:
            outputdir = sys.argv[2]

        filelist = os.listdir(inputdir)

        outputlist = []
        for filename in filelist:
            try:
                song = song2latex.convert(
                        os.path.join(inputdir, filename),
                        outputdir
                )

                outputlist.append(song)
            except Exception as e:
                print(e)

        locale.setlocale(locale.LC_ALL, "")
        outputlist.sort(key=strxfrm)

        indexfile = open(os.path.join(outputdir, "songindex.tex"), "w")

        listfile = open(os.path.join(outputdir, "songlist.tex"), "w")

        indexfile.write(
                "\\clearpage%\n"
                "\\fontsize{9pt}{10pt}\\selectfont%\n"
                "\\newgeometry{hscale=.9, vscale=.9, vcentering=true, hcentering=true}%\n"
                "\\noindent%\n"
                "{\\titlefont Seznam písní - podle názvu%\n"
                "\\vspace{1em}}%\n"
                "\\setlength{\columnsep}{3ex}%\n"
                "\\raggedcolumns%\n"
                "\\begin{multicols*}{2}%\n")

        currentLetter = ""
        songlistbyauthor = []
        for song in outputlist:
            currenttitle = song[0]
            if currenttitle[0] != currentLetter:
                if currenttitle[0:2] == "Ch":
                    currentLetter = currenttitle[0:2]
                    currenttitle = currenttitle[2:]
                else: 
                    currentLetter = currenttitle[0]
                    currenttitle = currenttitle[1:]

                indexfile.write("\n\t\\par\\noindent{\\bfseries " + currentLetter + "}%")

            indexfile.write("\n\t" + currenttitle + " \dotfill {\\itshape " + song[1] + "}\\\\")

            listfile.write("\\input{{{0}}}\n".format(song[2]))

            songlistbyauthor.append((song[1], song[0], song[2]))

        indexfile.write(
                "\\end{multicols*}%\n"
                "\n\\clearpage%\n"
                "\\noindent%\n"
                "{\\titlefont Seznam písní - podle autora%\n"
                "\\vspace{1em}}%\n"
                "\\setlength{\columnsep}{4ex}%\n"
                "\\begin{multicols*}{2}%\n")

        songlistbyauthor.sort(key=strxfrm)
        currentauthor = ""
        for song in songlistbyauthor:
            if song[0] != currentauthor:
                currentauthor = song[0]
                indexfile.write("\n\t\\par\\noindent{\\bfseries " + song[0] + "} %")

            indexfile.write("\n\t\\hspace*{0pt}\\dotfill " + song[1] + "\\\\")

        indexfile.write("\n\\end{multicols*}")
        indexfile.close()

        listfile.write("\\input{songindex}\n")
        listfile.close()

        os.system(
                "cd " + outputdir +
                "&& pdflatex songbook.tex"
                "&& pdfnup songbook.pdf --nup 2x1"
                "&& mv songbook-nup.pdf songbook.pdf"
                "&& evince songbook.pdf &"
        )
    
    rundir = os.path.dirname(sys.argv[0])
    shutil.rmtree(os.path.join(rundir, "__pycache__"), True)
