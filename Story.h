#pragma once
#include "DatabasePointer.h"
using namespace std;

class Stroy {
public:
	Story(Player* m_player) :m_player(m_player) { map_points = 1; }
	int& mapPoints() { return map_points; }
	void showStory(int id);
	void Run();

private:
	Player* m_player;
	int map_points;
};