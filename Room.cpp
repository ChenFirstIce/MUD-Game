#include <bits/stdc++.h>
#include "Room.h"
#include "Matchentity.h"
using namespace std;

const int MAXITEMNUM = 32;

RoomType Room::getRoomType(string p_arr) {
	char chr = p_arr[0];

	switch (chr) {
	case 'N':
		return NOMAL;
		break;
	case 'S':
		return STORE;
		break;
	default:
		cout << "Error" << endl;
	}
}

////��ҵĽ������
//void Room::addPlayer(Player* p_player){
//	m_player = p_player;
//}
//
//void Room::removePlayer(Player* p_player){
//	m_player = nullptr;
//}

//��������Ľ�����˳�
void Room::addEnemy(enemy p_enemy){
	m_enemies.push_back(p_enemy);
}

void Room::removeEnemy(enemy p_enemy){
	m_enemies.erase(find(m_enemies.begin(), m_enemies.end(), (entityid)p_enemy));
}

void Room::addNPC(npc p_npc){
	m_npces.push_back(p_npc);
}

void Room::removeNPC(npc p_npc){
	m_npces.erase(find(m_npces.begin(), m_npces.end(), (entityid)p_npc));
}

//��Ʒ����
item Room::findItem(string& p_item) {
	list<item>::iterator itr = find_if(m_items.begin(), m_items.end(), matchEntityFull(p_item));

	if (itr != m_items.end()) {
		return *itr;
	}
	else {
		itr = find_if(m_items.begin(), m_items.end(), matchEntity(p_item));
		if (itr != m_items.end()) {
			return *itr;
		}
	}

	return 0;
}

void Room::addItem(item p_item){
	if (m_items.size() >= MAXITEMNUM)
		m_items.pop_front();

	m_items.push_back(p_item);
}

void Room::removeItem(item p_item){
	m_items.erase(find(m_items.begin(),m_items.end(),(entityid)p_item));
}

//���غͱ��淿��ģ��
void Room::loadTemplate(istream& p_stream){
	string temp;

	p_stream >> temp >> ws;    
	getline(p_stream, m_name);
	p_stream >> temp >> ws;    
	getline(p_stream, m_desc);
	p_stream >> temp >> temp;       
	m_type = getRoomType(temp);
	p_stream >> temp >> m_data;

	for (int d = 0; d < NUMDIRECTIONS; d++)
		p_stream >> temp >> m_rooms[d];

	p_stream >> temp >> m_enemy;
	p_stream >> temp >> m_maxenemies;
	//p_stream >> temp >> m_npc;

}

void Room::loadData(istream& p_stream){
	string temp;

	p_stream >> temp;

	m_items.clear();//������Ʒ
	entityid last;
	while (extract(p_stream, last) != 0)
		m_items.push_back(last);

	p_stream >> temp;

	m_npces.clear();//����NPC
	entityid lase;
	while (extract(p_stream, last) != 0)
		m_npces.push_back(last);

	p_stream >> temp;   
	p_stream >> m_money;

	p_stream >> temp;
	p_stream >> m_task;
}

void Room::saveData(ostream& p_stream){
	p_stream << "[ITEMS] ";//������Ʒ

	list<item>::iterator itr = m_items.begin();
	while (itr != m_items.end()){
		p_stream << *itr << " ";
		itr++;
	}

	p_stream << "0\n";

	p_stream << "[NPCES] ";//����NPC

	list<npc>::iterator itr = m_npces.begin();
	while (itr != m_items.end()){
		p_stream << *itr << " ";
		itr++;
	}

	p_stream << "0\n";

	p_stream << "[MONEY] " << m_money << "\n";

	p_stream << "[TASK]  " << m_task << "\n";
}

void chooseNPC(Player* m_player){
	f
}
