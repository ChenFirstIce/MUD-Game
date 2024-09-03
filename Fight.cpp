#include<bits/stdc++.h>
#include "Fight.h"
using namespace std;

void Fight::ShowMe1() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<player>Me[0])->Name() << "|" << endl;
	cout << "        \t|�ȼ���" << left << setw(6) << (static_cast<player>Me[0])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << setw(6) << (static_cast<player>Me[0])->getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << setw(6) << (static_cast<player>Me[0])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------" << endl;
	cout << "\033[31m--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe2() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<player>Me[0])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<npc>Me[1])->Name() << "|" << endl;
	cout << "        \t|�ȼ���" << left << setw(6) << (static_cast<player>Me[0])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[1])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << setw(6) << (static_cast<player>Me[0])->getExp() << "|" << "\t\t\t\t|���飺" << left << setw(6) << (static_cast<npc>Me[1])->getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << setw(6) << (static_cast<player>Me[0])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<npc>Me[1])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "\033[0m";
	cout << "\033[31m--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe3() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<npc>Me[1])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<npc>Me[2])->Name() << "|" << endl;
	cout << "        \t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[1])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[2])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << setw(6) << (static_cast<npc>Me[1])->getExp() << "|" << "\t\t\t\t|���飺" << left << setw(6) << (static_cast<npc>Me[2])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<npc>Me[1])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<npc>Me[2])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "   ��   \t             \t|������" << left << setw(6) << (static_cast<player>Me[0])->Name() << "|" << endl;
	cout << "        \t             \t|�ȼ���" << left << setw(6) << (static_cast<player>Me[0])->getLevel() << "|" << endl;
	cout << "        \t             \t|���飺" << left << setw(6) << (static_cast<player>Me[0])->getExp() << "|" << endl;
	cout << "        \t             \t|��������" << left << setw(6) << (static_cast<player>Me[0])->getType() << "|" << endl;
	cout << "        \t             \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << endl;
	cout << "        \t             \t|ATTACK:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t             \t|CRITING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t             \t|DODGING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t             \t|SPEED:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "\033[0m";
	cout << "\033[31m--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe4() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<npc>Me[2])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<npc>Me[3])->Name() << "|" << endl;
	cout << "        \t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[2])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[3])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << setw(6) << (static_cast<npc>Me[2])->getExp() << "|" << "\t\t\t\t|���飺" << left << setw(6) << (static_cast<npc>Me[3])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<npc>Me[2])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<npc>Me[3])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[3])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[3])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<npc>Me[3])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<npc>Me[3])->getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << setw(6) << (static_cast<npc>Me[2])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<npc>Me[3])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << setw(6) << (static_cast<player>Me[0])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<npc>Me[1])->Name() << "|" << endl;
	cout << "        \t|�ȼ���" << left << setw(6) << (static_cast<player>Me[0])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << setw(6) << (static_cast<npc>Me[1])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << setw(6) << (static_cast<player>Me[0])->getExp() << "|" << "\t\t\t\t|���飺" << left << setw(6) << (static_cast<npc>Me[1])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<player>Me[0])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<npc>Me[1])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "\033[0m";
	cout << "\033[31m--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowEnemy1() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<enemy>Enemy[0])->Name() << "|" << endl;
	cout << "   ��   \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[0])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------" << endl;
	cout << "\033[0m";
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy2() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<enemy>Enemy[0])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<enemy>Enemy[1])->Name() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[0])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<enemy>Enemy[1])->getType() << "|" << endl;
	cout << "   ��   \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(1) << "|" << endl;
	cout << "   ��   \t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "\033[0m";
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy3() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t             \t---------------------" << endl;
	cout << "        \t             \t|������" << left << setw(6) << (static_cast<enemy>Enemy[0])->Name() << "|" << endl;
	cout << "        \t             \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[0])->getType() << "|" << endl;
	cout << "        \t             \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(0) << "|" << endl;
	cout << "        \t             \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(1) << "|" << endl;
	cout << "        \t             \t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(2) << "|" << endl;
	cout << "        \t             \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(3) << "|" << endl;
	cout << "   ��   \t             \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(4) << "|" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << setw(6) << (static_cast<enemy>Enemy[1])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<enemy>Enemy[2])->Name() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[1])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<enemy>Enemy[2])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "\033[0m";
	//cout << "--------------------------------------------------------------------------------\n\n";
}


void Fight::ShowEnemy4() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "\033[33m";
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << setw(6) << (static_cast<enemy>Enemy[0])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<enemy>Enemy[1])->Name() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[0])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<enemy>Enemy[1])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << setw(6) << (static_cast<enemy>Enemy[2])->Name() << "|" << "\t\t\t\t|������" << left << setw(6) << (static_cast<enemy>Enemy[3])->Name() << "|" << endl;
	cout << "        \t|��������" << left << setw(6) << (static_cast<enemy>Enemy[2])->getType() << "|" << "\t\t\t\t|��������" << left << setw(6) << (static_cast<enemy>Enemy[3])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << setw(6) << (static_cast<enemy>Enemy[3])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << setw(6) << (static_cast<enemy>Enemy[3])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << setw(6) <<(static_cast<enemy>Enemy[2])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << setw(6) << (static_cast<enemy>Enemy[3])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << setw(6) << (static_cast<enemy>Enemy[3])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[2])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << setw(6) << (static_cast<enemy>Enemy[3])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "\033[0m";
	//cout << "--------------------------------------------------------------------------------\n\n";
}

Fight::Fight(Player* m_player) {
	int i, j;
	m_room = m_player->currentRoom();

	Me.push_back(0);

	//�����ҷ���Ӫ
	list<npc>::iterator npcitr = m_player->Npces().begin();
	while (npcitr != m_player->Npces().end()) {
		Me.push_back((*npcitr));
		npcitr++;
	}

	//����˳�������ҷ���Ӫ
	for (i = 1; i < Me.size(); i++) {
		npc temp = Me[i];
		for (j = i - 1; j >= 0; j--) {
			npc m_npc = Me[j];
			if (temp->getAttr(SPEED) < m_npc->getAttr(SPEED)) {
				Me[j + 1] = Me[j];
			}
		}
		Me[j + 1] = temp;
	}

	//��Ů����ǰ�ţ��׵����г�
	Me.push_front(0);

	//������з���Ӫ
	list<enemy>::iterator enemyitr = m_room->Enemies().begin();
	while (enemyitr != m_room->Enemies().end()) {
		Enemy.push_back((*enemyitr));
		enemyitr++;
	}

	//�з���Ӫ����
	for (i = 1; i < Enemy.size(); i++) {
		enemy temp = Enemy[i];
		for (j = i - 1; j >= 0; j--) {
			enemy m_enemy = Enemy[j];
			if (temp->getAttr(SPEED) < m_enemy->getAttr(SPEED)) {
				Enemy[j + 1] = Enemy[j];
			}
		}
		Enemy[j + 1] = temp;
	}


}

void Fight::Turn()//0-2*n-1���δ����ҷ�nֻ���顢�з�nֻ���飻��ά����ÿ����Ԫ��һ����������ţ��ڶ�����Ӧ�����ٶ�
{
	int n = Me.size();
	int m = Enemy.size();
	vector<vector<int>> BattleTurn;
	int t[2];

	BattleTurn.resize(n + m);

	for (int i = 0; i < n + m; ++i) {
		BattleTurn[i].resize(2);
	}

	for (int i = 0; i < n; i++) {
		BattleTurn[i][0] = Me[i];
		if (M[i] == 0) {
			BattleTurn[i][1] = m_player->getAttr(SPEED);
		}
		else {
			npc m_npc = Me[i];
			BattleTurn[i][1] = m_npc->getAttr(SPEED);
		}
	}

	for (int i = n; i < m + n; i++) {
		enemy m_enemy = Enemy[i];
		BattleTurn[i][0] = Enemy[i];
		BattleTurn[i][1] = m_enemy->Speed();
	}

	for (int j = 0; j < n + m - 1; j++) {
		for (int i = 0; i < n + m - 1 - j; i++) {
			if (BattleTurn[i][1] < BattleTurn[i + 1][1]) {
				t[0] = BattleTurn[i][0];
				t[1] = BattleTurn[i][1];
				BattleTurn[i][0] = BattleTurn[i + 1][0];
				BattleTurn[i][1] = BattleTurn[i + 1][1];
				BattleTurn[i + 1][0] = t[0];
				BattleTurn[i + 1][1] = t[1];
			}
		}
	}

	for (int i = 0; i < n + m; i++) {
		Turn.push_back(BattleTurn[i][0]);
	}
}

//�жϵ��˵�ǰ�Ų����빥������
int Fight::Front1() {
	int n = Enemy.size() / 2;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		enemy m_enemy = Enemy[i];
		if (m_enemy->hitPoints() > 0) {
			cnt++;
			targets.push_back(m_enemy);
		}
	}

	return cnt;
}
//�ж��ҷ���ǰ�Ų����빥������
int Fight::Front2() {
	int n = Me.size() / 2;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (Me[i] == 0) {
			if (m_player->HitPoints() > 0) {
				cnt++;
				targets.push_back(0);
			}
		}
		else {
			npc m_npc = Me[i];
			if (m_npc->HitPoints() > 0) {
				cnt++;
				targets.push_back(m_npc);
			}
		}

	}

	return cnt;
}

//�жϵ�ǰ�������Ƿ���
bool Fight::isLive(int id) {
	if (id == 0) {
		if (m_player->HitPoints() <= 0) {
			medie++;
			return false;
		}
	}
	else if (id < 4) {
		npc m_npc = id;
		if (m_npc->HitPoints() <= 0) {
			return false;
			medie++;
		}
	}
	else {
		enemy m_enemy = id;
		if (m_enemy->HitPoints() <= 0) {
			endie++;
			return false;
		}
	}
	return true
}

int Fight::Choice(int Round, int atk) {
	int choose;

	if (atk == 0) {
		Player* patk = m_player;
	}
	else {
		npc patk = atk;
	}

	while (1) {
		cout << " " << patk->Name() << " Ҫ��ʲô��" << endl;
		cout << "1.����  2.ʹ�õ��� 3.����" << endl;
		cin >> choose;
		if (choose < 1 || choose>3) {
			cout << "�������������룡" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else {
			return choose;
		}

	}
}

int Fight::Restrain1(int p_atk, int p_target)//����ֵ0Ϊ������������, 1Ϊ���������Ʊ�������, -1Ϊ�޿��ƹ�ϵ
//����0�������У�1����2��2����3��3����1 
{
	if (p_atk == 0) {
		Player* atk = Player::getPlayer();
	}
	else {
		npc atk = p_atk;
	}

	enemy target = p_target;

	if (atk->getType() == "LIGHT") {
		return 1;
	}
	else if (atk->getType() == "GOLD") {
		if (target->getType() == "GOLD") return -1;
		else if (target->getType() == "FIRE") return 1;
		else if (target->getType() == "GRASS") return 0;
	}
	else if (atk->getType() == "FIRE") {
		if (target->getType() == "GOLD") return 0;
		else if (target->getType() == "FIRE") return -1;
		else if (target->getType() == "GRASS") return 1;
	}
	else if (atk->getType() == "GRASS") {
		if (target->getType() == "GOLD") return 1;
		else if (target->getType() == "FIRE") return 0;
		else if (target->getType() == "GRASS") return -1;
	}
}

int Fight::Restrain2(int p_atk, int p_target)//����ֵ0Ϊ������������, 1Ϊ���������Ʊ�������, -1Ϊ�޿��ƹ�ϵ
//����0�������У�1����2��2����3��3����1 
{
	if (p_target == 0) {
		Player* target = Player::getPlayer();
	}
	else {
		npc target = p_target;
	}

	enemy atk = p_atk;

	if (atk->getType() == "LIGHT") {
		return 1;
	}
	else if (atk->getType() == "GOLD") {
		if (target->getType() == "GOLD") return -1;
		else if (target->getType() == "FIRE") return 1;
		else if (target->getType() == "GRASS") return 0;
	}
	else if (atk->getType() == "FIRE") {
		if (target->getType() == "GOLD") return 0;
		else if (target->getType() == "FIRE") return -1;
		else if (target->getType() == "GRASS") return 1;
	}
	else if (atk->getType() == "GRASS") {
		if (target->getType() == "GOLD") return 1;
		else if (target->getType() == "FIRE") return 0;
		else if (target->getType() == "GRASS") return -1;
	}
}

//����
//�ҷ������з�
void Fight::Atk1(int atk, int target) {
	if (!isLive(target)) {
		return;
	}

	//�ж�����
	if (atk == 0) {
		Player* p_atk = m_player;
	}
	else {
		npc p_atk = atk;
	}

	enemy p_enemy = target;

	if (rand() % 100 <= p_enemy->Dodging()) {
		//cout << "\033[33m";
		cout << p_atk->Name() << " ������ " << p_enemy->Name();
		cout << "�� \033[31m���� " << p_enemy->Name() << " �㿪�˹���!" << endl;
		cout << "\033[0m";
		system("pause");
	}
	else {
		double hurt;
		hurt = p_atk->geAttr(ATTACK);
		//cout << "\033[32m";
		cout << p_atk->Name() << " ������ " << p_enemy->Name() << " , ";
		if (rand() % 100 <= p_atk->getAttr(CRITING)) {
			hurt *= 2;
			cout << "\033[32m������Ҫ��! ";
		}
		if (Restrain1(atk, target) == 1) {
			hurt *= 1.5;
			cout << "\033[32mЧ����Ⱥ! ";
		}
		else if (Restrain1(atk, target) == 0) {
			hurt *= 0.5;
			cout << "\033[33m��Ч��΢����";
		}
		cout << "\033[0m";
		cout << " ����� " << hurt << " ���˺���";
		p_enemy->HitPoints() -= hurt;

		system("pause");
	}
}

//�з������ҷ�
void Fight::Atk2(int atk, int target) {
	if (!isLive(target)) {
		return;
	}

	enemy p_atk = atk;

	//�ж�����
	if (target == 0) {
		Player* p_target = m_player;
	}
	else {
		npc p_target = target;
	}

	if (rand() % 100 <= p_target->getAttr(DODGING)) {
		cout << p_atk->Name() << " ������ " << p_target->Name();
		cout << "�� ���� \033[31m" << p_target->Name() << " �㿪�˹���!" << endl;
		system("pause");
	}
	else {
		double hurt;

		hurt = p_atk->StrikeDamage();
		cout << p_atk->Name() << " ������ " << p_target->Name() << " , ";

		if (Restrain2(atk, target) == 1) {
			hurt *= 1.5;
			cout << "\033[32mЧ����Ⱥ! ";
		}
		else if (Restrain2(atk, target) == 0) {
			hurt *= 0.5;
			cout << "\033[33m��Ч��΢����";
		}
		cout << "\033[0m��Ч��΢";
		cout << " ����� " << hurt << " ���˺���";
		p_target->HitPoints() -= hurt;

		system("pause");
	}
}

void Fight::AttackTurn(int atk, int& Round) {
	int targetnum = 1;
	int choose = 0;
	int n = 0;//��������ѡ���������β����
	int front = 0;//��������ѡ���������

	if (atk < 4) {

		//�ж�����һ�������
		if (atk == 0) {
			Player* patk = m_player;
			targetnum = 1;
		}
		else {
			npc patk = atk;
			targetnum = patk->getTarget();
		}

		cout << "�ɹ�������Ϊ��" << targetnum << endl;

		front = Front1();

		if (front == targetnum) {//ǰ������(�Ѿ��Զ���ǰ�����빥������
			cout << "�Ѿ�����ǰ�ţ�";
			for (int i = 0; i < front; i++) {
				cout << (static_cast<enemy>targets[i])->Name() << "  ";
			}
			cout << endl;
		}
		else
		{
			if (front > targetnum) {//ѡ��ǰ��
				targets.clear();//��պ���ǰ�ŵĹ�������

				front = 0;
				n = Enemy.size() / 2;
			}
			else {
				n = Enemy.size();
			}

			if (targets.size() > 0) {
				cout << "�Ѿ�����ǰ�ţ�";
				for (int i = 0; i < front; i++) {
					cout << (static_cast<enemy>targets[i])->Name() << "  ";
				}
				cout << endl;
			}

			//δȫ������
			//�������ѡ��ĵ���
			cout << "Ҫ����˭��(����ѡ�񻷽�)" << endl;//ѡ�񹥻�˭
			for (int i = front; i < n; i++) {
				if (isLive(Enemy[i])) {
					cout << "ID:" << left << setw(3) << i + 1 << "   Name:" << (static_cast<enemy>Enemy[i])->Name() << endl;
					cout << endl;
				}
			}

			//ѡ�񹥻��ĵ���
			for (int i = 0; i < targetnum - targets.size(); i++) {
				cout << "������ID������0��ȡ������)" << endl;
				cout << "> ";
				cin >> choose;

				while (choose < front + 1 || choose > n || !isLive(Enemy[choose - 1])) {//������������ + 1
					if (choose == 0) {
						Round--;
						return;
					}

					cout << "\033[31m�������������룡\033[0m" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());

					cin >> choose;
				}

				targets.push_back(Enemy[choose - 1]);
				cout << (static_cast<enemy>Enemy[choose - 1])->Name() << "�Ѽ��빥������";

				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
		}
		for (int i = 0; i < targetnum; i++) {
			Atk1(patk, targets[i]);
		}
	}
	else {
		enemy patk = atk;
		targetnum = patk->getTarget();

		cout << "�ɹ�������Ϊ��" << targetnum << endl;

		for (int i = 0; i < Me.size(); i++) {
			if (isLive(Me[i])) {
				targets.push_back(Me[i]);

				if (targets.size() == targetnum) {
					break;
				}

			}
		}

		for (int i = 0; i < targetnum; i++) {
			Atk2(patk, targets[i]);
		}
	}
}

void Fight::UseMedical(int atk, int& Round) {
	int choose = 0;

	system("cls");

	cout << "-------------------------------- ��ı��� --------------------------------" << endl;
	cout << " ID:  |ҩƷ:" << endl;

	for (int i = 0; i < m_player->Items(); i++)
	{
		if (m_player->getItem(i)->Type() == HEALING) {
			cout << left << setw(2) << i + 1 << "  |" << m_player->getItem(i)->Name() << endl;
		}
	}

	cout << "---------------------------------------------------------------------------" << endl;

	cout << "��ѡ��Ҫʹ�õ�ҩƷ��ID(����0��ȡ������)" << endl;
	cout << "< ";
	cin >> choose;

	while (choose < 1 || choose > m_player->Items() || m_player->getItem(choose - 1)->Type() != HEALING) {//������������+1
		if (choose == 0) {
			Round--;
			return;
		}

		cout << "\033[31m�������������룡\033[0m" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		cin >> choose;
	}

	if (atk == 0) {
		m_player->useHealing(choose - 1);
	}
	else {
		npc m_atk = atk;
		m_atk->usdHealing(m_player->getItem(choose - 1));
	}

	m_player->dropItem(choose - 1);
}

bool Fight::isWin() {
	int cnt = 0;

	for (int i = 0; i < Enemy.size(); i++) {
		if (!isLive(Enemy[i])) {
			cnt++;
		}
	}

	if (cnt == Enemy.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Fight::isLose() {
	int cnt = 0;

	for (int i = 0; i < Me.size(); i++) {
		if (!isLive(Me[i])) {
			cnt++;
		}
	}

	if (cnt == Me.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}

void Fight::ProceedFight()
{
	int total = Turn.size();
	int choose;
	int Round = 0;
	bool isWin = false;
	bool isLose = false;
	Turn();//�������˳��
	while (1) {
		int atk = Turn[0];
		if (!isLive(atk)) {//������pop��Turn����
			Turn.pop_front();
			total--;
			continue;
		}

		system("cls");
		cout << endl << "\t\t\t\t\t   ��ǰ�غϣ�" << Round + 1;
		ShowBattle();

		if (atk < 4) {//���ҷ�����
			choose = Choice(Round, atk);//ѡ�����

			if (choose == 1) {
				AttackTurn(atk, Round);
			}
			else if (choose == 2) {
				UseMedical(atk, Round);
			}
			else if (choose == 3) {
				if (rand() % 10 < 8) {
					cout << "\033[32m���ܳɹ���\033[0m" << endl;
					break;
				}
				else {
					cout << "\033[31m����ʧ�ܣ�\033[0m" << endl;
					Round--;
				}
			}
			if (isWin()) {
				addTrophy();
				break;
			}
		}
		else {
			AttackTurn(atk);
			if (isLose()) {
				loseEXP();
				break;
			}
		}

		Turn.pop_front();
		Turn.push_back(atk);

		Round++;
		targets.clear();
	}

	Resite();
}

void Fight::addTrophy() {
	int money = 0;
	int exp = 0;

	system("cls");
	cout << "\033[32m";
	cout << "    11111111111111111111111 111111111  11111       1111111" << endl;
	cout << "    11111111111111111111111 1111111     11111        11111" << endl;
	cout << "     1111   111   11    11     111        1111        11" << endl;
	cout << "      111   1111  11    1      111        11111       11" << endl;
	cout << "      111    111 11    11      111        111111      11" << endl;
	cout << "       111   111 11    11      111        111111      11" << endl;
	cout << "       111    1111     1       111        11 1111     11" << endl;
	cout << "       1111   1111    11       111        11  1111    11" << endl;
	cout << "        111    111    1        111        11   1111   11" << endl;
	cout << "        111    111   11        111        11    1111  11" << endl;
	cout << "         111  11111  11        111        11     1111 11" << endl;
	cout << "         111  11111  1         111        11      111111" << endl;
	cout << "         111111 111111         111        11       11111" << endl;
	cout << "          11111  11111         111        11        1111" << endl;
	cout << "          1111   1111          111        11         111" << endl;
	cout << "           111    111       111111111    111111       11" << endl;
	cout << "           11     11        111111111  11111111        1" << endl;
	cout << "           11      1 " << endl;
	cout << "\033[0m";
	cout << "��ϲ���:" << endl;
	for (int i = 0; i < Enemy.size(); i++) {
		enemy p_enemy = Enemy[i];

		list<loot>::iteratror itm = p_enemy->LootList().begin();
		while (itm != p_enemy->LootList().end()) {
			if (rand() % 100 <= (*itm).second) {
				m_player->pickItem((*itm).first);
				cout << (*itm).first->Name() << " ";
			}
			itm++;
		}
	}

	for (int i = 0; i < Enemy.size(); i++) {
		enemy p_enemy = Enemy[i];

		money += p_enemy->MoneyMin() + rand() % (p_enemy->MoneyMax() - p_enemy->MoneyMin());
		exp += p_enemy->Exp();
	}

	m_player->addExp(exp);

	for (int i = 1; i < Me.size(); i++) {
		npc m_npc = Me[i];

		m_npc->addExp(exp);
	}

	m_player->Money() += money;
	cout << "�� " << money << endl;

	cout << "��þ���EXP:" << left << setw(4) << exp;
}

void Fight::loseEXP() {
	system("cls");
	cout << "\033[33m";
	cout << "        ???       ???????  ?????  ?????????????" << endl;
	cout << "     ????????       ?????    ??   ?????????????" << endl;
	cout << "    ???     ??      ???      ??   ??   ???   ??" << endl;
	cout << "   ???       ??     ???      ??   ?    ???   ??" << endl;
	cout << "   ??        ???    ???      ??        ???" << endl;
	cout << "  ???         ??    ???      ??        ???" << endl;
	cout << "  ???         ??    ???      ??        ???" << endl;
	cout << "  ???         ??    ???      ??        ???" << endl;
	cout << "  ???         ??    ???      ??        ???" << endl;
	cout << "  ???         ??    ???      ??        ???" << endl;
	cout << "   ??        ???    ???      ??        ???" << endl;
	cout << "   ???       ??     ???     ??         ???" << endl;
	cout << "    ???     ??       ?????????         ???" << endl;
	cout << "      ???????          ?????         ???????" << endl;
	cout << "\033[0m";
	int exp = m_player->Exp();
	m_player->Exp() -= exp * 0.2;
}

void Fight::Resite() {
	m_player->HitPoints() = m_player->getAttr(MAXHITPOINTS);

	for (int i = 1; i < Me.size(); i++) {
		npc m_npc = Me[i];
		m_npc->HitPoints() = m_npc->getAttr(MAXHITPOINTS);
	}
}