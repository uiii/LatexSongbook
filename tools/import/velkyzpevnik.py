#! /usr/bin/env python
# -*- conding: utf-8 -*-

"""
Usage:
    velkyzpevnik.py <author> <song> <tune> [-o PATH | --output=PATH]
    velkyzpevnik.py <song-url> <tune> [-o PATH | --output=PATH]
    velkyzpevnik.py -h | --help

Options:
    -h, --help                Show this screen.
    -o PATH, --output PATH    Print song into file specified by PATH
                              instead of standard output.
                              PATH can be either file or directory.
                              When directory is specified, the output
                              file is placed there and its name is
                              in the form '<author>.<song>.txt'.
"""

from docopt import docopt
from urllib import request
from bs4 import BeautifulSoup
from bs4 import element
import re
import os

def getHtml(url):
    try:
        page = request.urlopen(url)
    except:
        error("Url is not valid")

    source = page.read().decode('utf-8')
    return BeautifulSoup(source)

def error(message):
    print("ERROR: " + message)
    exit(1)

if __name__ == '__main__':
    args = docopt(__doc__)
    print(args)

    baseUrl = "http://velkyzpevnik.cz"

    songUrl = args['<song-url>']

    if not songUrl:
        songUrl = baseUrl + "/zpevnik/" + args['<author>'] + "/" + args['<song>']

    html = getHtml(songUrl)

    input = html.find('input', attrs={"name":"tune"}) or error("Song not found")
    currentTune = input['value']
    requiredTune = re.sub(r'mi', '', args['<tune>']) # remove 'mi' suffix if present

    if currentTune != requiredTune:
        input = html.find('input', attrs={"name":"id"}) or error("Song is not valid")
        songId = input['value']
        html = getHtml(baseUrl + "/song.php?new_tune=" + requiredTune + "&tune=" + currentTune + "&id=" + songId)

    title = re.sub(r'(.+) - (.+)', r'\2 (\1)', html.title.string)

    songHtml = html.find('pre', class_="pisen") or error("Song is not valid")
    #print(songHtml)

    for el in songHtml.findAll('span', class_="chord"):
        el.replaceWith("@@" + el.string)

    song = re.sub(r'(^|\n) ( *)@@([^\n]+)', r'\1:\2@@\3', songHtml.get_text())
    song = re.sub(r'@@', '', song)

    if args['--output']:
        outputPath = args['--output']

        if outputPath.endswith(os.sep):
            if not os.path.isdir(outputPath):
                error("Directory not exists: " + outputPath)

        if os.path.isdir(outputPath):
            outputPath = outputPath + os.sep + re.sub(r'.*/([^/]+)/([^/]+)/?', r'\1.\2.txt', songUrl)

        outputFile = open(outputPath, 'w')
        outputFile.write(title + "\n\n")
        outputFile.write(song)
    else:
        print(title + "\n")
        print(song)
