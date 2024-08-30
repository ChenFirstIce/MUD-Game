#include "CommandExecutor.h"
#include <iostream>
#include <sstream>
using namespace std;

void CommandExecutor::Execute(const Command& cmd) {
    if (cmd.action == "move") {
        Move(cmd);
    }
    else if (cmd.action == "attack") {
        handleAttack(cmd);
    }
    else if (cmd.action == "pickup") {
        handlePickup(cmd);
    }
    else {
        cout << "ɶ��" << endl;
    }
}

//��ҵ���ǳ�
void CommandExecutor::New(){
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

void CommandExecutor::Continue(){
    m_player = Player::addPlayer();
    
    if (m_player == nullptr) {
        cout << "û�д浵֮ǰ����Ϸ��" << endl;
    }
}

void CommandExecutor::Quit(){
    Player::savePlayer();
    exit(0);
}

//��Ʒ��������
bool CommandExecutor::UseItem(const Command& cmd){
    string p_item = cmd.argus;
    int i = m_player->getItemIndex(p_item);

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    if (i == -1)
    {
        cout << "�Ҳ�������Ʒ��" << endl;
        return false;
    }

    Item& itm = *(m_player->getItem(i));


    switch (itm.Type())
    {
    case WEAPON:
        m_player->useWeapon(i);
        cout << "װ����" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player->useArmor(i);
        cout << "����" << itm.Name() < endl;

        return true;

    case HEALING:
        m_player->useHealing(i);
        m_player->dropItem(i);
        cout << "ʹ��" << itm.Name() << endl;

        return true;
    case EXP:
        m_player->addEXP(i);
        m_player->dropItem(i);
        cout << "ʹ��" << itm.Name() << endl;

        return true;
    }

    return false;
}

//��Ʒ����
bool CommandExecutor::RemoveItem(const Command& cmd){
    /*
    string p_item = cmd.argus;
    p_item = lowerCase(p_item);

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
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    if (p_item == "����" && m_player->Weapon() != 0)
    {
        cout << "ж��" << m_player->Weapon()->Nmae() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "����" && m_player->Armor() != 0)
    {
        cout << "����" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }

    cout << "�޷�ж��" << p_item << endl;
    return false;
}

//���以������
void CommandExecutor::PrintRoom(){
    room p_room = m_player->currentRoom();
    stringstream temp;
    int count = 0;

    temp << p_room->Description() << "\n\n";

    //�����Ǯ
    count = 0;
    temp << "��Ǯ��  ";
    if (p_room->Money() > 0)
    {
        count++;
        temp << "$" << p_room->Money() << "\n ";
    }

    //��Ʒ
    temp << "��Ʒ��  ";
    list<item>::iterator itemitr = p_room->Items().begin();
    while (itemitr != p_room->Items().end())
    {
        count++;
        temp << (*itemitr)->Name() << ", ";
        itemitr++;
    }

    if (count > 0)
    {
        string foo = temp.str();
        temp.clear();
        foo.erase(temp.size() - 2, 2);
        temp << foo << "\n\n";
    }

    //����
    temp <<  "���ˣ�  ";
    cout = 0;
    list<enemy>::iterator enemyitr = p_room->Enemies().begin();
    while (enemyitr != p_room->Enemies().end()){
        temp << (*enemyitr)->Name() << ", ";
        count++;
        enemyitr++;
    }
    if (count > 0){
        string foo = temp.str();
        temp.clear();
        foo.erase(temp.size() - 2, 2);
        temp << foo << "\n\n";
    }

    //���ȫ����ӡ
    ccout << temp.str();
}

void CommandExecutor::GetItem(const Command& cmd){
    string p_item = cmd.argus;
    

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    if (p_item[0] == '��'){
        sstream p_money; 
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;
       
        if (m > m_player->CurrentRoom()->Money())
        {
            cout << "û����ô��Ǯ�������Σ�" << endl;
        }
        else
        {
            m_player.Money() += m;
            m_player->CurrentRoom()->Money() -= m;
            cout << "���� ��" << m << "Ԫ" << endl;
            cout << "tips��Ȱ�㽻�������:)" << endl;
        }
        return;
    }

    item i = m_player->CurrentRoom()->FindItem(p_item);

    if (i == 0){
        cout << "����û����Ҫ�Ķ�����" << endl;
        return;
    }
    
    if (!m_player->pickItem(i)){
        cout << "���ò�����ô�ණ���ˣ���̫̰��" << endl;
        return;
    }

    m_player->CurrentRoom()->removeItem(i);
    cout << "��ӵ��ϼ������ǻҳ���" << i->Name() << endl;
}

void CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    if (p_item[0] == '$'){
        sstream p_money;
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;

        if (m > m_player->Money()){
            cout << "��û��ô��Ǯ����" << endl;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "��ϲ�㣡��������" << m << "ԪǮ��" << endl;
        }
        return;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "�㲻��ӵ��" << p_item << endl;
        return;
    }

    cout << "��������" << p_item << endl;

    m_player->currentRoom()->addItem(m_player->getItem(i));
    m_player->dropItem(i);
}

void CommandExecutor::StoreList(){//��ʽ����δ���
    Store& s = StoreDatabase::get(p_store);

    cout << "--------------------------------------------------------------------------------\n";
    cout << " ��ӭ���� " + s.Name() + "!\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << " ��Ʒ                           | �۸�\n";
    cout << "--------------------------------------------------------------------------------\n";

    Store::iterator itr = s.begin();
    while (itr != s.end())
    {
        cout << left << setw(40) << itr->Name() << "| ";
        cout << left << setw(4) << itr->Price() << '\n';
        itr++;
    }
    cout << "--------------------------------------------------------------------------------\n";
        
}

void CommandExecutor::Buy(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    item i = s.find(p_item);
    if (i == 0)
    {
        cout << "����û������Ҫ�Ķ���" << endl;
        return;
    }

    if (p.Money() < i->Price())
    {
        cout << "������ѽ���е㵣������" << endl;
        return;
    }

    if (!p.pickItem(i))
    {
        cout << "�����Ѿ�װ�����ˣ�" << endl;
        return;
    }

    p.Money() -= i->Price();
    cout << "����" << p_item << ",�Ѿ����뱳���ˣ�" << endl;
}

void CommandExecutor::Sell(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    int index = p.getItemIndex(p_item);
    if (index == -1)
    {
        cout << "�㲻��ӵ��" << p_item << endl;
        return;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "�����Ѿ���" << p_item << "������ȡ��" << endl;
        return;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "�ɹ�����" << p_item << "����ϲǮ���ֶ���" << i->Price() << "Ԫ" << endl;
}

//NPC��������
npc CommandExecutor::ChooseNPC(string p_item){
    int id = m_player->findNPC(p_item);

    if (id = 0) {
        cout << "�Ҳ�������\n" << "�������˭��" << endl;
        return 0;
    }

    cout << "> " << endl;
    cin >>

    return id;
}

bool CommandExecutor::UseItemToNPC(const Command& cmd){//δ���
    string p_item;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return false;
    }

    npc p_npc = ChooseNPC(cmd.argus);

    //����Ҫʹ�õĶ���
    cout << "��Ҫʹ�ã�" << endl;
    cout << "> " << endl;
    cin >> p_item;

    //������Ʒ�ڲ���
    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "�㲻��ӵ��" << p_item << endl;
        return false;
    }
    //�ж�װ����û�б�װ����
    if (itm == m_player->Weapon()||itm == m_player->Armor()) {
        cout << "���Ѿ�װ����������Ʒ�ɲ��������" << endl;
        return false;
    }

    switch (itm.Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "��" << m_npc->Name() << "װ����" << itm.Name() << endl;

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "��" << m_npc->Name() << "����" << itm.Name() < endl;

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "��" << m_npc->Name() << "ʹ��" << itm.Name() << endl;

        return true;
    case EXP:
        m_npc->addEXP(itm);
        m_player->dropItem(index);
        cout << <<"��" << m_npc->Name() << "ʹ��" << itm.Name() << endl;

        return true;
    default:
        cout << "����ʧ��" << endl;
        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd){
    string p_item;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return false;
    }

    npc p_npc = ChooseNPC(cmd.argus);

    //�ж���û��װ����
    if (p_item == "����" && p_npc->Weapon() != 0)
    {
        cout << "ж��" << p_npc->Weapon()->Nmae() << endl;
        p_npc->removeWeapon();

        return true;
    }

    if (p_item == "����" && p_npc->Armor() != 0)
    {
        cout << "����" << p_npc->Armor()->Name() << endl;
        p_npc->removeArmor();

        return true;
    }
}


