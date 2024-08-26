#include <iostream>
#include "map.h"


using namespace std;

Map::Map() :npc(0) {
	position = 2;
	dx = 0;
	dy = 1;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::Map(int p) :npc(p) {
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

Map::~Map()
{
}

void Map::Store()
{
}


void Map::ShowMap()
{
	system("cls");
	cout << "��ͼ1:" << endl;
	cout << " __________ __________ __________ " << endl;
	cout << "|          |          |          |" << endl;
	cout << "| �������� |   �̵�   |  ���ȹ�  |" << endl;
	cout << "|     " << pos[0][0] << "    |    " << pos[0][1] << "     |    " << pos[0][2] << "     |" << endl;
	cout << "|__________|__________|__________|" << endl;
	cout << "�����ڵ�λ��Ϊ" << mapName[position] << endl;
}


void Map::showRoom() {
	if (isThereChat())
		cout << "�����У�" << '\t' << npc.getName() << '\t';
}

void Map::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
			cout << "�ƶ�ʧ��" << endl;
	}
	case 'a': {
		if (position == 2 || position == 3) {
			dy--;
			position--;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	case 's': {
			cout << "�ƶ�ʧ��" << endl;
	}
	case 'd': {
		if (position == 1 || position == 2) {
			dy++;
			position++;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	default:
		break;
	}
	pos[dx][dy] = '*';
	npc = Npc(position);		//����npc
	showRoom();
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
