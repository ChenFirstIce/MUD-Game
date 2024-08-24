#include <ifstream>
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
		m_map[id].LoadTemplate(file);
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
        file << "[ROOMID] " << itr->ID() << "\n";
        m_vector[itr->ID()].SaveData(file);
        file << "\n";

        itr++;
    }
}
