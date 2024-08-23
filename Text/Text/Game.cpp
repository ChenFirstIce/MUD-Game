#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

void Game::Enter(){
	if (m_lastcommand == "new"||Player::Instance == nullptr) {
		string m_name = "´ÆÓ¥"

		cout << "ÇëÊäÈëÄãµÄÃû×Ö£º£¨Ä¬ÈÏÎª¡°´ÆÓ¥¡±£©";
		cin >> m_name;

		m_player = Player::getNewPlayer(m_name);
	}
	else if (m_lastcommand == "continue") {
		m_player = Player::addPlayer();
	}
}

void Game::Leave(){
	Player::savePlayer();
}

void Game::Handle(string p_data){
	Player& p = *m_player;
	if (p_data == "/") {
		p_data = m_lastcommand;
	}
	else {
		m_lastcommand = p_data;
	}
	string firstword = 
}
