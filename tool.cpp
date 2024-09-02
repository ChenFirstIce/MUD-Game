#include<iostream>
#include <windows.h>
#include"tool.h"
using namespace std;

void gotoXY(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clear(int x, int y, int w, int h)
{
	for (int i = 0; i < h; i++) {
		gotoXY(x, y + i);
		for (int j = 0; j < w; j++) putchar(' ');
	}
}