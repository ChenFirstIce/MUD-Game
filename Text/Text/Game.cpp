#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

//void Game::Enter(){
//	if (m_lastcommand == "new"||Player::Instance == nullptr) {
//		cout << "������������֣���Ĭ��Ϊ����ӥ����";
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
////���ɴ�������
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

        // ��������
        Command cmd = parser.parse(input);

        // ִ������
        executor.execute(cmd);
    }
}
