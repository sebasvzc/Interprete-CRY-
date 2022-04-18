#!/bin/bash

yacc -v Lab2.y
gcc y.tab.c -lfl  -o ejecutable
./ejecutable < prueba.txt
