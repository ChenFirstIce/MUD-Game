#pragma once
#include <bits/stdc++.h>
#include "Player.h"
#include "Item.h"
using namespace std;

const int NUMDIRECTIONS = 4;

class Room :public Entity {
public:
	//������Ϣ
	RoomType& Type() { return m_type; }
	int& Data() { return m_data; }
	string& Description() { return m_desc; }//���
	entityid& Adjacent(int p_dir) { return m_rooms[p_dir]; }
	void getRoomType(string p_arr);

	//����
	enemytemplates& spawnWhichEnemy() { return m_enemy; }
	int& maxEnemies() { return m_maxenemies; }
	list<enemy>& Enemies() { return m_enemies; }

	//npc
	npctemplates& spawnWhichNpc() { return m_npc; }
	list<npc>& Npces() { return m_npces; }
	
	//��Ʒ��Ϣ
	list<item>& Item() { return m_items; }
	money& Money() { return m_money; }

	//��ҽ�����˳�

	//��Ʒ����
	item findItem(string& p_item);
	void addItem(item p_item);
	void removeItem(item p_item);

	//�ļ�����
	void loadTemplate(istream& p_stream);
	void loadData(istream& p_stream);
	void saveData(ostream& p_stream);

	
private:
	//������Ϣ
	RoomType m_type;
	int m_data;//�̵��ID
	string m_desc;//��������
	entityid m_rooms[NUMDIRECTIONS];
	
	//������Ϣ
	list<enemy> m_enemies;
	enemytemplate m_enemy;//�����ĸ�����
	int m_maxenemies;//��������

	//npc��Ϣ
	list<npc> m_npces;
	npctemplate m_npc;//�����ĸ�npc

	//��Ʒ��Ϣ
	list<item> m_items;
	money m_money;

	//�����Ϣ
	Player& player;
};