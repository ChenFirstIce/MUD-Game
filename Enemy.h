#pragma once
#include "DatabasePointer.h"
#include "Room.h"
#include "Item.h"
using namespace std;

typedef pair<item, int> loot;        //int 表示留下物品的概率

//敌人模板
class EnemyTemplate :public Entity {
public:
	EnemyTemplate();
	friend istream& operator >>(istream& p_stream, EnemyTemplate& t);

	//模板状态栏
	int m_hitpoints;
	int m_dodging;
	int m_strikedamage;
	int m_exp;
	int m_weapon;
	money m_moneymin;
	money m_moneymax;

	//物品栏
	list<loot> m_loot;
};


//模板的实例化，可以制造相似的敌人但是血量和所在房间是不一样的
class Enemy :public Entity {//代理类
public:
	Enemy();
	void LoadTemplate(enemytemplate p_template);
	
	//状态访问函数(各种属性)
	string& Name() { return m_template->Name(); }
	int& HitPoints() { return m_hitpoints; }
	room& currentRoom() { return m_room; }
	int Dodging() { return m_template->m_dodging; }
	int StrikeDamage() { return m_template->m_strikedamage; }
	int Exp() { return m_template->m_exp; }
	item Weapon() { return m_template->m_weapon; }
	money MoneyMin() { return m_template->m_moneymin; }
	money MoneyMax() { return m_template->m_moneymax; }

	//物品函数
	list<loot>& LootList() { return m_template->m_loot; }

	//文件函数
	friend ostream& operator<<(ostream& p_stream, Enemy& t);
	friend istream& operator>>(istream& p_stream, Enemy& t);
protected:
	enemytemplate m_template;
	int m_hitpoints;
	room m_room;          //敌人所在房间的指针
};