#!/bin/sh
gcc -o anton prozess-anton.c
gcc -o berta prozess-berta.c

time ./anton &
time ./berta &
