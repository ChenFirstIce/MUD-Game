#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include "DatabasePointer.h"
#include "Attributes.h"
#include "Entity.h"
#include "Item.h"
using namespace std;

class NPC :public Entity {
public:
	NPC();
	void showNPC();

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
	string getType();
	void setType(string type);

	//是否被拯救
	bool& Stats() { return m_stats; }

	//装备加持
	void addDynamicBonuses(item p_item);//额外数值
	void addBonuses(item p_item);//基础数值

	//血量
	int& hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

	//重新计算属性值
	void recalculateStats();

	//攻击人数
	int getTarget(){return m_target;}
	
	//物品互动(这里的item全部都是数据库中的ID)
	void removeWeapon();
	void removeArmor();
	void useWeapon(int p_item);
	void useArmor(int p_item);
	void useHealing(int p_item);
	void useExp(int p_item);

	//返回武器,未写完
	item Weapon();
	item Armor();

	//输入输出重载
	friend ostream& operator <<(ostream& p_stream, NPC& p);
	friend istream& operator >>(istream& p_stream, NPC& p);

	
protected:
	//信息(姓名在Entity里)
	bool m_stats;

	//NPC属性
	int m_level;//等级
	int m_exp;//经验值（随等级重置）
	int m_hitpoints;//血量;
	int m_target;//增加可攻击敌人个数
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//基础属性值
	AttributeSet m_attributes;//总属性值

	//玩家装备仓
	int m_weapon;//武器的ID
	int m_armor;//武器的ID

	//房间
	/*int m_statpoints;*/
	int m_room;
};
