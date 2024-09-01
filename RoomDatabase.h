#pragma once
#include "Room.h"
#include "EntityDatabase.h"
using namespace std;

class RoomDatabase :public EntityDatabase<Room> {
public:
	static void loadTemplates();
	static void loadData(string filename = "Roomthings.txt");
	static void saveData();
};