#!/bin/bash

yacc -v Lab.y
gcc y.tab.c -o ejecutable
./ejecutable < prueba.txt
