#include "StoreDatabase.h"
using namespace std;

map<entityid, Store> EntityDatabase<Store>::m_map;

bool StoreDatabase::Load(){
    ifstream file("stores.txt");
    entityid id;
    string temp;

    while (file.good())
    {
        file >> temp >> id;                         // load ID
        m_map[id].ID() = id;
        file >> m_map[id] >> ws;               // load store
    }
    return true;
}
