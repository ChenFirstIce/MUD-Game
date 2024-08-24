#pragma once
#include <string>
#include <vector>
using namespace std;

struct Command {
    string action;  // ���������� "move"��"attack"��"pickup"
    string args;  // ���������� ["north"] �� ["sword"]

    Command::Command(const string& act, const string& arguments)
        : action(act), args(arguments) {}

};