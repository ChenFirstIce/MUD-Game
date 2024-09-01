#pragma once
#include"Player.h"
#include"Enemy.h"
#include<time.h>
#include<iostream>
#include<iomanip>
using namespace std;

class Fight {
public:
	Fight(Array myArray, Enemy* enemyElf);//传敌我布阵数据
	int ProceedFight(int m, int n, Item &m_item);//回合战斗
	void ShowBattle();//每回合展示双方阵容
	void Turn(int m, int n);//计算出手序
	void Atk1(Player &atk,Enemy &target);//进行攻击动作
	void Atk2(Enemy &atk,Player &target);
	void useHealing(int n);//使用药品
	int Restrain(Player& atk, Enemy& target);//判断克制关系
	
private:
	vector<shared_ptr<Player>> MyArray;//记录我方布阵
	Player Me[4] ;//记录战斗时我方阵容
	Enemy enemy[4];//记录战斗时敌方阵容
	int BattleTurn[8][2];//记录出手顺序
};
