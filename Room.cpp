#include "bits/stdc++.h"
#include "Room.h"
#include "Matchentity.h"
#include "func.h"
using namespace std;

extern string UTF8ToGB(const char* str);

const int MAXITEMNUM = 32;

RoomType Room::getRoomType(string p_arr) {
	char chr = p_arr[0];

	switch (chr) {
	case 'N':
		return NORMAL;
		break;
	case 'S':
		return STORE;
		break;
	default:
		cout << "Error" << endl;
	}
}

////玩家的进入进出
//void Room::addPlayer(Player* p_player){
//	m_player = p_player;
//}
//
//void Room::removePlayer(Player* p_player){
//	m_player = nullptr;
//}

//其他人物的进入和退出
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

//物品函数
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

//加载和保存房间模板
void Room::loadTemplate(istream& p_stream){
	string temp;

	p_stream >> temp >> ws;    
	getline(p_stream, m_name);
	m_name = UTF8ToGB(m_name.c_str()).c_str();
	cout << m_name;
	p_stream >> temp >> ws;    
	getline(p_stream, m_desc);
	p_stream >> temp >> temp;       
	m_type = getRoomType(temp);
	p_stream >> temp >> m_data;

	p_stream >> temp;
	for (int d = 0; d < NUMDIRECTIONS; d++)
		p_stream >> m_rooms[d];

	p_stream >> temp;

	entityid last;
	while (extract(p_stream, last) != 0) {
		m_enemies.push_back(last);
		cout << last;
	}

	p_stream >> temp >> m_maxenemies;
}

void Room::loadData(istream& p_stream){
	string temp;
	int task;

	p_stream >> temp;

	m_items.clear();//房间物品
	entityid last;
	while (extract(p_stream, last) != 0) {
		m_items.push_back(last);
		cout << last;
	}

	p_stream >> temp;

	m_enemies.clear();//房间NPC
	while (extract(p_stream, last) != 0)
		m_enemies.push_back(last);

	p_stream >> temp >> ws;
	p_stream >> m_money;

	p_stream >> temp;
	p_stream >> task;
	if (task == 1) {
		m_task = true;
	}
	else if(task ==0) {
		m_task = false;
	}
	cout << m_task;
}

void Room::saveData(ostream& p_stream){
	p_stream << "[ITEMS] ";//房间物品

	list<item>::iterator itr1 = m_items.begin();
	while (itr1 != m_items.end()){
		p_stream << *itr1 << " ";
		itr1++;
	}

	p_stream << "0\n";

	p_stream << "[ENEMY] ";//房间敌人

	list<enemy>::iterator itr2 = m_enemies.begin();
	while (itr2 != m_enemies.end()){
		p_stream << *itr2 << " ";
		itr2++;
	}

	p_stream << "0\n";

	p_stream << "[MONEY] " << m_money << "\n";

	p_stream << "[TASK]  " << m_task << "\n";
}
