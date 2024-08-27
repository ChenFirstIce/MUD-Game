#pragma once
#include "EntityDatabase.h"
#include "NPC.h"
using namespace std;

class NPCDatabase : public EntityDatabase<NPC> {
public:
	static void Load();//加载文档中的敌人，并添加到相应的房间
	static void Save();//保存目前m_map中的敌人到文档中
};
