#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "matrix.h"
#define ilosc 39

//the header file for functions containted in matrix.c


int safelosowanie();
void przesuwacz(char a[][80]);
void init();
void deinit();
int kolor(int, int);
void przywitanie();




#endif // MATRIX_H_INCLUDED
