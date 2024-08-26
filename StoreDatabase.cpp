#include <fstream>
#include "StoreDatabase.h"
#include "Store.h"
using namespace std;

map<entityid, Store> EntityDatabase<Store>::m_map;

bool StoreDatabase::Load(){
    ifstream file("stores.txt");     //�洢�̵��
    entityid id;
    string temp;

    while (file.good())
    {
        file >> temp >> id;          //�̵��ID
        m_map[id].ID() = id;
        file >> m_map[id] >> ws;     //�����̵�����
    }
    return true;
}
