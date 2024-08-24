#include "CommandExecutor.h"
#include <iostream>
using namespace std;

void CommandExecutor::execute(Player& player, const Command& cmd) {
    if (cmd.action == "move") {
        handleMove(player, cmd);
    }
    else if (cmd.action == "attack") {
        handleAttack(player, cmd);
    }
    else if (cmd.action == "pickup") {
        handlePickup(player, cmd);
    }
    else {
        cout << "ɶ��" << endl;
    }
}

void CommandExecutor::handleNew(Player& player, const Command& cmd){
    if (!cmd.args.empty()) {
        string target = cmd.args;
        cout << "Attacking " << target << endl;
        // ������غ�����ִ�й���
    }
    else {
        cout << "ɶ��" << endl;
    }
}

void CommandExecutor::handleContinue(Player& player, const Command& cmd)
{
}

void CommandExecutor::handlePick(Player& player, const Command& cmd){
    if (!cmd.args.empty()) {
        string target = cmd.args;
        cout << "pick " << target << endl;
    }
    else {
        cout << "ɶ��" << endl;
    }
}

void CommandExecutor::handleUse(Player& player, const Command& cmd){

}
