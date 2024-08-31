#include <sstream>
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

	//游戏开始界面
	while (1) {
		string input;
		cout << ">  ";
		getline(cin, input);

		Command
	}

	return 0;
}
