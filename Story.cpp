#include <bits/stdc++.h>
#include "Maze.h"
#include "Story.h"
#include "Fight.h"
using namespace std;

void Story::showStory(int id){
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

void Story::Run(){
	int id = m_player->currentRoom();
	room m_room = m_player->currentRoom();
	Fight fight(m_player);

	if (m_room->Task()) {
		if (id == 6) {
			//�ൺ����վ
			showStory(6);//����+�Թ�
			m_room->Task() = false;//����
			m_player->addNPC();

			//ľ��
			showStory(10);//ľ�ݾ���
			fight.ProceedFight();

			m_player->currentRoom() = 7;

			map_points = 2;
		}
		else {
			showStory(id);
			m_room->Task() = false;
		}
	}
	else if (!static_cast<room>(2)->Task() && !static_cast<room>(4)->Task() && !static_cast<room>(5)->Task()) {
		showStory(3);
	}
}
