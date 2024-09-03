#pragma once
#include <bits/stdc++.h>
#include "DatabasePointer.h"
#include "Item.h"
#include "Attributes.h"
#include "NPC.h"
using namespace std;
//未完成

const int PLAYERITEMS = 30;
const int NPCNUM = 4;

class Player{
public:
	//构造函数
	static void creatPlayer(string p_name = "雌鹰", int type = 1);//
	static void deletePlayer();
	static Player* getPlayer();
	~Player() = default;

	//信息
	string& Name() { return name; }
	void showPlayer();
	int& Task() { return m_task; }//改变剧情节点
	money& Money() { return m_money; }
	int& Exp() { return m_exp; }
	int& Stats() { return m_statpoints; }

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

	//装备加持
	void addDynamicBonuses(item p_item);//可变数值（比如武器装备和卸下）
	void addBonuses(item p_item);//永久数值（增加就不会改变）

	//血量
	double& HitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

    //重新计算属性值
	void recalculateStats();
	
	//物品函数
	item getItem(int p_index) { return m_inventory[p_index]; }//p_index使item在背包中的索引
	int Items() { return m_items; }
	int MaxItems() { return PLAYERITEMS; }
	int getItemIndex(string& p_name);//查找背包中的物品并返回物品在背包中的ID

	//返回武器
	item Weapon();
	item Armor();

	//修改装备仓
	bool pickItem(item p_item);
	bool dropItem(int p_index);

	//寻找NPC和增加NPC
	list<npc>& Npces() { return m_npces; }
	npc findNPC(string& p_npc);
	void addNPC();

	//物品互动(p_index全部是背包中的索引)
	void removeWeapon();
	void removeArmor();
	void useWeapon(int p_index);
	void useArmor(int p_index);
	void useHealing(int p_index);
	void useExp(int p_index);

	//房间函数
	room& currentRoom() { return m_room; }

	//输入输出重载
	friend ostream& operator <<(ostream& p_stream, Player& p);
	friend istream& operator >>(istream& p_stream, Player& p);

	//玩家存读档
	static void savePlayer();
	static Player* addPlayer();

	//
	static Player& get(int m_id);
private:
	//构造函数（单例模式）
	Player(string p_name = "雌鹰", AttackType p_type = LIGHT);//未完成

	//玩家信息
	static Player* Instance;
	string name;
	entityid id = 0;

	//玩家属性
	int m_level;//等级
	int m_exp;//经验值（随等级重置）
	money m_money;//金钱
	double m_hitpoints;//血量;
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//基础属性值
	AttributeSet m_attributes;//额外属性值

	//玩家装备仓
	item m_inventory[PLAYERITEMS];//item数据库指针数组
	int m_items;
	int m_weapon;//在数组中的索引
	int m_armor;//在数组中的索引

	//男主们
	int m_task;//新增加剧情结点
	list<npc> m_npces;

	//房间
	int m_statpoints;
	int m_room;//房间的ID
};