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
	Map();//��ʼλ��Ϊ��ͼ0
	Map(int pos); //�ɲ���posΪ����λ��
	~Map();
	void ShowMap1();			//��ʾ���ͼ
	//void showRoom();		//��ʾ���ĵط�����Ϣ
	void Move1(char order);
	int getPosition1();
	void setPosition1(int p);
	void ShowMap2();			//��ʾ���ͼ
	//void showRoom();		//��ʾ���ĵط�����Ϣ
	void Move2(char order);
	int getPosition2();
	void setPosition2(int p);
	void ShowPosition(int p);
private:
	string name;
	int position=1; //��ǰλ��
	string mapName1[6] = { "�ٳ�","��Ϣ��¥","��������","�����","УҽԺ","�ൺ��վ"};
	string mapName2[3] = { "��������","�̵�","���ȹ�"};
	char pos[3][3];
	int dx;
	int dy;
};

#endif