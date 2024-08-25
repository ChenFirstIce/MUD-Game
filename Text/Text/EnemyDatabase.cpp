#include "EnemyDatabase.h"
using namespace std;

map<entityid, EnemyTemplate> EntityDatabase<EnemyTemplate>::m_map;
map<entityid, Enemy> EntityDatabase<Enemy>::m_map;

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

void EnemyDatabase::Create(entityid p_template, room p_room){
	entityid id = findOpenID();  //查找未被使用的ID
	Enemy& e = m_map[id];        

	e.ID() = id;                   
	e.LoadTemplate(p_template);   
	e.currentRoom() = p_room;

	p_room->addEnemy(id);
}

void EnemyDatabase::Delete(enemy p_enemy){
	p_enemy->currentRoom()->removeEnemy(p_enemy);
	m_map.erase(p_item);
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
		file >> m_map[id] >> ws;
		m_map[id].currentRoom()->addEnemy(id);
	}
}

void EnemyDatabase::Save()
{
	ofstream file("enemies.txt");

	iterator itr = begin();
	while (itr != end())
	{
		file << "[ID]             " << itr->ID() << "\n";
		file << *itr << "\n";
		itr++;
	}
}