#pragma once
#include"Player.h"
#include"Enemy.h"
#include<time.h>
#include<iostream>
#include<iomanip>
using namespace std;

class Fight {
public:
	Fight(Array myArray, Enemy* enemyElf);//�����Ҳ�������
	int ProceedFight(int m, int n, Item &m_item);//�غ�ս��
	void ShowBattle();//ÿ�غ�չʾ˫������
	void Turn(int m, int n);//���������
	void Atk1(Player &atk,Enemy &target);//���й�������
	void Atk2(Enemy &atk,Player &target);
	void useHealing(int n);//ʹ��ҩƷ
	int Restrain(Player& atk, Enemy& target);//�жϿ��ƹ�ϵ
	
private:
	vector<shared_ptr<Player>> MyArray;//��¼�ҷ�����
	Player Me[4] ;//��¼ս��ʱ�ҷ�����
	Enemy enemy[4];//��¼ս��ʱ�з�����
	int BattleTurn[8][2];//��¼����˳��
};
