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

string lowerCase(string str) {// ȫ��תд��Сд��ĸ,��ʵ�β��ı�
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

	cout << "��ʼ����Ϸ" << endl;
	cout << "������Ϸ" << endl;
	cout << "�˳���Ϸ" << endl;
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
	//	//��������
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

