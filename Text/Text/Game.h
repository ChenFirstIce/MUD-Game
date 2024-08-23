#pragma once
#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

class Game {
public:
	//���캯��δ���
	Game() = default;
	
	//�������״̬
	void Enter();
	void Leave();

	//��ӡ�����Ϣ
	static string whoList();
	static string printHelp();
	string printStats();
	string printExperience();
	string printInventory();

	//����Ʒ����
	bool UseItem();
	bool RemoveItem();
	static void Logout(player p_player);

	//��������
	void Handle(string p_data);
protected:
	player& m_player;
	string m_lastcommand;
};