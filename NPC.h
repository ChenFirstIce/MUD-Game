#pragma once 
#include <iostream>
#include <vector>
#include "Entity.h"
using namespace std;

class NPC :public Entity {
public:

	//void showNPC();未完成

	//等级&经验
	int getLevel() { return m_level; }
	void addExp(int exp);
	int needforLevel(int p_level);
	int needforNextLevel();

	//属性函数
	int getBaseAttr(int attr) { return m_baseattributes[attr]; }//获得某基础属性点数
	int getAttr(int p_attr);//获得总属性点数
	void setBaseAttr(int p_attr, int p_val);//重新设置某属性基础点数
	void addToBaseAttr(int p_attr, int p_val);//增加某属性基础点数

	//战斗属性
	int getType();
	void setType(int p_attr);

	//装备加持
	void addDynamicBonuses(item p_item);//额外数值
	void addBonuses(item p_item);//基础数值

	//血量
	int hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

	//重新计算属性值
	void recalculateStats();

	//物品函数
	item getItem(int p_index) { return m_inventory[p_index]; }
	int Items() { return m_items; }
	int MaxItems() { return PLAYERITEMS; }
	int getItemIndex(string& p_name);

	//攻击人数
	int getTarget(){return m_target;}

	//返回武器
	item Weapon();
	item Armor();

	//输入输出重载
	friend ostream& operator <<(ostream& p_stream, Player& p);
	friend istream& operator >>(istream& p_stream, Player& p);

	//玩家存读档
	void saveNPC();
	static void addNPC();
protected:
	//玩家属性
	int m_level;//等级
	int m_exp;//经验值（随等级重置）
	int m_hitpoints;//血量;
	int m_target;//增加可攻击敌人个数
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//基础属性值
	AttributeSet m_attributes;//总属性值

	//玩家装备仓
	item m_inventory[PLAYERITEMS];//item数据库指针数组
	int m_items;
	int m_weapon;//在数组中的索引
	int m_armor;

	//房间
	/*int m_statpoints;*/
	int m_room;
};