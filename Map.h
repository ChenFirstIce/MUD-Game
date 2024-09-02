#pragma once
#ifndef MAP_H
#define MAP_H
#include <string>
#include<iostream>
#include <windows.h>
#include <iomanip>
#include"Player.h"
using namespace std;

class Map
{
public:
	Map(Player* m_player) :m_player(m_player) {}//初始位置为地图0
	~Map() {}
	void ShowMap1();			//显示大地图
	void Move1(char order);
	void ShowMap2();			//显示大地图
	void Move2(char order);
	void gotoc()
	void setPosition2(int p);
private:
	string name;
	int position; //当前位置
	string mapName1[6] = { "操场","信息南楼","望海餐厅","警察局","校医院","青岛北站" };
	string mapName2[3] = { "废弃工厂","商店","咖啡馆" };
	char pos[3][3];
	int dx;
	int dy;
	Player* m_player;
};

#endif