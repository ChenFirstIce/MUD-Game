#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "CommandParser.h"
using namespace std;

Command CommandParser::Parse(const string& input) {
    istringstream iss(input);
    string word;
    vector<string> tokens;

    while (iss >> word) {
        tokens.push_back(word);
    }

    string action = tokens[0];
    tokens.erase(tokens.begin());

    string argus = tokens[0] + " ";
    for (auto i = tokens.begin() + 1; i != tokens.end(); i++) {
        argus += *i;
        argus += " ";
    }

    if (!argus.empty() && argus.back() == ' ') {
        argus.pop_back();
    }

    return Command(action, argus);
}
