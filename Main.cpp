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
		//剧情
	}

	Player* m_player = Player::getPlayer();

	while (1) {
		system("cls");

		//打印个人信息
		//打印房间信息(判断是不是商店)

		cout << "> ";
		cin >> input;
		input = lowerCase(intput);

		if (input == "map") {
			//进入map改变player的room信息
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
			system("cls");
			//npc界面
			//选择npc
			//进入循环
				//输入（如果返回就跳出循环）
				//操作
		}
		else if (input == "bag") {
			//背包界面
			//选择背包
			//进入循环
				//输入（如果返回就跳出循环）
				//操作
		}
		else {
			//操作
		}
	}

	return 0;
}
