#ifndef COLOR_H
#define COLOR_H
#include <windows.h>  // For SetConsoleTextAttribute
#include <iostream>
using namespace std;
inline void setColor(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void transitionEffect(string message);
void examTimer(int seconds); 
void showScore(int finalScore);
void displayScoreChart(int score);
void mainMenu();
#endif
