#pragma once
#include "Command.h"
#include <string>
using namespace std;

class CommandParser {
public:
    Command parse(const string& input);
};