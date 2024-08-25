#pragma once
#include "EntityDatabase.h"
#include "Enemy.h"
using namespace std;

//ֻ����������
class EnemyTemplateDatabase :public EntityDatabase<EnemyTemplate> {
public:
	static void Load();
};


class EnemyDatabase : public EntityDatabase<Enemy>
{
public:
    static void Create(entityid p_template, room p_room);//�������
    static void Delete(enemy p_enemy);
    static void Load();
    static void Save();

};  