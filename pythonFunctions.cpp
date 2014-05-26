#include "pythonfunctions.h"
# include <windows.h>
# include <iostream>
# include <conio.h>

void showField()
{
    system("cls");
    for (int i = 0; i <= (N + 1); ++i)
        for (int j = 0; j <= (M + 1); ++j)
            std::cout << (i == 0 || j == 0 || i == (N + 1) || j == (M + 1) ? 'x' : a[i][j]) << (j <= M ? "" : "\n");
}
void showPython()
{
    if(directionX == -1 && directionY == 0) a[coordX[1]][coordY[1]] = 30; //голова вверх
    if(directionX == 1 && directionY == 0) a[coordX[1]][coordY[1]] = 31; //голова вниз
    if(directionX == 0 && directionY == 1) a[coordX[1]][coordY[1]] = 16; //голова вправо
    if(directionX == 0 && directionY == -1) a[coordX[1]][coordY[1]] = 17; //голова влево

    for (int i = 2; i <= pythonSize; ++i)
        a[coordX[i]][coordY[i]] = 254; //единица тела питона
}
void clearPython()
{
    for (int i = 1; i <= pythonSize; ++i)
        a[coordX[i]][coordY[i]] = ' ';
}
bool gameOver()
{
    for (int i = 2; i <= pythonSize; ++i)
        if (coordX[1] == coordX[i] && coordY[1] == coordY[i])
        {
            system("color 40");
            return true;
        }
    return false;
}
void checkCoords()
{
    if (coordX[1] > N) coordX[1] = 1;
    if (coordX[1] < 1) coordX[1] = N;
    if (coordY[1] > M) coordY[1] = 1;
    if (coordY[1] < 1) coordY[1] = M;
}
bool checkRabbit()
{
    if(rabbitX == -1 && rabbitY == -1)
        return false;
    return true;
}
void addRabbit()
{
        int x = rand(), y = rand();
        if(x < 0) x *= -1; //избавляемся от отрицательных координат
        if(y < 0) y *= -1;
        x %= (N + 1); //загоняем кролика в наше поле
        y %= (M + 1);
        if(x == 0) ++x;
        if(y == 0) ++y;
        if(a[x][y] != 'x' && a[x][y] != 'v' && a[x][y] != '^' && a[x][y] != '<' && a[x][y] != '>')
        {
            rabbitX = x;
            rabbitY = y;
            a[x][y] = 253; //кролик
            return;
        }
}
void nextStep()
{
    clearPython();

    for (int i = pythonSize; i >= 2; --i) //для тела
    {
        coordX[i] = coordX[i - 1];
        coordY[i] = coordY[i - 1];
    }

    coordX[1] += directionX; //для головы
    coordY[1] += directionY; //для головы

    checkCoords();

    if(coordX[1] == rabbitX && coordY[1] == rabbitY) //процесс поедания:)
    {
        pythonSize++;
        rabbitX = -1;
        rabbitY = -1;
    }

    showPython();

    if (pythonSize==10) //level up
    {
        std::cout << "LEVEL UP!\n";
        SPEED = 1.05 * SPEED; //увеличиваем скорость
        system("color 10"); //меняем цвет консоли
    }

    if (pythonSize==20)
    {
        std::cout << "LEVEL UP!\n";
        SPEED = 1.05 * SPEED;
        system("color 90");
    }
    if (pythonSize==40)
    {
        std::cout << "LEVEL UP!" << std::endl << "Keep it up!\n";
        SPEED = 1.05 * SPEED;
        system("color 70");
    }

    if (gameOver() == true)
    {
        std::cout << "\nGAME OVER...Be careful next time!\n";
        system("pause");
        exit(0);
    }
}
void control()
{
    char symbol = getch();
    switch (symbol)
    {
    case 'w':
        if(directionX != 1 || directionY != 0)
        {
            directionX = -1;
            directionY = 0;
        }
        break;
    case 'a':
        if(directionX != 0 || directionY != 1)
        {
            directionX = 0;
            directionY = -1;
        }
        break;
    case 's':
        if(directionX != -1 || directionY != 0)
        {
            directionX = 1;
            directionY = 0;
        }
        break;
    case 'd':
        if(directionX != 0 || directionY != -1)
        {
            directionX = 0;
            directionY = 1;
        }
        break;
    case 32: //space
        std::cout << "\nPAUSE\n";
        getch();
        break;
    case 27: //enter
        std::cout << "\nEXIT? :( Hope, I'll see you soon.\n";
        system("pause");
        exit(0);
        break;
    default :
        break;
    }
}
