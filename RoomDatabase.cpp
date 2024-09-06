#include <fstream>
#include "RoomDatabase.h"
using namespace std;

map<entityid, Room> EntityDatabase<Room>::m_map;

void RoomDatabase::LoadTemplates(){
	ifstream file("Room.txt");
    string line;
	entityid id;
	string temp;

	while (file.good()) {
        file >> temp >> id;

		m_map[id].ID() = id;
		m_map[id].loadTemplate(file);//��������֮ǰд����
		file >> ws;
	}

    cout << "RomeDatabase Template Loaded successful." << endl;

    file.close();
}

void RoomDatabase::LoadData(string filename)
{
    ifstream file(filename);

    string temp;
    entityid roomid;

    while (file.good())
    {
        file >> temp >> roomid;

        m_map[roomid].loadData(file);
        file >> ws;
    }

    cout << "RomeDatabase Data Loaded successful." << endl;

    file.close();
}

void RoomDatabase::SaveData(){
    ofstream file("Roomthings.txt");

    iterator itr = begin();

    while (itr != end())
    {
        file << "[ROOMID] " << itr->second.ID() << "\n";
        m_map[itr->second.ID()].saveData(file);//֮ǰ���vector��
        file << "\n";

        itr++;
    }

    file.close();
}
