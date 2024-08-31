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

	void Run();
};