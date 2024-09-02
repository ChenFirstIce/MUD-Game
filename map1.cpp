#include <iostream>
#include "map.h"
#include"tool.h"


using namespace std;

void Map::setPosition1(int p) {
	position = p;
	if (p == 1) {
		dx = 2;
		dy = 1;
	}
	if (p == 2) {
		dx = 1;
		dy = 1;
	}
	if (p == 3) {
		dx = 1;
		dy = 0;
	}
	if (p == 4) {
		dx = 0;
		dy = 0;
	}
	if (p == 5) {
		dx = 1;
		dy = 2;
	}
	if (p == 6) {
		dx = 0;
		dy = 2;
	}
}
/*
Map::Map(int p) :player(p) {
	position = p;
	
	
	if (p == 1) {
		dx = 2;
		dy = 1;
	}
	if (p == 2) {
		dx = 1;
		dy = 1;
	}
	if (p == 3) {
		dx = 1;
		dy = 0;
	}
	if (p == 4) {
		dx = 0;
		dy = 0;
	}
	if (p == 5) {
		dx = 1;
		dy = 2;
	}
	if (p == 6) {
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

Map::~Map() {
	
}


Map::Map() {

}

void gotoc1() {
	system("cls");
	gotoXY(55, 10);
	cout << "地 图";
	gotoXY(56, 20);
	cout << "加载中...";
	for (int j = 0; j < 100; j++) {
		Sleep(17);
		gotoXY(j+3, 15);
		cout<< " " << j << "%";
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

void Map::ShowMap1()
{
	system("cls");
	cout << "033[33m";
	cout << "地图1:" << endl;
	
	cout << "            _____________               _____________" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   警察局    |             |   青岛北站  |" << endl;
	//cout << "           |     "<<pos[0][0]<<"       |             |     "<<pos[0][2]<<" | " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   望海餐厅  |  信息南楼   |   校医院    |" << endl;
	//cout << "           |     "<<pos[1][0]<<"       |     "<<pos[1][1]<<"       |     "<<pos[1][2]<<"| " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "                         |             |" << endl;
	cout << "                         |     操场    |" << endl;
	//cout << "                         |     "<<pos[2][1]<<" | " << endl;
	cout << "                         |_____________|" << endl;
	cout << "您现在的位置为" << mapName1[position] << endl;
	cout << "033[0m";
}

void Map::Move1(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
		if (position == 3 || position == 5 || position == 6) {
			dx--;
			position++;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 'a': {
		if (position == 5 || position == 4) {
			dy--;
			position++;
		}
		else if (position == 5) {
			position == 2;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 's': {
		if (position == 1 || position == 2 || position == 4 || position == 7 || position == 8 || position == 9) {
			dx++;
			position--;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 'd': {
		if (position == 3 || position == 5) {
			dy++;
			position--;
		}
		else if (position ==2) {
			position == 5;
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

void Map::ShowPosition(int p) {
	cout << "您现在的位置为" << mapName1[p] << endl;
}

int Map::getPosition1()
{
	return position;
}

