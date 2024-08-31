#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

void Game::Load(){
    ItemDatabase::Load();
    PlayerDatabase::Load();
    RoomDatabase::LoadTemplates();
    RoomDatabase::LoadData();
    StoreDatabase::Load();
    EnemyTemplateDatabase::Load();
    EnemyDatabase::Load();
    NPCDatabase::Load();
}

void Game::Run(){
    string input;
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec;
    
    cout << "> ";
    cin >> input;

    cmd = commandpar.Parse(input);

    if (cmd.action == "attack") {
        Player* m_player = Player::getPlayer();
        int cnt = m_player->Task();
        //����ս��ϵͳ��Ҫ����NPC��player��
        //�ж��Ƿ������һ�׶�
        if (cnt < (m_player->Task())) {
            //��ʼ��һ�ξ���
        }
    }
    else if (cmd.action == "map") {
        //�����ͼ����
        //���뷿��
    }
    else {
        commandexec.Execute(cmd);
    }
}

void Game::Save(){
    PlayerDatabase::Save();
    RoomDatabase::SaveData();
    EnemyDatabase::Save();
    Player::savePlayer();
}
