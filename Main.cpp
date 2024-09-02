#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Entity.h"
#include "Player.h"
#include "DatabasePointer.h"
#include "Game.h"
#include "CommandExecutor.h"
using namespace std;

int main() {
	Game game;
	CommandParser commandpar;
	CommandExecutor commandexec;
	string input;
	bool isStart = false;

	do {
		system("cls");

		//游戏开始界面
		cout << "> ";
		cin >> input;
		input = lowerCase(intput);

		isStart = game.First(input);
	} while (!isStart);

	if (input == "new") {
		//背景剧情
	}

	Player* m_player = Player::getPlayer();

	while (1) {
		system("cls");

		game.PrintPrime();

		cout << "> ";
		cin >> input;
		input = lowerCase(intput);

		if (input == "map") {
			system("cls");
			game.Map();
			continue;
		}
		else if (input == "attack") {
			int cnt = m_player;
			//进入战斗
			//改变room和player的npc，改变npc的状态
			if (cnt != m_player) {
				if (//目标房间){
					//迷宫
					//剧情
				}
				//改变房间
			}
		}
		else if (input == "npc") {
			game.NPC();
		}
		else if (input == "bag") {
		    game.Bag();
	    }
		else {
			//操作
		}
	}

	return 0;
}
