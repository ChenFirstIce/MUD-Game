#include <iostream>
#include "Map.h"
#include"tool.h"


using namespace std;

void Map::setPosition1() {
	position = m_player->currentRoom();
	int p = m_player->currentRoom();

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

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pos[i][j] = ' ';
		}
	}

	pos[dx][dy] = '*';
}

void Map::ShowMap1()
{
	system("cls");
	cout << "地图1:" << endl;

	cout << "            _____________               _____________" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   望海苑    |             |   青岛北站  |" << endl;
	cout << "           |      " << pos[0][0] << "      |             |      " << pos[0][2] << "      | " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   望海餐厅  |  信息南楼   |   图书馆    |" << endl;
	cout << "           |      " << pos[1][0] << "      |      " << pos[1][1] << "      |      " << pos[1][2] << "      | " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "                         |             |" << endl;
	cout << "                         |     操场    |" << endl;
	cout << "                         |      " << pos[2][1] << "      | " << endl;
	cout << "                         |_____________|" << endl;
	cout << "您现在的位置为" << mapName[position - 1] << endl;
}

bool Map::Move1(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
		if (position == 3 || position == 5 || position == 1) {
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
		if (position == 2 ) {
			dy--;
			position++;
		}
		else if (position == 5) {
			position = 2;
			dy--;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 's': {
		if ( position == 2 || position == 4 || position == 6) {
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
		if (position == 3 ) {
			dy++;
			position--;
		}
		else if (position == 2) {
			position = 5;
			dy++;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case '1':
		m_player->currentRoom() = position;
		return 1;
	default:
		break;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';

	return 0;
}