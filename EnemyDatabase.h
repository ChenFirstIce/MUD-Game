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
    static void Create(entityid p_template, room p_room);//制造敌人并将敌人添加到房间
    static void Delete(enemy p_enemy);//从数据库中删除敌人，并从房间中移除敌人
    static void Load();//加载文档中的敌人，并添加到相应的房间
    static void Save();//保存目前m_map中的敌人到文档中

};  