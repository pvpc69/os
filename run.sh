#!/bin/sh
# usage: ./run.sh look      (compiles look.c and runs it with look.in if present)
gcc "$1.c" -o "$1.out" && if [ -f "$1.in" ]; then ./"$1.out" < "$1.in"; else ./"$1.out"; fi
