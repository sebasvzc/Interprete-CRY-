#!/bin/bash

yacc -v Lab2.y
gcc y.tab.c -o ejecutable
./ejecutable < prueba.txt
