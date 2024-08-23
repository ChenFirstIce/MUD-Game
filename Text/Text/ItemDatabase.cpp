#include <bits/stdc++.h>
#include "Entity.h"
#include "ItemDatabase.h"
using namespace std;

map<entityid, Item> ItemDatabase::m_map;
ItemDatabase* ItemDatabase::Instance = nullptr;

ItemDatabase& ItemDatabase::getInstance()
{
	if (Instance == nullptr) {
		Instance = new ItemDatabase();
	}

	return *Instance;
}

bool ItemDatabase::Load()
{
	entityid id;
	string temp;
	ifstream file("items.txt");

	while (file.good()) {
		file >> temp >> id;
		m_map[id].ID() = id;
		file >> m_map[id] >> ws;
	}

	cout << "ItemDatabase Loaded successful." << endl;

	return true;
}
