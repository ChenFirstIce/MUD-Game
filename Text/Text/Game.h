#pragma once
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Game {
public:
	//���캯��δ���
	Game() = default;

	//��������������������
	void handleCommand();
protected:
	player& m_player;
};