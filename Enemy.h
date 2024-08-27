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
	int getType();
	void setType(int p_attr);
	friend istream& operator >>(istream& p_stream, EnemyTemplate& t);

	//模板状态栏
	int m_hitpoints;
	int m_dodging;
	int m_strikedamage;
	int m_speed;
	int m_exp;
	int m_weapon;
	AttackType m_type;//后来增加的
	money m_moneymin;
	money m_moneymax;

	//物品栏
	list<loot> m_loot;
};


//模板的实例化，可以制造相似的敌人但是血量和所在房间是不一样的
//Enemy 
class Enemy :public Entity {//代理类
public:
	Enemy();
	void LoadTemplate(enemytemplate p_template);
	
	//信息
	string& Name() { return m_template->Name(); }

	//获得各个属性点数
	int& HitPoints() { return m_hitpoints; }
	int Dodging() { return m_template->m_dodging; }
	int StrikeDamage() { return m_template->m_strikedamage; }
	int Speed() { return m_template->m_speed; }
	
	
	//掉落物
	item Weapon() { return m_template->m_weapon; }
	money MoneyMin() { return m_template->m_moneymin; }
	money MoneyMax() { return m_template->m_moneymax; }
	int Exp() { return m_template->m_exp; }

	//房间
	room& currentRoom() { return m_room; }

	//获得战斗属性
	int getType();
	void setType(int p_attr);

	//物品函数
	list<loot>& LootList() { return m_template->m_loot; }

	//文件函数
	friend ostream& operator<<(ostream& p_stream, Enemy& t);
	friend istream& operator>>(istream& p_stream, Enemy& t);
protected:
	enemytemplate m_template;
	AttackType m_type;//后来增加的
	int m_hitpoints;
	room m_room;//敌人所在房间的指针
};