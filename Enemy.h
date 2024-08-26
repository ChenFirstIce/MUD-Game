#pragma once
#include "DatabasePointer.h"
#include "Room.h"
#include "Item.h"
using namespace std;

typedef pair<item, int> loot;        //int ��ʾ������Ʒ�ĸ���

//����ģ��
class EnemyTemplate :public Entity {
public:
	EnemyTemplate();
	friend istream& operator >>(istream& p_stream, EnemyTemplate& t);

	//ģ��״̬��
	int m_hitpoints;
	int m_dodging;
	int m_strikedamage;
	int m_exp;
	int m_weapon;
	money m_moneymin;
	money m_moneymax;

	//��Ʒ��
	list<loot> m_loot;
};


//ģ���ʵ�����������������Ƶĵ��˵���Ѫ�������ڷ����ǲ�һ����
class Enemy :public Entity {//������
public:
	Enemy();
	void LoadTemplate(enemytemplate p_template);
	
	//״̬���ʺ���(��������)
	string& Name() { return m_template->Name(); }
	int& HitPoints() { return m_hitpoints; }
	room& currentRoom() { return m_room; }
	int Dodging() { return m_template->m_dodging; }
	int StrikeDamage() { return m_template->m_strikedamage; }
	int Exp() { return m_template->m_exp; }
	item Weapon() { return m_template->m_weapon; }
	money MoneyMin() { return m_template->m_moneymin; }
	money MoneyMax() { return m_template->m_moneymax; }

	//��Ʒ����
	list<loot>& LootList() { return m_template->m_loot; }

	//�ļ�����
	friend ostream& operator<<(ostream& p_stream, Enemy& t);
	friend istream& operator>>(istream& p_stream, Enemy& t);
protected:
	enemytemplate m_template;
	int m_hitpoints;
	room m_room;          //�������ڷ����ָ��
};