#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Entity.h"
#include "Player.h"
#include "DatabasePointer.h"
#include "Game.h"
#include "CommandExecutor.h"
#include "Fight.h"
using namespace std;

string lowerCase(string str) {// 全部转写成小写字母,但实参不改变
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

void ShowTitle() {
	cout << "\033[33m";
	cout << "              $$                    $$                     $$$                 $       $   " << endl;
	cout << "            $$$$$$$$$$$$$$$       $$$                      $$     $      $$    $$$$$$$$$$$     $$           $ " << endl;
	cout << "           $$  $$$$$$$$$$$$$     $$$         $      $$$$$$$$$$$$$$$$      $$   $$$$$$$$$$       $$  $$$$$$$$$$$" << endl;
	cout << "           $$ $ $   $    $       $$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$       $$  $$$$$$$$$$        $$ $$$$$$$$$$ " << endl;
	cout << "          $$  $$$$$$$$$$$$$     $$$$$$$$$$$$$$$           $$$$             $$  $$$$$$$$$$        $          $$" << endl;
	cout << "          $  $$$$$$$$$$$$$$     $$       $   $$          $$  $$$$              $$  $$  $$        $          $$" << endl;
	cout << "         $$$$$$ $$ $$ $$ $$    $$$$$$$$$$$$  $$        $$$     $$$         $   $$$$$$$$$$    $$$$$$  $      $$ " << endl;
	cout << "       $$$$$$  $$ $$ $$ $$   $$$$$$$$$$$$$  $$      $$$        $$  $   $$$$$$$$$$$$$$$$$    $$$$$$  $$$$$$$$$ " << endl;
	cout << "         $  $$  $$ $$$$$ $$  $$ $$   $$  $$  $$   $$$$$$$$$$$$$$$$$$$$  $$$$$ $$$$$$$$$$$$      $$   $$$$$$$$$ " << endl;
	cout << "           $$   $$ $$$$$ $$  $  $$$$$$$$$$$  $$    $$$$$$$$$$$$$$$$$$$     $$ $$$$$$$$$$$$      $$   $$     $$ " << endl;
	cout << "           $    $$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$   $$$$ $$      $$   $$        " << endl;
	cout << "         $$$$$$$$$ $$$$$ $$     $$   $$  $$  $$       $$$$$$$   $$         $$ $$   $$$$$$$      $$   $$        " << endl;
	cout << "         $$$$$  $$ $$$$$ $$     $$   $$  $$  $$       $$   $$   $$         $$ $$$$$$$$$$$$      $$   $$       $$" << endl;
	cout << "         $      $$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$ $    $$$$      $$ $$$$       $$" << endl;
	cout << "            $$$$$$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$      $$$$      $$$$ $$       $$ " << endl;
	cout << "        $$$$$$  $$$$$$$$$$$     $$       $$  $        $$   $$   $$        $$$ $$       $$$      $$$  $$       $$ " << endl;
	cout << "        $$     $$$$$$$$$$$     $           $$                  $$       $$  $$           $$   $$$   $$$$$$$$$$$  " << endl;
	cout << "                $$       $$              $$$$$               $$$$$      $$   $$$$$$$$$$$$$$     $     $$$$$$$$$  " << endl;
	cout << "                $$       $$                $$                  $$$              $$$$$$$$$$                       " << endl;
	cout << "\033[0m";

	cout << "开始新游戏" << endl;
	cout << "继续游戏" << endl;
	cout << "退出游戏" << endl;
}

int main() {
	Game game;
	CommandParser commandpar;
	CommandExecutor commandexec;
	string input;
	bool isStart = false;

	do {
		system("cls");

		ShowTitle();

		cout << "> ";
		cin >> input;
		input = lowerCase(input);

		isStart = game.First(input);
	} while (!isStart);

	//if (input == "new") {
	//	//背景剧情
	//}

	Player* m_player = Player::getPlayer();

	while (1) {
		system("cls");

		game.PrintPrime();

		cout << "> ";
		cin >> input;
		input = lowerCase(input);

		if (input == "map") {
			system("cls");
			game.Mape();
			continue;
		}
		else if (input == "attack") {
			Fight fight(m_player);
			fight.ProceedFight();
			continue;
		}
		else if (input == "npc") {
			game.NPC();
			continue;
		}
		else if (input == "bag") {
			game.Bag();
			continue;
		}
		else {
			Command cmd = commandpar.Parse(input);
			commandexec.Execute(cmd);
		}
	}
}

