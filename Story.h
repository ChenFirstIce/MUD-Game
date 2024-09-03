#pragma once
#include "DatabasePointer.h"
#include "Player.h"
#include "Room.h"
using namespace std;

class Story {
public:
	Story(Player* m_player) :m_player(m_player) { map_points = 1; }
	int& mapPoints() { return map_points; }
	void showStory(int id);
	void Run();

private:
	Player* m_player;
	int map_points;
};