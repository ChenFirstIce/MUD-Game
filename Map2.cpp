#include <iostream>
#include "map.h"
#include "tool.h"


using namespace std;

void Map::setPosition2(int p) {//±àºÅ
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

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
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

void Map::ShowMap2()
{
	system("cls");
	cout << "033[33m";
	cout << "µØÍ¼1:" << endl;
	cout << " __________ __________ __________ " << endl;
	cout << "|          |          |          |" << endl;
	cout << "| ·ÏÆú¹¤³§ |   ÉÌµê   |  ¿§·È¹Ý  |" << endl;
	cout << "|     " << pos[0][0] << "    |    " << pos[0][1] << "     |    " << pos[0][2] << "     |" << endl;
	cout << "|__________|__________|__________|" << endl;
	cout << "ÄúÏÖÔÚµÄÎ»ÖÃÎª" << mapName2[position] << endl;
	cout << "033[0m";
}

void Map::Move2(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
		cout << "ÒÆ¶¯Ê§°Ü" << endl;
	}
	case 'a': {
		if (position == 2 || position == 3) {
			dy--;
			position--;
		}
		else
		{
			cout << "ÒÆ¶¯Ê§°Ü" << endl;
		}
		break;
	}
	case 's': {
		cout << "ÒÆ¶¯Ê§°Ü" << endl;
	}
	case 'd': {
		if (position == 1 || position == 2) {
			dy++;
			position++;
		}
		else
		{
			cout << "ÒÆ¶¯Ê§°Ü" << endl;
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