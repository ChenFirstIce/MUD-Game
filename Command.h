#pragma once
#include <string>
#include <vector>
using namespace std;

struct Command {
    string action;  // 动作，例如 "move"、"attack"、"pickup"
    string argus;  // 参数，例如 ["north"] 或 ["sword"]

    Command(const string act, const string arguments)
        : action(act), argus(arguments) {}

};