#include "CommandExecutor.h"
#include <iostream>
using namespace std;

void CommandExecutor::Execute(Player& player, const Command& cmd) {
    if (cmd.action == "move") {
        handleMove(player, cmd);
    }
    else if (cmd.action == "attack") {
        handleAttack(player, cmd);
    }
    else if (cmd.action == "pickup") {
        handlePickup(player, cmd);
    }
    else {
        cout << "啥？" << endl;
    }
}

void CommandExecutor::New(const Command& cmd){
    string name;
    int type;

    if (cmd.args.empty()) {
        if (Player::getPlayer() != nullptr) {
            Player::deletePlayer();
        }

        cout << "你的名字是？（例如：雌鹰）" << endl;
        cout << ">";
        cin >> name;

        cout << "你的攻击类型是？（输入1，则攻击类型为光）" << endl;
        cout << ">";
        cin >> type;

        //增加元素选择
        m_player = Player::creatPlayer(name,type);
    }
    else {
        cout << "啥？" << endl;
    }
}

void CommandExecutor::Continue(Player& player, const Command& cmd){
    
}

void CommandExecutor::handlePick(Player& player, const Command& cmd) {
    if (!cmd.args.empty()) {
        string target = cmd.args;
        cout << "pick " << target << endl;
    }
    else {
        cout << "啥？" << endl;
    }
}

//物品
bool CommandExecutor::UseItem(const string& p_item){
    int i = m_player.getItemIndex(p_item);

    if (i == -1)
    {
        cout << "找不到该物品。" << endl;
        return false;
    }

    Item& itm = *p_player.getItem(i);


    switch (itm.Type())
    {
    case WEAPON:
        m_player.useWeapon(i);
        cout << "装备上" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player.useArmor(i);
        cout << "穿上" << itm.Name() < endl;

        return true;

    case HEALING:
        m_player.addBonuses(itm.ID());
        m_player.dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    }

    return false;
}

//物品
bool CommandExecutor::RemoveItem(string p_item){
    /*p_item = lowerCase(p_item);

    if (p_item == "weapon" && m_player.Weapon() != 0)
    {
        cout << "卸下" << m_player.Weapon()->Nmae() << endl;
        m_player.RemoveWeapon();

        return true;
    }

    if (p_item == "armor" && m_player.Armor() != 0)
    {
        cout << "脱下" << m_player.Armor()->Name() << endl;
        m_player.RemoveArmor();

        return true;
    }*/

    if (p_item == "武器" && m_player.Weapon() != 0)
    {
        cout << "卸下" << m_player.Weapon()->Nmae() << endl;
        m_player.RemoveWeapon();

        return true;
    }

    if (p_item == "护具" && m_player.Armor() != 0)
    {
        cout << "脱下" << m_player.Armor()->Name() << endl;
        m_player.RemoveArmor();

        return true;
    }

    cout << "无法卸掉" << p_item << endl;
    return false;
}

string CommandExecutor::PrintRoom(room p_room){

    return string();
}

void CommandExecutor::New()
{
}
