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

//模板输入即可，不需要保存到相应文件（因为是从文件中提取的）
istream& operator>>(istream& p_stream, EnemyTemplate& t)
{
    std::string temp;

    p_stream >> temp >> ws;  
    getline(p_stream, t.m_name);
    p_stream >> temp >> t.m_hitpoints;
    p_stream >> temp >> t.m_dodging;
    p_stream >> temp >> t.m_strikedamage;
    p_stream >> temp >> t.m_exp;
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

Enemy::Enemy(){
    m_template = 0;
    m_hitpoints = 0;
    m_room = 0;
}

void Enemy::LoadTemplate(enemytemplate p_template){
    m_template = p_template;
    m_hitpoints = p_template->m_hitpoints;
}

//输入输出流重载
ostream& operator<<(ostream& p_stream, Enemy& t){
    p_stream << "[TEMPLATEID]     " << t.m_template << "\n";
    p_stream << "[HITPOINTS]      " << t.m_hitpoints << "\n";
    p_stream << "[ROOM]           " << t.m_room << "\n";
    p_stream << "\n";

    return p_stream;
}

istream& operator>>(istream& p_stream, Enemy& t)
{
    string temp;

    p_stream >> temp >> t.m_template;
    p_stream >> temp >> t.m_hitpoints;
    p_stream >> temp >> t.m_room;
    p_stream >> temp;   

    return p_stream;
}

