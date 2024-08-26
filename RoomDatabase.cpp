#include <fstream>
#include "RoomDatabase.h"
using namespace std;

map<entityid, Room> EntityDatabase<Room>::m_map;

void RoomDatabase::loadTemplates(){
	ifstream file("Room.txt");
	entityid id;
	string temp;

	while (file.good()) {
		file >> temp >> id;
		
		m_map[id].ID() = id;
		m_map[id].loadTemplate(file);//函数名字之前写错了
		file >> ws;
	}
}

void RoomDatabase::loadData()
{
    ifstream file("Roomthings.txt");

    string temp;
    entityid roomid;

    while (file.good())
    {
        file >> temp >> roomid;

        m_map[roomid].loadData(file);
        file >> ws;
    }
}

void RoomDatabase::saveData(){
    ofstream file("Roomthings.txt");

    iterator itr = begin();

    while (itr != end())
    {
        file << "[ROOMID] " << itr->second.ID() << "\n";
        m_map[itr->second.ID()].saveData(file);//之前打成vector了
        file << "\n";

        itr++;
    }
}
