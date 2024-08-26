#pragma once 
#include <iostream>
#include <vector>
#include "Entity.h"
using namespace std;

//[ID]
//[]
//state
//[TALK]    1


//[EndTalk]
//take

class NPC :public Entity {
public:
	void Speak();
protected:
	int m_state;
	vector<string> m_words;
};