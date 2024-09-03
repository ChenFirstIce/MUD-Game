#pragma once
#include "CommandExecutor.h"
#include "EnemyDatabase.h"
#include "RoomDatabase.h"
#include "NPCDatabase.h"
#include "ItemDatabase.h"
#include "Player.h"
#include "Map.h"
#include "Story.h"
using namespace std;

class Game {
public:
	Game() { Load(); }
	~Game() { Save(); }

	void Save();
	void Load();

	bool First(string input);
	void Mape();
	void Bag();
	void NPC();
	void PrintPrime();
};