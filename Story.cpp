#include <bits/stdc++.h>
#include "Maze.h"
#include "Story.h"
using namespace std;

void Stroy::showStory(int id){
	if (id == 1) {
		
	}
	else if (id == 2) {

	}
	else if (id == 3) {

	}
	else if (id == 4) {

	}
	else if (id == 5) {

	}
	else if (id == 6) {//�м��һ���Թ�
		//
		Maze maz(m_player);
		//
	}
	else if (id == 7) {

	}
	else if (id == 8) {

	}
	else if (id == 9) {

	}
	else if (id == 10) {

	}
}

void Stroy::Run(){
	int id = m_player->currentRoom();
	room m_room = m_player->currentRoom();
	Fight fight(m_player);

	if (m_room->Task()) {
		if (id == 6) {
			//�ൺ����վ
			showStroy(6);//����+�Թ�
			m_room->Task() = false;
			m_player->addNPC();

			//ľ��
			showStory(10);//ľ�ݾ���
			fight.ProceedFight();

			m_Player->currentRoom() = 7;

			map_points = 2;
		}
		else {
			showStroy(id);
			m_room->Task() = false;
		}
	}
}
