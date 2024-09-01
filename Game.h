#pragma once
#include "CommandExecutor.h"
#include "Player.h"
using namespace std;

class Game {
public:
	Game() { Load(); }
	~Game() { Save(); }

	void Save();
	void Load();

	bool First(string input);
	void Map();
	void Bag();
	void NPC();
	void PrintPrime();
};