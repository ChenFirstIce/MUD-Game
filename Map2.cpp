#include <iostream>
#include "Map.h"
#include "tool.h"


using namespace std;

void Map::setPosition2() {//±àºÅ
	position = m_player->currentRoom();
	int p = m_player->currentRoom();

	if (p == 7) {
		dx = 0;
		dy = 0;
	}
	if (p == 8) {
		dx = 0;
		dy = 1;
	}
	if (p == 9) {
		dx = 0;
		dy = 2;
	}

	for (int i = 0; i < 3; i++)
	{
		pos[0][i] = ' ';
	}
	pos[dx][dy] = '*';
}

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
		return false;
	}
	case 'a': {
		if (position == 8 || position == 9) {
			dy--;
			position--;
		}
		else
		{
			cout << "ÒÆ¶¯Ê§°Ü" << endl;
			return false;
		}
		break;
	}
	case 's': {
		cout << "ÒÆ¶¯Ê§°Ü" << endl;
		return false;
	}
	case 'd': {
		if (position == 7 || position == 8) {
			dy++;
			position++;
		}
		else
		{
			cout << "ÒÆ¶¯Ê§°Ü" << endl;
			return false;
		}
		
	}
	default:
		return false;
	}
	for (int i = 0; i < 3; i++)
	{
		pos[0][i] = ' ';
	}
	pos[dx][dy] = '*';
	m_player->currentRoom() = position;

	return true;
}

void Map::gotoc() {
	system("cls");
	gotoXY(55, 10);
	cout << "µØ Í¼";
	gotoXY(56, 20);
	cout << "¼ÓÔØÖÐ...";
	for (int j = 0; j < 100; j++) {
		Sleep(17);
		gotoXY(j + 3, 15);
		cout << " " << j << "%";
		cout << "¡ö";
	}
	system("cls");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 40; j++) {
			gotoXY(i, j);
			cout << "¡ö";
			//SetColor(rand()%10);
		}
	}
	system("cls");
}

