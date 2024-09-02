#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Entity.h"
#include "Player.h"
#include "DatabasePointer.h"
#include "Game.h"
#include "CommandExecutor.h"
#include "Fight.h"
using namespace std;

int main() {
	Game game;
	CommandParser commandpar;
	CommandExecutor commandexec;
	string input;
	bool isStart = false;

	do {
		system("cls");

		//��Ϸ��ʼ����
		cout << "> ";
		cin >> input;
		input = lowerCase(intput);

		isStart = game.First(input);
	} while (!isStart);

	if (input == "new") {
		//��������
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
			int cnt = m_player->Task();

			Fight fight(m_player);
			fight.ProceedFight();
			//�ı�room��player��npc���ı�npc��״̬
			if (cnt != m_player) {
				if (//Ŀ�귿��){
					//�Թ�
					//����
			}
			//�ı䷿��
		}
		else if (input == "npc") {
			game.NPC();
		}
		else if (input == "bag") {
			game.Bag();
		}
		else {
			cmd = commandpar.Parse(input);
			commandexec.Execute(cmd);
		}
	}
}

