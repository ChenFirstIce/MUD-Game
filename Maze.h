#pragma once

class Maze {
public:
	Maze(Player* m_player) :m_player(m_player) {}
	void maze();
	void Set();
	void Welcome();
	void Hide();
private:
	Player* m_player;
};