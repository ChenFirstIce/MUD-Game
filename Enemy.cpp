#include "Enemy.h"
using namespace std;

EnemyTemplate::EnemyTemplate()
{
    m_hitpoints = 0;
    m_dodging = 0;
    m_strikedamage = 0;
    m_exp = 0;
    m_weapon = 0;
    m_moneymin = 0;
    m_moneymax = 0;
}

//战斗属性
int EnemyTemplate::getType() {
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

void EnemyTemplate::setType(int p_attr) {
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

//模板输入即可，不需要保存到相应文件（因为是从文件中提取的）
istream& operator>>(istream& p_stream, EnemyTemplate& t)
{
    string temp;
    int type;

    p_stream >> temp >> ws;  
    getline(p_stream, t.m_name);//名字
    p_stream >> temp >> type;//增加的
    t.setType(type);
    p_stream >> temp >> t.m_hitpoints;//血量
    p_stream >> temp >> t.m_dodging;//闪避
    p_stream >> temp >> t.m_strikedamage;//攻击力
    p_stream >> temp >> t.m_speed;
    p_stream >> temp >> t.m_exp;//经验
    p_stream >> temp >> t.m_weapon;
    p_stream >> temp >> t.m_moneymin;
    p_stream >> temp >> t.m_moneymax;

    t.m_loot.clear();
    while (extract(p_stream, temp) != "[ENDLOOT]")  //敌人物品栏的以[ENDLOOT]结束
    {
        entityid id;
        int chance;
        p_stream >> id >> chance;
        t.m_loot.push_back(loot(id, chance));
    }

    return p_stream;
}


//Enemy类
Enemy::Enemy(){
    m_template = 0;
    m_type = GRASS;
    m_hitpoints = 0;
    m_room = 0;
}

int Enemy::getType() {
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

void Enemy::setType(int p_attr) {
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

void Enemy::LoadTemplate(enemytemplate p_template){
    m_template = p_template;
    m_hitpoints = p_template->m_hitpoints;
}

//输入输出流重载
ostream& operator<<(ostream& p_stream, Enemy& t){
    p_stream << "[TEMPLATEID]     " << t.m_template << "\n";
    p_stream << "[ATTACKTYPE]     " << t.getType() << '\n';//后来增加的
    p_stream << "[HITPOINTS]      " << t.m_hitpoints << "\n";
    p_stream << "[ROOM]           " << t.m_room << "\n";
    p_stream << "\n";

    return p_stream;
}

istream& operator>>(istream& p_stream, Enemy& t)
{
    string temp;
    int type;

    p_stream >> temp >> t.m_template;
    p_stream >> temp >> type;//后来增加的
    t.setType(type);
    p_stream >> temp >> t.m_hitpoints;
    p_stream >> temp >> t.m_room;
    p_stream >> temp;   

    return p_stream;
}

