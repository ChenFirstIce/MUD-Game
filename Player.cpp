#include "stdc++.h"
#include "Matchentity.h"
#include "Player.h"
#include "func.h"
using namespace std;

extern string UTF8ToGB(const char* str);

//实例化
Player* Player::Instance = nullptr;

Player::Player(string p_name, AttackType p_type) :name(p_name),m_type(p_type) {
    m_level = 1;
    m_room = 1;
    m_task = 0;
    m_money = 100;
    m_items = 0;
    m_weapon = -1;
    m_armor = -1;
    recalculateStats();
    m_hitpoints = getAttr(MAXHITPOINTS);
    cout << "创建玩家" << name << "成功…" << endl;
}

void Player::creatPlayer(string p_name, string type){
    if (Instance == nullptr) {
        Instance = new Player(p_name);
        Instance->setType(type);
    }

   /* return *Instance;*/
}

void Player::deletePlayer(){
    if (Instance != nullptr) {
        delete Instance;
        Instance = nullptr;
    }
}

Player* Player::getPlayer(){
    if (Instance == nullptr) {
        return nullptr;
    }

    return Instance;
}

//打印信息
void Player::showPlayer() {//未完成
    cout << "---------------------------------- 玩家信息 ----------------------------------" << endl;
    cout << " 名字:   " << name << endl;
    cout << " 等级:   " << left << setw(4) << m_level << endl;
    cout << " 经验:   " << left << setw(4) << m_exp << "/" << left << setw(4) << needforLevel(m_level + 1) << endl;
    cout << " 属性:   ";

    if (m_type == LIGHT)
    {
        cout << "光";
    }
    else if (m_type == FIRE) {
        cout << "\033[31m火";
    }
    else if (m_type == GRASS) {
        cout << "\033[32m草";
    }
    else if (m_type == GOLD) {
        cout << "\033[33m金";
    }
    cout << "\033[0m\n--------------------------------------------------------------------------------\n";
}

//等级&经验
int Player::needforLevel(int p_level){
    return (int)(100 * pow(1.4, p_level - 1) - 1);
}

int Player::needforNextLevel(){
    return needforLevel(m_level + 1) - m_exp;
}

void Player::addExp(int exp) {
    m_exp += exp;

    while (needforNextLevel()<=0) {
        m_level++;
    }
    while (m_exp < needforLevel(m_level)) {
        m_level--;
    }
}

//属性
int Player::getAttr(int p_attr) {
    int val = m_attributes[p_attr] + m_baseattributes[p_attr];
    return val;
}

void Player::setBaseAttr(int p_attr, int p_val){
    m_baseattributes[p_attr] = p_val;
    recalculateStats();
}

void Player::addToBaseAttr(int p_attr, int p_val) {
    m_baseattributes[p_attr] += p_val;
    recalculateStats();
}

//战斗属性
string Player::getType(){
    if (m_type == LIGHT) {
        return "LIGHT";
    }
    else if (m_type == GOLD) {
        return "GOLD";
    }
    else if (m_type == FIRE) {
        return "FIRE";
    }
    else if (m_type == GRASS) {
        return "GRASS";
    }
    else {
        cout << "AttackType Error!";
        exit(2);
    }
}

void Player::setType(string type) {
    if (type == "LIGHT") {
        m_type = LIGHT;
    }
    else if (type == "GOLD") {
        m_type = GOLD;
    }
    else if (type == "FIRE") {
        m_type = FIRE;
    }
    else if (type == "GRASS") {
        m_type = GRASS;
    }
    else {
        cout << "AttackType Error!";
        exit(3);
    }
}


//加持
void Player::addDynamicBonuses(item p_item){
    Item& i = *p_item;

    if (p_item == 0)
        return;
    
    for (int x = 0; x < NUMATTRIBUTES; x++)
        m_attributes[x] += i.getAttr(x);
}


void Player::addBonuses(item p_item){
    Item& i = *p_item;
    int t = 0;

    if (p_item == 0) {
        return;
    }//不成功，未找到
    else {
        t = i.Min() + rand() % (i.Max() - i.Min() + 1);
    }

    if (i.Type() == HEALING) {
        addHitPoints(t);
    }
    else if (i.Type() == EXP) {
        addExp(t);
    }

    recalculateStats();
}

//血量
void Player::addHitPoints(int p_hitpoints) {
    m_hitpoints += p_hitpoints;

    if (m_hitpoints < 0) {
        m_hitpoints = 0;
    }
    else if (m_hitpoints > getAttr(MAXHITPOINTS)) {
        m_hitpoints = getAttr(MAXHITPOINTS);
    }
}

//重新计算属性值
void Player::recalculateStats() {
    m_attributes[MAXHITPOINTS] = 10 + ((int)(m_level * (10 / 1.5)));

    if (m_hitpoints > getAttr(MAXHITPOINTS))
        m_hitpoints = getAttr(MAXHITPOINTS);

    if (Weapon() != 0)
        addDynamicBonuses(Weapon());//增加武器的属性值（随机）
    if (Armor() != 0)
        addDynamicBonuses(Armor());//增加护具的属性值（随机）
}

//物品函数
int Player::getItemIndex(string& p_name){
    item* itr1 = find_if(m_inventory, m_inventory + MaxItems(), matchEntityFull(p_name));
    item* itr2 = find_if(m_inventory, m_inventory + MaxItems(), matchEntity(p_name));

    if (itr1 != m_inventory + MaxItems()) {
        return (itr1 - m_inventory);
    }
    else if (itr2 != m_inventory + MaxItems()) {
        return (itr2 - m_inventory);
    }
    return 0;
}

//返回武器
item Player::Weapon(){
    if (m_weapon == -1) return 0;
    else return m_inventory[m_weapon];
}

item Player::Armor() {
    if (m_armor == -1) return 0;
    else return m_inventory[m_armor];
}

//修改装备仓
bool Player::pickItem(item p_item) {
    if (m_items < MaxItems()) {
        item* itr = m_inventory;

        while (*itr != nullptr) {
            itr++;
        }

        *itr = p_item;
        m_items++;

        return true;
    }

    return false;
}

bool Player::dropItem(int p_index) {
    if (m_inventory[p_index] != 0) {
        if (m_weapon == p_index) {
            removeWeapon();
        }
        else if (m_armor == p_index) {
            removeArmor();
        }
        m_inventory[p_index] = 0;
        m_items--;
        return true;
    }

    return false;
}

//增加NPC和寻找NPC
npc Player::findNPC(string& p_npc){
    list<npc>::iterator itr = find_if(m_npces.begin(), m_npces.end(), matchEntityFull(p_npc));

    if (itr != m_npces.end()) {
        return *itr;
    }
    else {
        itr = find_if(m_npces.begin(), m_npces.end(), matchEntity(p_npc));
        if (itr != m_npces.end()) {
            return *itr;
        }
    }

    return 0;
}

void Player::addNPC(){
    npc p_npc;
    int id;

    system("cls");

    cout << "你可以选择解救:" << endl;

    for (int i = 1; i <= 3;i++) {
        p_npc = i;

        if (!p_npc->Stats()) {
            cout << "ID " << i;
            switch (i) {
            case 1:
                cout << "\033[32m";
                break;
            case 2:
                cout << "\033[33m";
                break;
            case 3:
                cout << "\033[31m";
            }

            cout << p_npc->Name() << " " << endl;
        }

        cout << "\033[0m";
    }

    cout << "请选择输入要解救的男主的ID" << endl;
    cout << "> ";
    cin >> id;

    p_npc = id;

    while (id < 1 || id > 3 || p_npc->Stats()) {
        cout << "错误！请重新输入！" << endl;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        cout << "> ";
        cin >> id;
    }

    p_npc = id;
    m_npces.push_back(p_npc);
    p_npc->Stats() = true;

    m_task++;
}

//物品互动
void Player::removeWeapon() {
    m_weapon = -1;
    recalculateStats();
}

void Player::removeArmor() {
    m_armor = -1;
    recalculateStats();
}

void Player::useWeapon(int p_index){
    removeWeapon();
    m_weapon = p_index;
    recalculateStats();
}

void Player::useArmor(int p_index){
    removeArmor();
    m_armor = p_index;
    recalculateStats();
}

void Player::useHealing(int p_index) {
    item itr = m_inventory[p_index];
    addBonuses(itr);
}

void Player::useExp(int p_index){
    item itr = m_inventory[p_index];
    addBonuses(itr);
}

//文件储存
ostream& operator<<(ostream& p_stream, Player& p){
    p_stream << "[NAME]           " << p.name << "\n";
    //p_stream << "[STATPOINTS]     " << p.m_statpoints << "\n";
    p_stream << "[ATTACKTYPE]     " << p.getType() << "\n";//后来增加的
    p_stream << "[TASK]           " << p.m_task << '\n';//增加的故事节点
    p_stream << "[EXPERIENCE]     " << p.m_exp << "\n";
    p_stream << "[LEVEL]          " << p.m_level << "\n";
    p_stream << "[ROOM]           " << p.m_room << "\n";
    p_stream << "[MONEY]          " << p.m_money << "\n";
    p_stream << "[HITPOINTS]      " << p.m_hitpoints << "\n";
    p_stream << p.m_baseattributes;

    p_stream << "[INVENTORY]      ";
    for (int i = 0; i < p.MaxItems(); i++)
    {
        p_stream << p.m_inventory[i] << " ";
    }
    p_stream << "\n";

    p_stream << "[NPC]            ";
    list<npc>::iterator itr = p.m_npces.begin();
    while (itr != p.m_npces.end()) {
        p_stream << *itr << " ";
        itr++;
    }

    
    p_stream << "0\n";

    p_stream << "[WEAPON]         " << p.m_weapon << "\n";
    p_stream << "[ARMOR]          " << p.m_armor << "\n";

    return p_stream;
}

istream& operator>>(istream& p_stream, Player& p){
    string temp;
    string type;

    p_stream >> temp >> ws;
    getline(p_stream, p.name);
    //p_stream >> temp >> p.m_statpoints;
    p_stream >> temp >> type;
    p.setType(type);
    p_stream >> temp >> p.m_task;
    p_stream >> temp >> p.m_exp;
    p_stream >> temp >> p.m_level;
    p_stream >> temp >> p.m_room;
    p_stream >> temp >> p.m_money;
    p_stream >> temp >> p.m_hitpoints;
    p_stream >> p.m_baseattributes;

    p_stream >> temp;
    p.m_items = 0;
    for (int i = 0; i < p.MaxItems(); i++){
        p_stream >> p.m_inventory[i];
        if (p.m_inventory[i] != 0)
            p.m_items++;
    }

    p.m_npces.clear();
    entityid last;
    while (extract(p_stream, last) != 0)
        p.m_npces.push_back(last);

    p_stream >> temp >> p.m_weapon;
    p_stream >> temp >> p.m_armor;

    p.recalculateStats();

    return p_stream;
}

//玩家读存档
void Player::savePlayer(){
    ofstream file("player.txt");

    file << *Instance;

    cout << "玩家" << Instance->name << "存档成功" << endl;

    file.close();
}

Player* Player::addPlayer(){
    ifstream file("player.txt");
    Player::creatPlayer();

    Instance = Player::getPlayer();
    file >> *Instance;

    cout << "玩家" << Instance->name << "读档成功" << endl;

    file.close();
    return Instance;
}

//
Player& Player::get(int m_id) {
    if (Instance == nullptr) {
        cout << "未创建玩家Instance" << endl;
        exit(5);
    }
    else {
        return *Instance;
    }
}

