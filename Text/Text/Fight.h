#pragma once
#include <vector>
using namespace std;

class Fight {
public:
	Fight();
	int proceedFight(int);
	void showBattel();
	void Turn();//¼ÆËã³öÊÖÐò
	void Attack();//¹¥»÷
	int Restrain();//
private:
	Player* player;
	vector<NPC> Me;
	vector<enemy> Enemy;
};