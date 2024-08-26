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
    static void Create(entityid p_template, room p_room);//������˲���������ӵ�����
    static void Delete(enemy p_enemy);//�����ݿ���ɾ�����ˣ����ӷ������Ƴ�����
    static void Load();//�����ĵ��еĵ��ˣ�����ӵ���Ӧ�ķ���
    static void Save();//����Ŀǰm_map�еĵ��˵��ĵ���

};  