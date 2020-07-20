#!/bin/bash
for FILE1 in "$@"
do
g++ "$FILE1" -o firstOpenGlApp -lglut -lGLU -lGL
done

