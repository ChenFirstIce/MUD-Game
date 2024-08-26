#include <iostream>
#include "map.h"


using namespace std;

Map::Map() :npc(0) {
	position = 4;
	dx = 1;
	dy = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::Map(int p) :npc(p) {
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

Map::~Map()
{
}


void Map::ShowMap()
{
	system("cls");
	cout << "地图1:" << endl;
	
	cout << "            _____________               _____________" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   警察局    |             |   青岛北站  |" << endl;
	cout << "           |     "<<pos[0][0]<<"       |             |     "<<pos[0][2]<<" | " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "           |             |             |             |" << endl;
	cout << "           |   望海餐厅  |  信息南楼   |   校医院    |" << endl;
	cout << "           |     "<<pos[1][0]<<"       |     "<<pos[1][1]<<"       |     "<<pos[1][2]<<"| " << endl;
	cout << "           |_____________|_____________|_____________|" << endl;
	cout << "                         |             |" << endl;
	cout << "                         |     操场    |" << endl;
	cout << "                         |     "<<pos[2][1]<<" | " << endl;
	cout << "                         |_____________|" << endl;
	cout << "您现在的位置为" << mapName[position] << endl;
}

void Map::Move(char order)
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
	pos[dx][dy] = '*';
	switch
	npc = Npc(position);		//更新npc
	showRoom();
}

bool Map::isThereChat()
{
	if (position == 0 || position == 2 || position == 4 || position == 5 || position == 7 || position == 9)
		return true;
	else return false;
}

bool Map::isThereFight()
{
	if (position == 1 || position == 3 || position == 4 || position == 5 || position == 6 || position == 7 || position == 8 || position == 9)
		return true;
	else return false;
}

int Map::getPosition()
{
	return position;
}

string Map::getNpcName() {
	return npc.getName();
}

void Map::setNpc(Npc newNpc) {
	npc = newNpc;
}

Role Map::chatToNpc(Role player) {
	return npc.chat(player);
}

int Map::getNpcGoodsId() {
	return npc.getGoodsId();
}

int Map::getNpcGoodsNum() {
	return npc.getGoodsNum();
}

string Map::getName()
{
	return mapName[position];
}
