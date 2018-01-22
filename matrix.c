#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#define ilosc 39

int kolumna[ilosc];
int nznakow[ilosc];
int trigger;
int zmienna = 1;

int safelosowanie ()        //this fuction is needed to forbid choosing the same column twice by the program
    {
        int r, k, x = (rand() % 40)*2;
        for (r = 0; r < ilosc; r++)
        {
            if (kolumna[r] == x) k = 1;
        }
        if (k == 1) return safelosowanie();
        else return x;
    }

void przesuwacz(char a[][80])       //this function is responsible for moving chars down in the array, randomize chars and drawing new columns to start dropping
{
    if (trigger < ilosc)
    {
        kolumna[trigger] = safelosowanie ();
        trigger++;
    }

    int i, k;
    for (k = 0; k<trigger; k++)
    {
        for (i = 23; i>0; i--)
        {
            a[i][kolumna[k]] = a[i-1][kolumna[k]];
        }
        nznakow[k] += 1;
        if (nznakow[k] < 24) a[0][kolumna[k]] = rand() % 94 + 33;
        else if (nznakow[k] >= 24 && nznakow[k] < 48) a[0][kolumna[k]] = ' ';
        else
        {
        nznakow[k] = 0;
        kolumna[k] = safelosowanie ();
        }
    }
}

void init()         //init is used at the beggining to initialize the screen and assignment of colors to numbers
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1,COLOR_GREEN, COLOR_BLACK);
	init_pair(2,COLOR_YELLOW, COLOR_BLACK);
	init_pair(3,COLOR_BLUE, COLOR_BLACK);
	init_pair(4,COLOR_RED, COLOR_BLACK);
	init_pair(5,COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6,COLOR_CYAN, COLOR_BLACK);
	init_pair(7,COLOR_WHITE, COLOR_BLACK);
}

void deinit()       //ends the program
{
	endwin();
	exit(0);
}

int kolor (int x, int klawisz)      //checks the key pressed and accordingly changes color
{
    if (klawisz == 27) deinit();
    else if (klawisz == 49) return 1;
    else if (klawisz == 50) return 2;
    else if (klawisz == 51) return 3;
    else if (klawisz == 52) return 4;
    else if (klawisz == 53) return 5;
    else if (klawisz == 54) return 6;
    else return x;
}

void przywitanie()          //this function is used to display starting screen, informs the user about available colors
{
    printw("Dostepne kolory:\n");
    attron(A_BOLD | COLOR_PAIR(1));
    printw("1 - Zielony\n");
    attron(A_BOLD | COLOR_PAIR(2));
    printw("2 - Zolty\n");
    attron(A_BOLD | COLOR_PAIR(3));
    printw("3 - Niebieski\n");
    attron(A_BOLD | COLOR_PAIR(4));
    printw("4 - Czerwony\n");
    attron(A_BOLD | COLOR_PAIR(5));
    printw("5 - Magenta\n");
    attron(A_BOLD | COLOR_PAIR(6));
    printw("6 - Cyjan\n");
    attron(A_BOLD | COLOR_PAIR(7));
    printw("Klawisz Escape konczy dzialanie programu\n");   //ends
    printw("Nacisnij spacje by przejsc do symualcji");      //to start the simulation press SPACE
    while(zmienna)                                          //waits for user to acquaint with the options
    {
        int znak;
        znak = getch();
        if (znak == 32) zmienna = 0;
    }
}
