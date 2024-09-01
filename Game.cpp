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

void Game::Save() {
    PlayerDatabase::Save();
    RoomDatabase::SaveData();
    EnemyDatabase::Save();
    Player::savePlayer();
}

//�ֽ���
bool Game::First(string input) {
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    cmd = commandpar.Parse(input);

    if (cmd.action == "new") {
        RoomDatabase::LoadData("iRoomthings.txt");//����ķ�����Ʒ
        commandexec.New();
        return true;
    }
    else if (cmd.action == "continue") {
        RoomDatabase::LoadData("Roomthings.txt");//��һ�α���ķ�����Ʒ
        return (commandexec.Continue());
    }

    return false;
}

bool Game::Map() {
    string input;
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    cout << "> ";
    cin >> input;

    cmd = commandpar.Parse(input);

    if (m_player->currentRoom()->Data() == 0) {
        //��ӡ������Ϣ
    }
    else {
        //��ӡ�̵���Ϣ
    }

    return (commandexec.Excute(cmd));
}

bool Game::Print(){
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);
    
}


//void Game::Run() {
//    string input;
//    Player* m_player = Player::getPlayer();
//    Command cmd;
//    CommandParser commandpar;
//    CommandExecutor commandexec(m_player);
//
//    cout << "> ";
//    cin >> input;
//
//    cmd = commandpar.Parse(input);
//
//    bool isRun = false;
//
//    if (cmd.action == "map") {
//        //��ͼϵͳ
//        //��÷���ţ���ӡ����
//        do {
//            system("cls");
//
//            if (m_player->currentRoom()->Data() == 0) {
//                commandexec.PrintRoom();
//            }
//            else {
//                commandexec.StoreList(m_player->currentRoom());
//            }
//
//            isRun = commandexec.Execute(cmd);
//        } while (!isRun)
//    }
//    else if (cmd.action == "attack") {
//        int cnt = m_player->Task();
//        //����ϵͳ
//        if (cnt != m_player->Task()) {
//            //�ƶ�����
//            //�ж��Ƿ�ʹ��ƪ
//            //�����Թ���Ϸ
//        }
//    }
//    else if (cmd.action == "npc") {
//        //npc����
//        
//    }
//    else {
//        commandexec.Execute(cmd);
//    }
//}

