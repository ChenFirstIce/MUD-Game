#pragma once
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Game {
public:
	//构造函数未完成
	Game() = default;

	//输入命令并对命令进行运行
	void handleCommand();
protected:
	player& m_player;
};