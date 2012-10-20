#! /usr/bin/env python
# -*- conding: utf-8 -*-

"""
usage:
    velkyzpevnik.py <author> <song> <tune>
    velkyzpevnik.py <song-url> <tune>
"""

from docopt import docopt
from urllib import request
from bs4 import BeautifulSoup
from bs4 import element
import re

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

    baseUrl = "http://velkyzpevnik.cz"

    html = getHtml(baseUrl + "/zpevnik/" + args['<author>'] + "/" + args['<song>'])

    input = html.find('input', attrs={"name":"tune"}) or error("Song not found")
    currentTune = input['value']

    if currentTune != args['<tune>']:
        input = html.find('input', attrs={"name":"id"}) or error("Song is not valid")
        songId = input['value']
        html = getHtml(baseUrl + "/song.php?new_tune=" + args['<tune>'] + "&tune=" + currentTune + "&id=" + songId)

    title = re.sub(r'(.+) - (.+)', r'\2 (\1)', html.title.string)

    songHtml = html.find('pre', class_="pisen") or error("Song is not valid")
    #print(songHtml)

    for el in songHtml.findAll('span', class_="chord"):
        el.replaceWith("@@" + el.string)

    song = re.sub(r'(^|\n) ( *)@@([^\n]+)', r'\1:\2@@\3', songHtml.get_text())
    song = re.sub(r'@@', '', song)

    print(title)
    print(song)

    #re.sub(r'^( +)<span class="chord"
