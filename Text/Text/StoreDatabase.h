#pragma once
#include "EntityDatabase.h"
#include "Store.h"
using namespace std;

class StoreDatabase :public EntityDatabase<Store> {
public:
	static bool Load();
};