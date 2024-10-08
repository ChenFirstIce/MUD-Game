#pragma once
#include <bits/stdc++.h>
#include "DatabasePointer.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
using namespace std;

const int NUMDIRECTIONS = 4;

class Room :public Entity {
public:
	//房间信息
	RoomType& Type() { return m_type; }
	int& Data() { return m_data; }
	string& Description() { return m_desc; }//会变
	entityid& Adjacent(int p_dir) { return m_rooms[p_dir]; }
	RoomType getRoomType(string p_arr);

	//敌人
	enemytemplate& spawnWhichEnemy() { return m_enemy; }
	int& maxEnemies() { return m_maxenemies; }
	list<enemy>& Enemies() { return m_enemies; }

	//npc
	//npctemplate& spawnWhichNpc() { return m_npc; }
	//list<npc>& Npces() { return m_npces; }
	
	//物品信息
	list<item>& Item() { return m_items; }
	money& Money() { return m_money; }

	//玩家进入和退出
	void addPlayer(Player* p_player);
	void removePlayer(Player* p_player);

	//其他人物进入和退出
	void addEnemy(enemy p_enemy);
	void removeEnemy(enemy p_enemy);

	//物品函数
	item findItem(string& p_item);
	void addItem(item p_item);
	void removeItem(item p_item);

	//文件函数
	void loadTemplate(istream& p_stream);
	void loadData(istream& p_stream);
	void saveData(ostream& p_stream);

	
private:
	//房间信息
	RoomType m_type;
	int m_data;//商店的ID
	string m_desc;//房间描述
	entityid m_rooms[NUMDIRECTIONS];
	
	//敌人信息
	list<enemy> m_enemies;
	enemytemplate m_enemy;//产生哪个敌人
	int m_maxenemies;//最大敌人数

	//npc信息
	//list<npc> m_npces;
	//npctemplate m_npc;//产生哪个npc

	//物品信息
	list<item> m_items;
	money m_money;

	//玩家信息
	Player* m_player;
};