#include "NPCDatabase.h"
using namespace std;

map<entityid, NPC> EntityDatabase<NPC>::m_map;

void NPCDatabase::Load(){
	ifstream file("NPC.txt");
	entityid id;
	string temp;

	while (file.good()) {
		file >> temp >> id;

		m_map[id].ID() = id;
		file >> m_map[id] >> ws;
	}

	file.close();
}

void NPCDatabase::Save(){
	ofstream file("NPC.txt");

	iterator itr = begin();
	while (itr != end())
	{
		file << "[ID]             " << itr->second.ID() << "\n";
		file << itr->second << "\n";
		itr++;
	}

	file.close();
}
