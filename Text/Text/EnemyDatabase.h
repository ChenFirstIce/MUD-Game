#pragma once
#include "EntityDatabase.h"
#include "Enemy.h"
using namespace std;

//只用来加载用
class EnemyTemplateDatabase :public EntityDatabase<EnemyTemplate> {
public:
	static void Load();
};


class EnemyDatabase : public EntityDatabase<Enemy>
{
public:
    static void Create(entityid p_template, room p_room);//制造敌人
    static void Delete(enemy p_enemy);
    static void Load();
    static void Save();

};  