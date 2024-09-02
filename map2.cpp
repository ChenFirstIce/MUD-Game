#include <iostream>
#include "map.h"
#include"tool.h"


using namespace std;

void Map::setPosition2(int p) {
	position = p;
	if (p == 1) {
		dx = 0;
		dy = 0;
	}
	if (p == 2) {
		dx = 0;
		dy = 1;
	}
	if (p == 3) {
		dx = 0;
		dy = 2;
	}
}
/*
Map::Map(int p) :Player(p) {
	position = p;
	if (p == 1) {
		dx = 0;
		dy = 0;
	}
	if (p == 2) {
		dx = 0;
		dy = 1;
	}
	if (p == 3) {
		dx = 0;
		dy = 2;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}
*/



void gotoc() {
	system("cls");
	gotoXY(55, 10);
	cout << "地 图";
	gotoXY(56, 20);
	cout << "加载中...";
	for (int j = 0; j < 100; j++) {
		Sleep(17);
		ggotoXY(j + 3, 15);
		cout << " " << j << "%";
		cout << "■";
	}
	system("cls");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 40; j++) {
			gotoXY(i, j);
			cout << "■";
			//SetColor(rand()%10);
		}
	}
	system("cls");
}
void Map::ShowMap2()
{
	system("cls");
	cout << "地图1:" << endl;
	cout << " __________ __________ __________ " << endl;
	cout << "|          |          |          |" << endl;
	cout << "| 废弃工厂 |   商店   |  咖啡馆  |" << endl;
	cout << "|     " << pos[0][0] << "    |    " << pos[0][1] << "     |    " << pos[0][2] << "     |" << endl;
	cout << "|__________|__________|__________|" << endl;
	cout << "您现在的位置为" << mapName2[position] << endl;
}

void Map::Move2(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
			cout << "移动失败" << endl;
	}
	case 'a': {
		if (position == 2 || position == 3) {
			dy--;
			position--;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 's': {
			cout << "移动失败" << endl;
	}
	case 'd': {
		if (position == 1 || position == 2) {
			dy++;
			position++;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	default:
		break;
	}
}

int Map::getPosition2()
{
	return position;
}
