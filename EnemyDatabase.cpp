#include "EnemyDatabase.h"
using namespace std;

map<entityid, EnemyTemplate> EntityDatabase<EnemyTemplate>::m_map;
map<entityid, Enemy> EntityDatabase<Enemy>::m_map;

//EnemyTemplateDatabaseÀà
void EnemyTemplateDatabase::Load(){
	ifstream file("enemiesTemplate.txt");
	entityid id;
	string temp;

	while (file.good()) {
		file >> temp >> id;

		m_map[id].ID() = id;
		file >> m_map[id] >> ws;
	}
}


//EnemyDatabaseÀà
void EnemyDatabase::Create(entityid p_template, room p_room){
	entityid id = size() + 1;  
	Enemy& e = m_map[id];        

	e.ID() = id;                   
	e.LoadTemplate(p_template);   
	e.currentRoom() = p_room;

	p_room->addEnemy(id);
}

void EnemyDatabase::Delete(enemy p_enemy){
	p_enemy->currentRoom()->removeEnemy(p_enemy);
	m_map.erase(p_enemy);
}

void EnemyDatabase::Load(){
	ifstream file("enemies.txt");
	entityid id;
	string temp;

	file >> ws;    
	while (file.good())
	{
		file >> temp >> id;
		m_map[id].ID() = id;
		enemy p_enemy = id;
		file >> m_map[id] >> ws;
		m_map[id].currentRoom()->addEnemy(p_enemy);
	}
}

void EnemyDatabase::Save(){
	ofstream file("enemies.txt");

	iterator itr = begin();
	while (itr != end())
	{
		file << "[ID]             " << itr->second.ID() << "\n";
		file << itr->second << "\n";
		itr++;
	}
}