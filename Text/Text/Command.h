#pragma once
#include <string>
#include <vector>
using namespace std;

struct Command {
    string action;  // 动作，例如 "move"、"attack"、"pickup"
    string args;  // 参数，例如 ["north"] 或 ["sword"]

    Command::Command(const string& act, const string& arguments)
        : action(act), args(arguments) {}

};