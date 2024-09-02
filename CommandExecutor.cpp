#include "CommandExecutor.h"
#include <iostream>
#include <sstream>
using namespace std;

//��Ҫ����NPC�Ľ�����߼�����
bool CommandExecutor::Execute(const Command& cmd) {
    if (cmd.action == "drop") {
        return (DropItem(cmd));
    }
    else if (cmd.action == "pick") {
        return (GetItem(cmd));
    }
    else if (cmd.action == "buy") {
        return (Buy(cmd));
    }
    else if (cmd.action == "sell") {
        return (Sell(cmd));
    }
    else if (cmd.action == "use") {
        return (UseItem(cmd));
    }
    else if (cmd.action == "remove") {
        return (RemoveItem(cmd));
    }
    else if (cmd.action == "quit") {
        return (Quit(cmd));
    }
    else if (cmd.action == "help") {
        PrintHelp();
        return true;
    }
    else{
        cout << "ɶ��" << endl;    
    }
    return false;
}

//��ҵ���ǳ�
void CommandExecutor::New() {
    string name;
    int type;

    if (Player::getPlayer() != nullptr) {
        Player::deletePlayer();
    }

    cout << "���"<<"\033[36m"<<"����"<<"\033[0m"<<"�ǣ������磺��ӥ��" << endl;
    cout <<"\033[34m" <<">"<<"\033[0m";
    cin >> name;

    cout << "���"<<"\033[36m"<<"��������"<<"\033[0m"<<"�ǣ�������1���򹥻�����Ϊ�⣩" << endl;
    cout <<"\033[34m" <<">"<<"\033[0m";
    cin >> type;

    //����Ԫ��ѡ��
    m_player = Player::creatPlayer(name, type);
}

bool CommandExecutor::Continue() {
    m_player = Player::addPlayer();

    if (m_player == nullptr) {
        cout << "û�д浵֮ǰ����Ϸ��" << endl;
        return false;
    }

    return true;
}

bool CommandExecutor::Quit(const Command& cmd){
    if (!cmd.argus.empty()) {
        cout << "ɶ" << endl;
        return false;
    }

    exit(0);
}

//��ӡ����
void CommandExecutor::PrintHelp(){

}

void CommandExecutor::PrintInventory(){
    Player& p = *m_player;

    cout << "-------------------------------- ��ı��� --------------------------------" << endl;
    cout << " ID:  |��Ʒ:" << endl;

    for (int i = 0; i < p.Items(); i++){
        cout << left << setw(2) << p.getItem(i)->ID() << "  |" << p.getItem(i)->Name() << endl;
    }

    cout << "\n-------------------------------- ���װ�� --------------------------------" << endl;

    if (p.Weapon() == 0) {
        cout << "\033[31m"<<"û��������"<<"\033[0m"<<"���޿�Ѽ֮����" << endl;
    }
    else {
        cout << " ����:  " << p.Weapon()->Name() << endl;
    }

    if (p.Armor() == 0) {
        cout << "û�л��ߣ�" << endl;
    }
    else {
        cout << " ����:  " << p.Armor()->Name() << endl;
    }

    cout << "Money:  ��" << p.Money() << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}

void CommandExecutor::PrintMyNPC(){

}

//��Ʒ��������
bool CommandExecutor::UseItem(const Command& cmd){
    string p_item = cmd.argus;
    int i = m_player->getItemIndex(p_item);

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return false;
    }

    if (i == -1)
    {
        cout <<"\033[31m"<< "�Ҳ�������Ʒ��" <<"\033[0m"<< endl;
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

bool CommandExecutor::RemoveItem(const Command& cmd){
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
    }
    

    /*if (cmd.argus.empty()) {
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
    }*/

    cout <<"`\033[31m"<< "�޷�ж��" << p_item<<"\033[0m" << endl;
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
        temp << "��" << p_room->Money() << "\n ";
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
        temp << (*enemyitr)->Name() << " (Ѫ��:   " << (*enemyitr)->HitPoints() << " )" << ", ";
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

bool CommandExecutor::GetItem(const Command& cmd){
    string p_item = cmd.argus;
    

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return false;
    }

    if (p_item[0] == '��'){
        sstream p_money; 
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;
       
        if (m > m_player->CurrentRoom()->Money())
        {
            cout << "û����ô��Ǯ��"<<"\033[31m"<<"�����Σ�" <<"\033[0m"<< endl;

            return false;
        }
        else
        {
            m_player.Money() += m;
            m_player->CurrentRoom()->Money() -= m;
            cout << "���� ��" << m << "Ԫ" << endl;
            cout << "tips��Ȱ�㽻�������:)" << endl;
        }

        return true;
    }

    item i = m_player->CurrentRoom()->FindItem(p_item);

    if (i == 0){
        cout << "����û����Ҫ�Ķ�����" << endl;

        return false;
    }
    
    if (!m_player->pickItem(i)){
        cout << "���ò�����ô�ණ���ˣ�"<<"\033[31m"<<"��̫̰��" <<"\033[0m" << endl;

        return false;
    }

    m_player->CurrentRoom()->removeItem(i);
    cout << "��ӵ��ϼ������ǻҳ���" << i->Name() << endl;

    return true;
}

bool CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;

        return false;
    }

    if (p_item[0] == '$'){
        sstream p_money;
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;

        if (m > m_player->Money()){
            cout << "��û��ô��Ǯ����" << endl;

            return false;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "\033[33m"<<"��ϲ�㣡"<<"\033[0m"<<"��������" << m << "ԪǮ��" << endl;
        }

        return true;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "�㲻��ӵ��" << p_item << endl;

        return false;
    }

    cout << "��������" << p_item << endl;

    m_player->currentRoom()->addItem(m_player->getItem(i));
    m_player->dropItem(i);

    return true;
}

void CommandExecutor::StoreList(entityid p_store){//��ʽ����δ���
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

        return false;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "�����Ѿ���" << p_item << "��"<<"\033[31m"<<"����ȡ��" <<"\033[0m"<< endl;

        return false;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "\033[31m"<<"�ɹ�����" << p_item <<"\033[0m"<< "����ϲǮ���ֶ���" << i->Price() << "Ԫ" << endl;

    return true;
}

//NPC��������
npc CommandExecutor::ChooseNPC(string p_item){
    int id = m_player->findNPC(p_item);

    if (id = 0) {
        cout << "�Ҳ�������\n" << "�������˭��" << endl;
        return 0;
    }

    cout << "\033[34m" <<">"<<"\033[0m"; << endl;
    cin >>

    return id;
}

bool CommandExecutor::UseItemToNPC(const Command& cmd, npc& p_npc){//δ���
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;

        return false;
    }

    //������Ʒ�ڲ���
    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "�㲻��ӵ��" << p_item << endl;

        return false;
    }
    //�ж�װ����û�б�װ����
    if (itm == m_player->Weapon()||itm == m_player->Armor()) {
        cout << "���Ѿ�װ�����ˣ���Ʒ�ɲ��������" << endl;

        return false;
    }

    switch (itm.Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "��" <<"\033[33m"<< m_npc->Name() <<"\033[0m"<< "װ����" << itm.Name() << endl;

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "��" <<"\033[33m"<< m_npc->Name() << "\033[0m"<< "����" << itm.Name() < endl;

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "��" <<"\033[33m"<< m_npc->Name() << "\033[0m"<< "ʹ��" << itm.Name() << endl;

        return true;
    case EXP:
        m_npc->addEXP(itm);
        m_player->dropItem(index);
        cout << <<"��" <<"\033[33m"<< m_npc->Name() << "\033[0m"<< "ʹ��" << itm.Name() << endl;

        return true;
    default:
        cout << "����ʧ��" << endl;

        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd, npc& p_npc){
    string p_item = cmd.argus;

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

bool CommandExecutor::ShowFace(npc p_npc){
    int id = npc;
    switch (id) {
    case 1:
        firstFace();
        break;
    case 2:
        secondFace();
        break;
    case 3:
        thirdFace();
        break;
    case 4:
        forthFace();
        break;
    default:
        return false;
    }
    return true;
}



