#pragma once
#include <vector>
using namespace std;

class Fight {
public:
	Fight();
	int proceedFight(int);
	void showBattel();
	void Turn();//���������
	void Attack();//����
	int Restrain();//
private:
	Player* player;
	vector<NPC> Me;
	vector<enemy> Enemy;
};