#pragma once
#include <vector>
using namespace std;

class Fight {
public:
	Fight(Player* m_player);//����
	
	//����˳��
	void Turn();

	//ǰ��
	int Front1();
	int Front2();

	//�Ƿ���
	bool isLive(int id);

	//ѡ�����
	int Choice(int Round, int atk);

	//���Կ���
	int Restrain1(int p_atk, int p_target);
	int Restrain2(int p_atk, int p_target);

	//����˺�
	void Atk1(int atk, int target);
	void Atk2(int atk, int target);

	//ѡ�񹥻�������ҩ
	void AttackTurn(int atk, int& Round);
	void UseMedical(int atk, int& Round);

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