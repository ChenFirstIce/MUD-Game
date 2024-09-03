#pragma once
#include <bits/stdc++.h>
#include "DatabasePointer.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
using namespace std;

const int NUMDIRECTIONS = 4;

class Room:public Entity {
public:
	//������Ϣ
	RoomType& Type() { return m_type; }
	int& Data() { return m_data; }//�ж��ǲ����̵�
	string& Description() { return m_desc; }//���
	entityid& Adjacent(int p_dir) { return m_rooms[p_dir]; }
	RoomType getRoomType(string p_arr);
	bool& Task(){ return m_task; }

		//����
	enemytemplate& spawnWhichEnemy() { return m_enemy; }
	int& maxEnemies() { return m_maxenemies; }
	list<enemy>& Enemies() { return m_enemies; }

	//npc
	list<npc>& Npces() { return m_npces; }

	//��Ʒ��Ϣ
	list<item>& Item() { return m_items; }
	money& Money() { return m_money; }

	//�������������˳�
	void addEnemy(enemy p_enemy);
	void removeEnemy(enemy p_enemy);
	void addNPC(npc p_npc);
	void removeNPC(npc p_npc);

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

	//��Ʒ��Ϣ
	list<item> m_items;
	money m_money;

	//����
	bool m_task;//�о�����true
};