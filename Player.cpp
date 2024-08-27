#include <bits/stdc++.h>
#include "Matchentity.h"
#include "Player.h"
using namespace std;

//实例化
Player* Player::Instance = nullptr;

Player::Player(string p_name = "雌鹰") :name(p_name) {
    m_level = 1;
    m_room = 0;
    //m_statpoints = 0;
    m_type = LIGHT;
    m_money = 100;
    m_items = 0;
    m_weapon = -1;
    m_armor = -1;
    recalculateStats();
    m_hitpoints = getAttr(MAXHITPOINTS);
    cout << "创建玩家" << name << "成功…" << endl;
}

Player& Player::getNewPlayer(string p_name){
    if (Instance == nullptr) {
        Instance = new Player(p_name);
    }

    return *Instance;
}
//打印信息
void Player::showPlayer() {//未完成
    cout << "*********************************************************************" << endl;
    cout << left;
    cout << setw(10) << "name:" << setw(10) << name << endl;
    cout << setw(10) << "HP:" << setw(10) << m_hitpoints << '/' << m_attributes[MAXHITPOINTS];
    cout << setw(10) << "EXP:";
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
int Player::getType(){
    if (m_type == LIGHT) {
        return 1;
    }
    else if (m_type == GOLD) {
        return 2;
    }
    else if (m_type == FIRE) {
        return 3;
    }
    else if (m_type == GRASS) {
        return 4;
    }
    else {
        cout << "AttackType Error!";
        exit(2);
    }
}

void Player::setType(int p_attr) {
    switch (p_attr) {
    case 1:
        m_type = LIGHT;
        break;
    case 2:
        m_type = GOLD;
        break;
    case 3:
        m_type = FIRE;
        break;
    case 4:
        m_type = GRASS;
    default:
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
        t = i.Min() + rand() % (i.Max() - i.Min());
    }

    if(i.Type()==HEALING){
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


    p_stream << "[WEAPON]         " << p.m_weapon << "\n";
    p_stream << "[ARMOR]          " << p.m_armor << "\n";

    return p_stream;
}

istream& operator>>(istream& p_stream, Player& p){
    string temp;
    int type;

    p_stream >> temp >> ws;
    getline(p_stream, p.name);
    //p_stream >> temp >> p.m_statpoints;
    p_stream >> temp >> type;
    p.setType(type);
    p_stream >> temp >> p.m_exp;
    p_stream >> temp >> p.m_level;
    p_stream >> temp >> p.m_room;
    p_stream >> temp >> p.m_money;
    p_stream >> temp >> p.m_hitpoints;
    p_stream >> p.m_baseattributes;

    p_stream >> temp;
    p.m_items = 0;
    for (int i = 0; i < p.MaxItems(); i++)
    {
        p_stream >> p.m_inventory[i];
        if (p.m_inventory[i] != 0)
            p.m_items++;
    }

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
}

Player& Player::addPlayer(){
    ifstream file("player.txt");

    Instance = &Player::getNewPlayer();
    file >> *Instance;

    cout << "玩家" << Instance->name << "读档成功" << endl;
    return *Instance;
}

