#pragma once
#include "stdc++.h"
#include "EntityDatabase.h"
#include "Item.h"
using namespace std;

class ItemDatabase :public EntityDatabase<Item> {
public:
	ItemDatabase() = default;
	~ItemDatabase() = default;
	/*static ItemDatabase& getInstance();*/
	static bool Load();
private:
	/*ItemDatabase() = default;
	static ItemDatabase* Instance;*/
};