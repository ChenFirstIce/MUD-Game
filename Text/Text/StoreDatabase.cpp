#include <fstream>
#include "StoreDatabase.h"
#include "Store.h"
using namespace std;

map<entityid, Store> EntityDatabase<Store>::m_map;

bool StoreDatabase::Load(){
    ifstream file("stores.txt");     //存储商店的
    entityid id;
    string temp;

    while (file.good())
    {
        file >> temp >> id;          //商店的ID
        m_map[id].ID() = id;
        file >> m_map[id] >> ws;     //加载商店内容
    }
    return true;
}
