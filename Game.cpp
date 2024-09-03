#include <bits/stdc++.h>
#include <windows.h>
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
    char input;
    Story story(m_player);
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);
    Map map(m_player);

    map.gotoc();

    if (story.mapPoints() == 1) {
        map.ShowMap1();
        do {
            cout << "��������Ĳ���" << endl;
            cout << "> ";
            cin >> input;
        } while (map.Move1(input));
    }
    else if (story.mapPoints() == 2) {
        map.ShowMap1();
        do {
            cout << "��������Ĳ���" << endl;
            cout << "> ";
            cin >> input;
        } while (map.Move1(input));
    }

    story.Run();
}

void Game::Bag(){
    string input;
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    while (true) {
        system("cls");

        PrintInventory();

        cout << "������ָ����в���" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") {
            return;
        }

        commandexec.Execute(input);
    }
}

void Game::NPC() {
    string input;
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    npc ta;
    bool isRun = false;

    do {
        system("cls");

        commandexec.PrintMyNPC();

        cout << "��ѡ����Ҫ�����Ķ�����������Ӣ����or����cancel�˳���ǰ���棩" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") return;

        ta = commandexec.ChooseNPC(input);

        if (ta != 0) {
            isRun = true;
        }

    } while (!isRun);

    isRun = false;

    while(true) {
        system("cls");

        ta->showNPC();

        cout << "�������в���[use <>; remove <>; look]����������or����cancel�˳���ǰ���棩" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") return;

        cmd = commandpar.Parse(input);

        if (cmd.action == "use") {
            isRun = commandexec.UseItemToNPC(cmd,ta);
        }
        else if (cmd.action == "remove") {
            isRun = commandexec.RemoveItemFromNPC(cmd,ta);
        }
        else if (cmd.action == "look") {
            isRun = commandexec.ShowFace(ta);
            Sleep(5000);
            cout << "��Ҳ�����㣬" << endl;
            cout << "      ������Ļ֮����㣩" << endl;
            cout << "���ƿ���Ŀ�⡭��" << endl;
        }
        else {
            isRun = false;
        }

        if (!isRun) {
            cout << "�ⶼ��������������" << endl;
        }
    } 

}

void Game::PrintPrime(){
    Player* m_player = Player::getPlayer();
    Command cmd;
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);
    
    m_player->showPlayer();
    if (m_player->currentRoom()->Data() != 0) {
        CommandExesutor::StoreList(m_player->currentRoom()->Data());
    }
    else {
        commandexec.PrintRoom();
    }
}
