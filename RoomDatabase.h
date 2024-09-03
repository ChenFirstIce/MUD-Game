#pragma once
#include "Room.h"
#include "EntityDatabase.h"
using namespace std;

class RoomDatabase :public EntityDatabase<Room> {
public:
	static void LoadTemplates();
	static void LoadData(string filename = "Roomthings.txt");
	static void SaveData();
};