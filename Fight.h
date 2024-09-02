#pragma once
#include <vector>
using namespace std;

class Fight {
public:
	Fight(Player* m_player);//入阵
	
	//出手顺序
	void Turn();

	//前排
	int Front1();
	int Front2();

	//是否存活
	bool isLive(int id);

	//选择界面
	int Choice(int Round, int atk);

	//属性克制
	int Restrain1(int p_atk, int p_target);
	int Restrain2(int p_atk, int p_target);

	//造成伤害
	void Atk1(int atk, int target);
	void Atk2(int atk, int target);

	//选择攻击或者用药
	void AttackTurn(int atk, int& Round);
	void UseMedical(int atk, int& Round);

	//判断战局
	bool isWin();
	bool isLose();

	//攻击轮数
	void ProceedFight();

	//结局战利品布置
	void addTrophy();
	void loseEXP();

	//重新设置
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