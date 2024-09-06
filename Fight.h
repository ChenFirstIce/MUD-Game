#pragma once
#include <vector>
#include "DatabasePointer.h"
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
using namespace std;

class Fight {
public:
	Fight(Player* m_player);//����
	
	//����˳��
	void BattleTurn();

	//ǰ��
	int Front1();
	int Front2();

	//�Ƿ���
	bool isLive(int id);

	//ѡ�����
	void ShowEnemy1();
	void ShowEnemy2();
	void ShowEnemy3();
	void ShowEnemy4();
	void ShowMe1();
	void ShowMe2();
	void ShowMe3();
	void ShowMe4();
	void ShowBattle();
	int Choice(int& Round, int atk);

	//���Կ���
	int Restrain1(int p_atk, int p_target);
	int Restrain2(int p_atk, int p_target);

	//����˺�
	void Atk1(int atk, int target);
	void Atk2(int atk, int target);

	//ѡ�񹥻�������ҩ
	bool AttackTurn(int atk);
	bool UseMedical(int atk);

	//�ж�ս��
	bool isWin();
	bool isLose();

	//��������
	void ProceedFight();

	//���ս��Ʒ����
	void addTrophy();
	void loseEXP();

	//��������
	void Resite();
private:
	Player* m_player;
	vector<int> Me;
	vector<int> Enemy;
	list<int> Turn;
	vector<int> targets;
	int endie = 0;
	int medie = 0;
	room m_room;
};