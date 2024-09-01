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

//分界面
bool Game::First(string input) {
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    cmd = commandpar.Parse(input);

    if (cmd.action == "new") {
        RoomDatabase::LoadData("iRoomthings.txt");//最初的房间物品
        commandexec.New();
        return true;
    }
    else if (cmd.action == "continue") {
        RoomDatabase::LoadData("Roomthings.txt");//上一次保存的房间物品
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
        //打印房间信息
    }
    else {
        //打印商店信息
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
//        //地图系统
//        //获得房间号，打印房间
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
//        //攻击系统
//        if (cnt != m_player->Task()) {
//            //推动剧情
//            //判断是否使火车篇
//            //加入迷宫游戏
//        }
//    }
//    else if (cmd.action == "npc") {
//        //npc界面
//        
//    }
//    else {
//        commandexec.Execute(cmd);
//    }
//}

