#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

//void Game::Enter(){
//	if (m_lastcommand == "new"||Player::Instance == nullptr) {
//		cout << "请输入你的名字：（默认为“雌鹰”）";
//		cin >> m_name;
//
//		m_player = Player::getNewPlayer(m_name);
//	}
//	else if (m_lastcommand == "continue") {
//		m_player = Player::addPlayer();
//	}
//}
//
//void Game::Leave(){
//	Player::savePlayer();
//}
//
////集成处理命令
//void Game::Handle() {
//	CommandParser parser;
//	CommandExecutor executor;
//
//	while (true) {
//		cout << "> ";
//		string input;
//		getline(cin, input);
//
//		Command cmd = parser.parse(input);
//		executor.execute(cmd);
//	}
//}

void Game::handleCommands() {
    CommandParser parser;
    CommandExecutor executor;

    while (true) {
        cout << "> ";
        string input;
        getline(cin, input);

        // 解析命令
        Command cmd = parser.parse(input);

        // 执行命令
        executor.execute(cmd);
    }
}
