#include <cstdio>
#include <windows.h>
#include <conio.h>
#include "Maze.h"
using namespace std;

char a[50][50] = { "############",
				"#O#    #   #",
				"#   ## # # #",
				"#####    # #",
				"#     #### #",
				"# #####  # #",
				"#       ##  ",
				"############" };

void Maze::Hide()//用于隐藏控制台光标 
{
	HANDLE				hOut;
	CONSOLE_CURSOR_INFO	curInfo;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	curInfo.dwSize = 1;
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(hOut, &curInfo);
}

void Maze::Welcome()//欢迎界面 
{
	cout << "\n\n           走 迷 宫";
	cout << "\n\n        请按任意键开始";
	_getch();
	system("cls");
}

void Maze::Set()//设置光标到初始位置 
{
	HANDLE hOut;
	COORD pos = { 0,0 };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

 void Maze::maze(){
	Hide();
	Welcome();
	int x = 1, y = 1;
	char ch;
	for (int i = 0; i <= 7; i++)
		puts(a[i]);
	while (1)
	{
		ch = _getch();
		if (ch == 's')//下
		{
			if (a[x + 1][y] == ' ')
			{
				a[x][y] = ' ';
				x++;
				a[x][y] = 'O';
			}
		}
		else if (ch == 'w')//上
		{
			if (a[x - 1][y] == ' ')
			{
				a[x][y] = ' ';
				x--;
				a[x][y] = 'O';
			}
		}
		else if (ch == 'a')//左
		{
			if (a[x][y - 1] == ' ')
			{
				a[x][y] = ' ';
				y--;
				a[x][y] = 'O';
			}
		}
		else if (ch == 'd')//右
		{
			if (a[x][y + 1] == ' ')
			{
				a[x][y] = ' ';
				y++;
				a[x][y] = 'O';
			}
		}
		Set();
		for (int i = 0; i <= 7; i++)
			puts(a[i]);
		if (x == 6 && y == 11)
			break;
	}

	m_player->pickItem(1);
	m_player->pickItem(1);

	Sleep(10000);
}