#pragma once
#include <string>
#include <vector>
using namespace std;

struct Command {
    string action;  // ���������� "move"��"attack"��"pickup"
    string argus;  // ���������� ["north"] �� ["sword"]

    Command(const string act, const string arguments)
        : action(act), argus(arguments) {}

};