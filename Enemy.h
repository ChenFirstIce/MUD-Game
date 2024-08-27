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
	int getType();
	void setType(int p_attr);
	friend istream& operator >>(istream& p_stream, EnemyTemplate& t);

	//ģ��״̬��
	int m_hitpoints;
	int m_dodging;
	int m_strikedamage;
	int m_speed;
	int m_exp;
	int m_weapon;
	AttackType m_type;//�������ӵ�
	money m_moneymin;
	money m_moneymax;

	//��Ʒ��
	list<loot> m_loot;
};


//ģ���ʵ�����������������Ƶĵ��˵���Ѫ�������ڷ����ǲ�һ����
//Enemy 
class Enemy :public Entity {//������
public:
	Enemy();
	void LoadTemplate(enemytemplate p_template);
	
	//��Ϣ
	string& Name() { return m_template->Name(); }

	//��ø������Ե���
	int& HitPoints() { return m_hitpoints; }
	int Dodging() { return m_template->m_dodging; }
	int StrikeDamage() { return m_template->m_strikedamage; }
	int Speed() { return m_template->m_speed; }
	
	
	//������
	item Weapon() { return m_template->m_weapon; }
	money MoneyMin() { return m_template->m_moneymin; }
	money MoneyMax() { return m_template->m_moneymax; }
	int Exp() { return m_template->m_exp; }

	//����
	room& currentRoom() { return m_room; }

	//���ս������
	int getType();
	void setType(int p_attr);

	//��Ʒ����
	list<loot>& LootList() { return m_template->m_loot; }

	//�ļ�����
	friend ostream& operator<<(ostream& p_stream, Enemy& t);
	friend istream& operator>>(istream& p_stream, Enemy& t);
protected:
	enemytemplate m_template;
	AttackType m_type;//�������ӵ�
	int m_hitpoints;
	room m_room;//�������ڷ����ָ��
};