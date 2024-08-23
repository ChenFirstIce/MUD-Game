#pragma once
#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

class Game {
public:
	//构造函数未完成
	Game() = default;
	
	//更新玩家状态
	void Enter();
	void Leave();

	//打印玩家信息
	static string whoList();
	static string printHelp();
	string printStats();
	string printExperience();
	string printInventory();

	//与物品互动
	bool UseItem();
	bool RemoveItem();
	static void Logout(player p_player);

	//处理命令
	void Handle(string p_data);
protected:
	player& m_player;
	string m_lastcommand;
};