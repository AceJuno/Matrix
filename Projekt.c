#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "matrix.h"
#define ilosc 39

char a[24][80];             //this array contains charachters displayed on screen
int kolumna[ilosc];         // this array contains information about which columns are dropping down
int nznakow[ilosc];         //this array contains number of characters un each dropping column
int trigger;                //trigger is used at the beggining to initiate falling of each column one at the time
int waiter;                 //contains information about which key was pressed
int para = 1;

int main()
{
    init();
    curs_set(0);
    przywitanie();
    int x = 24, y = 80;             //dimensions of console
    int i, k, r;
    struct timespec start, end;

    for (i = 0; i<x; i++)           //this loop fills the array with spaces
    {
        for (k = 0; k<y; k++)
        {
            a[i][k] = ' ';
        }

    }
    while (1)
    {
    start.tv_nsec = 80000000;       //this tells program how much it should wait before refreshing the screen
    waiter = getch();
    para = kolor(para, waiter);

    for (i = 0; i<x; i++)                                               //this is the main double "for" loop used to add charachters on the screen with the attributes assigned to them
            {
                for (k = 0; k<y; k++)
                {
                    for (r = 0; r < ilosc; r++)
                    {
                        if (kolumna[r] == k && nznakow[r]-19 >= i)
                        {
                            attron(A_DIM | COLOR_PAIR(para));
                            break;
                        }
                        else if (kolumna[r] == k && nznakow[r]-1 == i)
                        {
                            attroff(A_DIM | COLOR_PAIR(1));
                            attron(A_BOLD | COLOR_PAIR(7));
                            break;
                        }
                        else {
                        attroff(A_DIM | COLOR_PAIR(7));
                        attron(A_BOLD | COLOR_PAIR(para));
                        }
                    }
                    mvaddch(i, k, a[i][k]);                             //this line adds char on screen
                }
            }
            nanosleep(&start, &end);
            przesuwacz(a);
            attroff(COLOR_PAIR(1));
            attron(A_BOLD | COLOR_PAIR(7));
            refresh();
    }
}
