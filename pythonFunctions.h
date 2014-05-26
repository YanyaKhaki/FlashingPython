#ifndef PYTHONFUNCTIONS_H
#define PYTHONFUNCTIONS_H

int pythonSize=2;
int coordX[1000];
int coordY[1000];
int directionX = 0;
int directionY = 1;
int rabbitX = -1;
int rabbitY = -1;
char a[1000][1000];
int M, N, SPEED;

void showField();
void showPython();
void clearPython();
bool gameOver();
void checkCoords();
bool checkRabbit();
void addRabbit();
void nextStep();
void control();

#endif // PYTHONFUNCTIONS_H
