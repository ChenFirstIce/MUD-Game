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
        //进入战斗系统（要增加NPC到player）
        //判断是否进入下一阶段
        if (cnt < (m_player->Task())) {
            //开始下一段剧情
        }
    }
    else if (cmd.action == "map") {
        //进入地图界面
        //进入房间
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
