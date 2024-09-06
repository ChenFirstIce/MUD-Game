#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "CommandParser.h"
using namespace std;

Command CommandParser::Parse(const string& input) {
    stringstream iss(input);
    string word;
    vector<string> tokens;
    string argus;

    while (iss >> word) {
        tokens.push_back(word);
    }

    if (tokens.empty()) {
        return Command("", "");
    }

    string action = tokens[0];
    tokens.erase(tokens.begin());

    if (tokens.empty()) {
        return Command(action, "");
    }

    for (auto i = tokens.begin(); i != tokens.end(); i++) {
        argus += *i;
        argus += " ";
    }

    if (!argus.empty() && argus.back() == ' ') {
        argus.pop_back();
    }

    return Command(action, argus);
}
