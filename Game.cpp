#include "stdc++.h"
#include <windows.h>
#include "Game.h"
using namespace std;

void Game::Load(){
    ItemDatabase::Load();
    RoomDatabase::LoadTemplates();
    RoomDatabase::LoadData();
    StoreDatabase::Load();
    EnemyTemplateDatabase::Load();
    EnemyDatabase::Load();
    NPCDatabase::Load();
}

void Game::Save() {
    RoomDatabase::SaveData();
    EnemyDatabase::Save();
    NPCDatabase::Save();
    Player::savePlayer();
}

//分界面
bool Game::First(string input) {
    Player* m_player = Player::getPlayer();
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    Command cmd = commandpar.Parse(input);

    if (cmd.action == "new") {
        RoomDatabase::LoadData("iRoomthings.txt");//最初的房间物品
        commandexec.New();
        return true;
    }
    else if (cmd.action == "continue") {
        RoomDatabase::LoadData("Roomthings.txt");//上一次保存的房间物品
        return (commandexec.Continue());
    }
    else if (cmd.action == "quit") {
        exit(0);
    }

    return false;
}

void Game::Mape() {
    char input;
    Player* m_player = Player::getPlayer();
    Story story(m_player);
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);
    Map mape(m_player);

    mape.gotoc();

    if (story.mapPoints() == 1) {
        mape.setPosition1();
        do {
            mape.ShowMap1();
            cout << "请输入你的操作(w向上，a向左，s向下，d向右，1进入房间)" << endl;
            cout << "> ";
            cin >> input;
        } while (!mape.Move1(input));
    }
    else if (story.mapPoints() == 2) {
        mape.setPosition2();
        do {
            mape.ShowMap1();
            cout << "请输入你的操作" << endl;
            cout << "> ";
            cin >> input;
        } while (!mape.Move1(input));
    }

    story.Run();
}

void Game::Bag(){
    string input;
    Player* m_player = Player::getPlayer();
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    while (true) {
        system("cls");

        commandexec.PrintInventory();

        cout << "请输入指令进行操作" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") {
            return;
        }

        Command cmd = commandpar.Parse(input);
        commandexec.Execute(cmd);
    }
}

void Game::NPC() {
    string input;
    Player* m_player = Player::getPlayer();
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);

    npc ta;
    bool isRun = false;

    do {
        system("cls");

        commandexec.PrintMyNPC();

        cout << "请选择你要互动的对象（输入他的英文名or输入cancel退出当前界面）" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") return;

        ta = m_player->findNPC(input);

        if (ta != 0) {
            isRun = true;
        }

    } while (!isRun);

    isRun = false;

    while(true) {
        system("cls");

        ta->showNPC();

        cout << "对他进行操作[use <>; remove <>; look]（输入命令or输入cancel退出当前界面）" << endl;
        cout << "> ";
        cin >> input;

        if (input == "cancel") return;

        Command cmd = commandpar.Parse(input);

        if (cmd.action == "use") {
            isRun = commandexec.UseItemToNPC(cmd,ta);
        }
        else if (cmd.action == "remove") {
            isRun = commandexec.RemoveItemFromNPC(cmd,ta);
        }
        else if (cmd.action == "look") {
            isRun = commandexec.ShowFace(ta);
            Sleep(5000);
            cout << "他也看向你，" << endl;
            cout << "      （在屏幕之外的你）" << endl;
            cout << "你移开了目光……" << endl;
        }
        else {
            isRun = false;
        }

        if (!isRun) {
            cout << "这都能输错，重新输入吧" << endl;
        }
    } 

}

void Game::PrintPrime(){
    Player* m_player = Player::getPlayer();
    CommandParser commandpar;
    CommandExecutor commandexec(m_player);
    
    m_player->showPlayer();
    if (m_player->currentRoom()->Data() != 0) {
        CommandExecutor::StoreList(m_player->currentRoom()->Data());
    }
    else {
        commandexec.PrintRoom();
    }
}
