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
        cout << "啥？" << endl;
    }
}

//玩家登入登出
void CommandExecutor::New(){
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

void CommandExecutor::Continue(){
    m_player = Player::addPlayer();
    
    if (m_player == nullptr) {
        cout << "没有存档之前的游戏。" << endl;
    }
}

void CommandExecutor::Quit(){
    Player::savePlayer();
    exit(0);
}

//物品互动函数
bool CommandExecutor::UseItem(const Command& cmd){
    string p_item = cmd.argus;
    int i = m_player->getItemIndex(p_item);

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    if (i == -1)
    {
        cout << "找不到该物品。" << endl;
        return false;
    }

    Item& itm = *(m_player->getItem(i));


    switch (itm.Type())
    {
    case WEAPON:
        m_player->useWeapon(i);
        cout << "装备上" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player->useArmor(i);
        cout << "穿上" << itm.Name() < endl;

        return true;

    case HEALING:
        m_player->useHealing(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    case EXP:
        m_player->addEXP(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    }

    return false;
}

//物品互动
bool CommandExecutor::RemoveItem(const Command& cmd){
    /*
    string p_item = cmd.argus;
    p_item = lowerCase(p_item);

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
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    if (p_item == "武器" && m_player->Weapon() != 0)
    {
        cout << "卸下" << m_player->Weapon()->Nmae() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "护具" && m_player->Armor() != 0)
    {
        cout << "脱下" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }

    cout << "无法卸掉" << p_item << endl;
    return false;
}

//房间互动函数
void CommandExecutor::PrintRoom(){
    room p_room = m_player->currentRoom();
    stringstream temp;
    int count = 0;

    temp << p_room->Description() << "\n\n";

    //房间金钱
    count = 0;
    temp << "金钱：  ";
    if (p_room->Money() > 0)
    {
        count++;
        temp << "$" << p_room->Money() << "\n ";
    }

    //物品
    temp << "物品：  ";
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

    //敌人
    temp <<  "敌人：  ";
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

    //最后全部打印
    ccout << temp.str();
}

void CommandExecutor::GetItem(const Command& cmd){
    string p_item = cmd.argus;
    

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    if (p_item[0] == '￥'){
        sstream p_money; 
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;
       
        if (m > m_player->CurrentRoom()->Money())
        {
            cout << "没有那么多钱，少做梦！" << endl;
        }
        else
        {
            m_player.Money() += m;
            m_player->CurrentRoom()->Money() -= m;
            cout << "捡起 ￥" << m << "元" << endl;
            cout << "tips：劝你交到警察局:)" << endl;
        }
        return;
    }

    item i = m_player->CurrentRoom()->FindItem(p_item);

    if (i == 0){
        cout << "这里没你想要的东西。" << endl;
        return;
    }
    
    if (!m_player->pickItem(i)){
        cout << "你拿不下这么多东西了，别太贪。" << endl;
        return;
    }

    m_player->CurrentRoom()->removeItem(i);
    cout << "你从地上捡起满是灰尘的" << i->Name() << endl;
}

void CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    if (p_item[0] == '$'){
        sstream p_money;
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;

        if (m > m_player->Money()){
            cout << "你没那么多钱……" << endl;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "恭喜你！你又少了" << m << "元钱！" << endl;
        }
        return;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "你不曾拥有" << p_item << endl;
        return;
    }

    cout << "你抛弃了" << p_item << endl;

    m_player->currentRoom()->addItem(m_player->getItem(i));
    m_player->dropItem(i);
}

void CommandExecutor::StoreList(){//格式控制未完成
    Store& s = StoreDatabase::get(p_store);

    cout << "--------------------------------------------------------------------------------\n";
    cout << " 欢迎来到 " + s.Name() + "!\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << " 物品                           | 价格\n";
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
        cout << "啥？" << endl;
        return;
    }

    item i = s.find(p_item);
    if (i == 0)
    {
        cout << "这里没有你想要的东西" << endl;
        return;
    }

    if (p.Money() < i->Price())
    {
        cout << "……诶呀，有点担负不起" << endl;
        return;
    }

    if (!p.pickItem(i))
    {
        cout << "背包已经装不下了！" << endl;
        return;
    }

    p.Money() -= i->Price();
    cout << "购入" << p_item << ",已经放入背包了！" << endl;
}

void CommandExecutor::Sell(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    int index = p.getItemIndex(p_item);
    if (index == -1)
    {
        cout << "你不曾拥有" << p_item << endl;
        return;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "我们已经有" << p_item << "，交易取消" << endl;
        return;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "成功卖出" << p_item << "，恭喜钱包又多了" << i->Price() << "元" << endl;
}

//NPC互动函数
npc CommandExecutor::ChooseNPC(string p_item){
    int id = m_player->findNPC(p_item);

    if (id = 0) {
        cout << "找不到他。\n" << "他是你的谁？" << endl;
        return 0;
    }

    cout << "> " << endl;
    cin >>

    return id;
}

bool CommandExecutor::UseItemToNPC(const Command& cmd){//未完成
    string p_item;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return false;
    }

    npc p_npc = ChooseNPC(cmd.argus);

    //输入要使用的东西
    cout << "你要使用？" << endl;
    cout << "> " << endl;
    cin >> p_item;

    //检验物品在不在
    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "你不曾拥有" << p_item << endl;
        return false;
    }
    //判断装备有没有被装备过
    if (itm == m_player->Weapon()||itm == m_player->Armor()) {
        cout << "你已经装备过来，物品可不会分身……" << endl;
        return false;
    }

    switch (itm.Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "给" << m_npc->Name() << "装备上" << itm.Name() << endl;

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "给" << m_npc->Name() << "穿上" << itm.Name() < endl;

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "给" << m_npc->Name() << "使用" << itm.Name() << endl;

        return true;
    case EXP:
        m_npc->addEXP(itm);
        m_player->dropItem(index);
        cout << <<"给" << m_npc->Name() << "使用" << itm.Name() << endl;

        return true;
    default:
        cout << "给予失败" << endl;
        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd){
    string p_item;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return false;
    }

    npc p_npc = ChooseNPC(cmd.argus);

    //判断有没有装备过
    if (p_item == "武器" && p_npc->Weapon() != 0)
    {
        cout << "卸下" << p_npc->Weapon()->Nmae() << endl;
        p_npc->removeWeapon();

        return true;
    }

    if (p_item == "护具" && p_npc->Armor() != 0)
    {
        cout << "脱下" << p_npc->Armor()->Name() << endl;
        p_npc->removeArmor();

        return true;
    }
}


