#pragma once
#include "EntityDatabase.h"
#include "NPC.h"
using namespace std;

class NPCDatabase : public EntityDatabase<NPC> {
public:
	static void Load();//�����ĵ��еĵ��ˣ�����ӵ���Ӧ�ķ���
	static void Save();//����Ŀǰm_map�еĵ��˵��ĵ���
};
