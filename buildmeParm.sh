#!/bin/bash
for FILE1 in "$@"
do
g++ "$FILE1".cpp -o "$FILE1" -lglut -lGLU -lGL
done

