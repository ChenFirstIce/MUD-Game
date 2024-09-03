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
	Map(Player* m_player) :m_player(m_player) {}//��ʼλ��Ϊ��ͼ0
	~Map() {}
	void ShowMap1();			//��ʾ���ͼ
	void Move1(char order);
	void ShowMap2();			//��ʾ���ͼ
	void Move2(char order);
	void gotoc(); 
	void setPosition2();
	void setPosition1();
private:
	string name;
	int position; //��ǰλ��
	string mapName[11] = { "�ٳ�","��Ϣ��¥","��������","�����","УҽԺ","�ൺ��վ","��������","�̳�","���ȵ�","ľ��","�ɴ�"};
	char pos[3][3];
	int dx;
	int dy;
	Player* m_player;
};

#endif
