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
        cout << "ɶ��" << endl;
    }
}

void CommandExecutor::New(const Command& cmd){
    string name;
    int type;

    if (cmd.args.empty()) {
        if (Player::getPlayer() != nullptr) {
            Player::deletePlayer();
        }

        cout << "��������ǣ������磺��ӥ��" << endl;
        cout << ">";
        cin >> name;

        cout << "��Ĺ��������ǣ�������1���򹥻�����Ϊ�⣩" << endl;
        cout << ">";
        cin >> type;

        //����Ԫ��ѡ��
        m_player = Player::creatPlayer(name,type);
    }
    else {
        cout << "ɶ��" << endl;
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
        cout << "ɶ��" << endl;
    }
}

//��Ʒ
bool CommandExecutor::UseItem(const string& p_item){
    int i = m_player.getItemIndex(p_item);

    if (i == -1)
    {
        cout << "�Ҳ�������Ʒ��" << endl;
        return false;
    }

    Item& itm = *p_player.getItem(i);


    switch (itm.Type())
    {
    case WEAPON:
        m_player.useWeapon(i);
        cout << "װ����" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player.useArmor(i);
        cout << "����" << itm.Name() < endl;

        return true;

    case HEALING:
        m_player.addBonuses(itm.ID());
        m_player.dropItem(i);
        cout << "ʹ��" << itm.Name() << endl;

        return true;
    }

    return false;
}

//��Ʒ
bool CommandExecutor::RemoveItem(string p_item){
    /*p_item = lowerCase(p_item);

    if (p_item == "weapon" && m_player.Weapon() != 0)
    {
        cout << "ж��" << m_player.Weapon()->Nmae() << endl;
        m_player.RemoveWeapon();

        return true;
    }

    if (p_item == "armor" && m_player.Armor() != 0)
    {
        cout << "����" << m_player.Armor()->Name() << endl;
        m_player.RemoveArmor();

        return true;
    }*/

    if (p_item == "����" && m_player.Weapon() != 0)
    {
        cout << "ж��" << m_player.Weapon()->Nmae() << endl;
        m_player.RemoveWeapon();

        return true;
    }

    if (p_item == "����" && m_player.Armor() != 0)
    {
        cout << "����" << m_player.Armor()->Name() << endl;
        m_player.RemoveArmor();

        return true;
    }

    cout << "�޷�ж��" << p_item << endl;
    return false;
}

string CommandExecutor::PrintRoom(room p_room){

    return string();
}

void CommandExecutor::New()
{
}
