#! /usr/bin/env python
# -*- conding: utf-8 -*-

import sys
import os
import song2latex
import shutil

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

        outputlist.sort()

        listfile = open(os.path.join(outputdir, "songlist.tex"), "w")
        for song in outputlist:
            listfile.write("\\input{{{0}}}\n".format(song[1]))
    
    rundir = os.path.dirname(sys.argv[0])
    shutil.rmtree(os.path.join(rundir, "__pycache__"), True)
