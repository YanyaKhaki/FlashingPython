# include <iostream>
# include <windows.h>
# include <time.h>
# include <conio.h>
#include "pythonfunctions.h"

using namespace std;

void game()
{
    while (1)
    {
        if (kbhit() == true) //если нажата клавиша
            control();

        nextStep();

        if(checkRabbit() == false)
            addRabbit();

        showField();

        Sleep(SPEED);
    }
}

int main ()
{
    coordX[1] = 1;
    coordY[1] = 2;
    coordX[2] = 1;
    coordY[2] = 1;
    system("color 20");
    cout << "Welcome to the greatest game ever!\n\n           PYTHON 1.0\n\n";
    cout << "Good luck! Use the following keys:\nW-up, S-down, A-left, D-right,\nSpace-PAUSE, Esc-EXIT.\n";
    cout << "But firstly choose your level:\n";
    cout << "1 - field 15x20, speed-min\n";
    cout << "2 - field 15x20, speed-normal\n";
    cout << "3 - field 15x20, speed-max\n";
    cout << "4 - field 20x40, speed-min\n";
    cout << "5 - field 20x40, speed-normal\n";
    cout << "6 - field 20x40, speed-max\n";

    char symbol = getch();
    switch (symbol)
    {
    case '1': N=15;M=20;SPEED=300;game();break;
    case '2': N=15;M=20;SPEED=150;game();break;
    case '3': N=15;M=20;SPEED=80;game();break;
    case '4': N=20;M=40;SPEED=300;game();break;
    case '5': N=20;M=40;SPEED=150;game();break;
    case '6': N=20;M=40;SPEED=80;game();break;
    default :break;
    }
}
