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
		input = lowerCase(intput);

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
		input = lowerCase(intput);

		if (input == "map") {
			system("cls");
			game.Map();
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
			cmd = commandpar.Parse(input);
			commandexec.Execute(cmd);
		}
	}
}

