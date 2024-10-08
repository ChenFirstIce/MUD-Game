#include "stdc++.h"
#include "Fight.h"
using namespace std;

Fight::Fight(Player* m_player):m_player(m_player){
	int i, j;

	m_room = m_player->currentRoom();

	//输入我方阵营
	list<npc>::iterator npcitr = m_player->Npces().begin();
	while (npcitr != m_player->Npces().end()) {
		Me.push_back((*npcitr));
		npcitr++;
	}

	//根据顺序重组我方阵营
	for (i = 1; i < Me.size(); i++) {
		npc temp = Me[i];
		for (j = i - 1; j >= 0; j--) {
			npc m_npc = Me[j];
			if (temp->getAttr(SPEED) < m_npc->getAttr(SPEED)) {
				Me[j + 1] = Me[j];
				break;
			}
		}
		Me[j + 1] = temp;
	}

	//大女主当前排，首当其中冲
	Me.insert(Me.begin(), 0);

	//把输入敌方阵营
	list<enemy>::iterator enemyitr = m_room->Enemies().begin();
	while (enemyitr != m_room->Enemies().end()) {
		Enemy.push_back((*enemyitr));
		enemyitr++;
	}

	//敌方阵营排序
	for (i = 1; i < Enemy.size(); i++) {
		enemy temp = Enemy[i];
		for (j = i - 1; j >= 0; j--) {
			enemy m_enemy = Enemy[j];
			if (temp->Speed() > m_enemy->Speed()) {
				Enemy[j + 1] = Enemy[j];
			}
			else {
				break;
			}
		}
		Enemy[j + 1] = temp;
	}
}

void Fight::ShowMe1() {
	//cout << "---------------------------------- 玩家信息 ----------------------------------" << endl;
	cout << endl;
	cout << "        \t\t\t _____________________________________" << endl;
	cout << "        \t\t\t|" << left << setw(14)  <<"姓名：" << left << setw(23) << static_cast<player>(Me[0])->Name() << "| " << endl;
	cout << "        \t\t\t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<player>(Me[0])->Level() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<player>(Me[0])->Exp() << "|" << endl;
	cout << "   我   \t\t\t|" << left << setw(14) << "攻击属性：" << left << setw(23) << static_cast<player>(Me[0])->getType() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<player>(Me[0])->HitPoints() <<"/" << left << setw(19) << static_cast<player>(Me[0])->getAttr(0) << "|" << endl;
	cout << "   方   \t\t\t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t\t\t|_____________________________________|" << endl<<endl;
	//cout << "--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe2() {
	//cout << "---------------------------------- 玩家信息 ----------------------------------" << endl;
	cout <<endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "        |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<player>(Me[0])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[1])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "等级：" << left << setw(23) << static_cast<player>(Me[0])->Level() << "|" << "\t \t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[1])->Level() << "|" << endl;
	cout << "        |" << left << setw(14) << "经验：" << left << setw(23) << static_cast<player>(Me[0])->Exp() << "|" << "\t \t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[1])->Exp() << "|" << endl;
	cout << "   我   |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<player>(Me[0])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[1])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<player>(Me[0])->HitPoints() << "/" << left << setw(19) << static_cast<player>(Me[0])->getAttr(0) << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[1])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[1])->getAttr(0) << "|" << endl;
	cout << "   方   |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(1) << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(1) << "|" << endl;
	cout << "        |" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(2) << "|" << "\t \t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(2) << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(3) << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(3) << "|" << endl;
	cout << "        |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(4) << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(4) << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl<<endl;
	//cout << "--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe3() {
	//cout << "---------------------------------- 玩家信息 ----------------------------------" << endl;
	cout << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "        |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[1])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[2])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[1])->Level() << "|" << "\t \t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[2])->Level() << "|" << endl;
	cout << "        |" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[1])->Exp() << "|" << "\t \t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[2])->Exp() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[1])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[2])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[1])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[1])->getAttr(0) << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[2])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[2])->getAttr(0) << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(1) << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(1) << "|" << endl;
	cout << "        |" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(2) << "|" << "\t \t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(2) << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(3) << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(3) << "|" << endl;
	cout << "   我   |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(4) << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(4) << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	cout << "        \t\t\t _____________________________________" << endl;
	cout << "   方   \t\t\t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<player>(Me[0])->Name() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<player>(Me[0])->Level() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<player>(Me[0])->Exp() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<player>(Me[0])->getType() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<player>(Me[0])->HitPoints() << "/" << left << setw(19) << static_cast<player>(Me[0])->getAttr(0) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t\t\t|_____________________________________|" << endl<<endl;
	//cout << "--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowMe4() {
	//cout << "---------------------------------- 玩家信息 ----------------------------------" << endl;
	cout << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "        |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[2])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[3])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[2])->Level() << "|" << "\t \t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[3])->Level() << "|" << endl;
	cout << "        |" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[2])->Exp() << "|" << "\t \t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[3])->Exp() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[2])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[3])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[2])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[2])->getAttr(0) << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[3])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[3])->getAttr(0) << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(1) << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[3])->getAttr(1) << "|" << endl;
	cout << "        |" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(2) << "|" << "\t \t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[3])->getAttr(2) << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(3) << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[3])->getAttr(3) << "|" << endl;
	cout << "   我   |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[2])->getAttr(4) << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[3])->getAttr(4) << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "   方   |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<player>(Me[0])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<npc>(Me[1])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "等级：" << left << setw(23) << static_cast<player>(Me[0])->Level() << "|" << "\t \t|" << left << setw(14) << "等级：" << left << setw(23) << static_cast<npc>(Me[1])->Level() << "|" << endl;
	cout << "        |" << left << setw(14) << "经验：" << left << setw(23) << static_cast<player>(Me[0])->Exp() << "|" << "\t \t|" << left << setw(14) << "经验：" << left << setw(23) << static_cast<npc>(Me[1])->Exp() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<player>(Me[0])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<npc>(Me[1])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<player>(Me[0])->HitPoints() << "/" << left << setw(19) << static_cast<player>(Me[0])->getAttr(0) << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<npc>(Me[1])->HitPoints() << "/" << left << setw(19) << static_cast<npc>(Me[1])->getAttr(0) << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(1) << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(1) << "|" << endl;
	cout << "        |" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(2) << "|" << "\t \t|" << left << setw(14) << "CRITING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(2) << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(3) << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(3) << "|" << endl;
	cout << "        |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<player>(Me[0])->getAttr(4) << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<npc>(Me[1])->getAttr(4) << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl<<endl;
	//cout << "--------------------------------------------------------------------------------\033[0m\n\n";
}

void Fight::ShowEnemy1() {
	//cout << "---------------------------------- 敌方信息 ----------------------------------" << endl;
	cout << "        \t\t\t _____________________________________" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[0])->Name() << "|" << endl;
	cout << "   敌   \t\t\t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[0])->getType() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[0])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[0])->MaxHitPoints() << "|" << endl;
	cout << "   方   \t\t\t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[0])->StrikeDamage() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Dodging() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Speed() << "|" << endl;
	cout << "        \t\t\t|_____________________________________|" << endl;
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy2() {
	//cout << "---------------------------------- 敌方信息 ----------------------------------" << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "        |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[0])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[1])->Name() << "|" << endl;
	cout << "   敌   |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[0])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[1])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[0])->HitPoints() <<"/"<<left<<setw(19)<< static_cast<enemy>(Enemy[0])->MaxHitPoints() << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[1])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[1])->MaxHitPoints() << "|" << endl;
	cout << "   方   |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[0])->StrikeDamage() << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[1])->StrikeDamage() << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Dodging() << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Dodging() << "|" << endl;
	cout << "        |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Speed() << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Speed() << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy3() {
	//cout << "---------------------------------- 敌方信息 ----------------------------------" << endl;
	cout << "        \t\t\t _____________________________________" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[0])->Name() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[0])->getType() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[0])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[0])->MaxHitPoints() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[0])->StrikeDamage() << "|" << endl;
	cout << "        \t\t\t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Dodging() << "|" << endl;
	cout << "   敌   \t\t\t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Speed() << "|" << endl;
	cout << "        \t\t\t|_____________________________________|" << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "   方   |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[1])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[2])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[1])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[2])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[1])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[1])->MaxHitPoints() << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[2])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[2])->MaxHitPoints() << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[1])->StrikeDamage() << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[2])->StrikeDamage() << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Dodging() << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[2])->Dodging() << "|" << endl;
	cout << "        |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Speed() << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[2])->Speed() << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	//cout << "--------------------------------------------------------------------------------\n\n";
}


void Fight::ShowEnemy4() {
	//cout << "---------------------------------- 敌方信息 ----------------------------------" << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "        |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[0])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[1])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[0])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[1])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[0])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[0])->MaxHitPoints() << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[1])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[1])->MaxHitPoints() << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[0])->StrikeDamage() << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[1])->StrikeDamage() << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Dodging() << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Dodging() << "|" << endl;
	cout << "   敌   |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[0])->Speed() << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[1])->Speed() << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	cout << "         _____________________________________\t \t _____________________________________" << endl;
	cout << "   方   |" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[2])->Name() << "|" << "\t \t|" << left << setw(14) << "姓名：" << left << setw(23) << static_cast<enemy>(Enemy[3])->Name() << "|" << endl;
	cout << "        |" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[2])->getType() << "|" << "\t \t|" << left << setw(14) << "攻击属性" << left << setw(23) << static_cast<enemy>(Enemy[3])->getType() << "|" << endl;
	cout << "        |" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[2])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[2])->MaxHitPoints() << "|" << "\t \t|" << left << setw(14) << "HITPOINTS:" << left << setw(3) << static_cast<enemy>(Enemy[3])->HitPoints() << "/" << left << setw(19) << static_cast<enemy>(Enemy[3])->MaxHitPoints() << "|" << endl;
	cout << "        |" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[2])->StrikeDamage() << "|" << "\t \t|" << left << setw(14) << "ATTACK:" << left << setw(23) << static_cast<enemy>(Enemy[3])->StrikeDamage() << "|" << endl;
	cout << "        |" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[2])->Dodging() << "|" << "\t \t|" << left << setw(14) << "DODGING:" << left << setw(23) << static_cast<enemy>(Enemy[3])->Dodging() << "|" << endl;
	cout << "        |" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[2])->Speed() << "|" << "\t \t|" << left << setw(14) << "SPEED:" << left << setw(23) << static_cast<enemy>(Enemy[3])->Speed() << "|" << endl;
	cout << "        |_____________________________________|\t \t|_____________________________________|" << endl;
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::BattleTurn()//0-2*n-1依次代表我方n只精灵、敌方n只精灵；二维数组每个单元第一个存上述编号，第二格存对应精灵速度
{
	int n = Me.size();
	int m = Enemy.size();
	vector<vector<int>> BattleTurn;

	BattleTurn.resize(n + m);

	for (int i = 0; i < n + m; ++i) {
		BattleTurn[i].resize(2);
	}

	for (int i = 0; i < n; i++) {
		BattleTurn[i][0] = Me[i];
		if (Me[i] == 0) {
			BattleTurn[i][1] = m_player->getAttr(SPEED);
		}
		else {
			npc m_npc = Me[i];
			BattleTurn[i][1] = m_npc->getAttr(SPEED);
		}
	}

	for (int i = n; i < m + n; i++) {
		enemy m_enemy = Enemy[i - n];
		cout << m_enemy->Name();
		BattleTurn[i][0] = m_enemy;
		BattleTurn[i][1] = m_enemy->Speed();
	}

	for (int j = 0; j < n + m; j++) {
		for (int i = 0; i < n + m - j - 1; i++) {  // 修改循环范围，减少多余的比较
			if (BattleTurn[i][1] < BattleTurn[i + 1][1]) {
				swap(BattleTurn[i][0], BattleTurn[i + 1][0]);
				swap(BattleTurn[i][1], BattleTurn[i + 1][1]);
			}
		}
	}

	for (int i = 0; i < n + m; i++) {
		Turn.push_back(BattleTurn[i][0]);
	}
}

void Fight::ShowBattle(){
	switch (Me.size()) {
	case 1:
		ShowMe1();
		break;
	case 2:
		ShowMe2();
		break;
	case 3:
		ShowMe3();
		break;
	case 4:
		ShowMe4();
		break;
	default: 
		break;
	}

	switch (Enemy.size()) {
	case 1:
		ShowEnemy1();
		break;
	case 2:
		ShowEnemy2();
		break;
	case 3:
		ShowEnemy3();
		break;
	case 4:
		ShowEnemy4();
		break;
	default:
		break;
	}
}


//判断敌人的前排并加入攻击队列
int Fight::Front1() {
	int n = Enemy.size() / 2;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		enemy m_enemy = Enemy[i];
		if (m_enemy->HitPoints() > 0) {
			cnt++;
			targets.push_back(m_enemy);
		}
	}

	return cnt;
}
//判断我方的前排并加入攻击队列
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

//判断当前攻击者是否存活
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
	return true;
}

int Fight::Choice(int& Round, int atk) {
	int choose;

	if (atk == 0) {
		Player* patk = m_player;

		while (1) {
			cout << " " << patk->Name() << " 要做什么？" << endl;
			cout << "1.攻击  2.使用道具 3.逃跑" << endl;
			cin >> choose;
			if (choose < 1 || choose>3) {
				cout << "错误！请重新输入！" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			else {
				return choose;
			}

		}
	}
	else {
		npc patk = atk;

		while (1) {
			cout << " " << patk->Name() << " 要做什么？" << endl;
			cout << "1.攻击  2.使用道具 3.逃跑" << endl;
			cin >> choose;
			if (choose < 1 || choose>3) {
				cout << "错误！请重新输入！" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			else {
				return choose;
			}

		}
	}
}

int Fight::Restrain1(int p_atk, int p_target)//返回值0为攻击方被克制, 1为攻击方克制被攻击方, -1为无克制关系
//属性0克制所有，1克制2，2克制3，3克制1 
{
	enemy target = p_target;

	if (p_atk == 0) {
		Player* atk = Player::getPlayer();

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
	else {
		npc atk = p_atk;

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
}

int Fight::Restrain2(int p_atk, int p_target)//返回值0为攻击方被克制, 1为攻击方克制被攻击方, -1为无克制关系
//属性0克制所有，1克制2，2克制3，3克制1 
{
	enemy atk = p_atk;

	if (p_target == 0) {
		Player* target = Player::getPlayer();

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
	else {
		npc target = p_target;

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
}

//攻击
//我方攻击敌方
void Fight::Atk1(int atk, int target) {
	if (!isLive(target)) {
		return;
	}

	enemy p_enemy = target;

	//判断类型
	if (atk == 0) {
		Player* p_atk = m_player;

		if (rand() % 100 <= p_enemy->Dodging()) {
			cout << p_atk->Name() << " 攻击了 " << p_enemy->Name();
			cout << "， 但是 " << p_enemy->Name() << " 躲开了攻击!" << endl;
			system("pause");
		}
		else {
			double hurt;
			hurt = p_atk->getAttr(ATTACK);
			cout << p_atk->Name() << " 攻击了 " << p_enemy->Name() << " , ";
			if (rand() % 100 <= p_atk->getAttr(CRITING)) {
				hurt *= 2;
				cout << "击中了要害! ";
			}
			if (Restrain1(atk, target) == 1) {
				hurt *= 1.5;
				cout << "效果拔群! ";
			}
			else if (Restrain1(atk, target) == 0) {
				hurt *= 0.5;
				cout << "收效甚微……";
			}

			cout << " 造成了 " << hurt << " 点伤害。";
			p_enemy->HitPoints() -= hurt;

			system("pause");
		}
	}
	else {
		npc p_atk = atk;

		if (rand() % 100 <= p_enemy->Dodging()) {
			cout << p_atk->Name() << " 攻击了 " << p_enemy->Name();
			cout << "， 但是 " << p_enemy->Name() << " 躲开了攻击!" << endl;
			system("pause");
		}
		else {
			double hurt;
			hurt = p_atk->getAttr(ATTACK);
			cout << p_atk->Name() << " 攻击了 " << p_enemy->Name() << " , ";
			if (rand() % 100 <= p_atk->getAttr(CRITING)) {
				hurt *= 2;
				cout << "击中了要害! ";
			}
			if (Restrain1(atk, target) == 1) {
				hurt *= 1.5;
				cout << "效果拔群! ";
			}
			else if (Restrain1(atk, target) == 0) {
				hurt *= 0.5;
				cout << "收效甚微……";
			}

			cout << " 造成了 " << hurt << " 点伤害。";
			p_enemy->HitPoints() -= hurt;

			system("pause");
		}
	}
}

//敌方攻击我方
void Fight::Atk2(int atk, int target) {
	if (!isLive(target)) {
		return;
	}

	enemy p_atk = atk;

	//判断类型
	if (target == 0) {
		Player* p_target = m_player;

		if (rand() % 100 <= p_target->getAttr(DODGING)) {
			cout << p_atk->Name() << " 攻击了 " << p_target->Name();
			cout << "， 但是 " << p_target->Name() << " 躲开了攻击!" << endl;
			system("pause");
		}
		else {
			double hurt;

			hurt = p_atk->StrikeDamage();
			cout << p_atk->Name() << " 攻击了 " << p_target->Name() << " , ";

			if (Restrain2(atk, target) == 1) {
				hurt *= 1.5;
				cout << "效果拔群! ";
			}
			else if (Restrain2(atk, target) == 0) {
				hurt *= 0.5;
				cout << "收效甚微……";
			}

			cout << " 造成了 " << hurt << " 点伤害。";
			p_target->HitPoints() -= hurt;

			system("pause");
		}
	}
	else {
		npc p_target = target;

		if (rand() % 100 <= p_target->getAttr(DODGING)) {
			cout << p_atk->Name() << " 攻击了 " << p_target->Name();
			cout << "， 但是 " << p_target->Name() << " 躲开了攻击!" << endl;
			system("pause");
		}
		else {
			double hurt;

			hurt = p_atk->StrikeDamage();
			cout << p_atk->Name() << " 攻击了 " << p_target->Name() << " , ";

			if (Restrain2(atk, target) == 1) {
				hurt *= 1.5;
				cout << "效果拔群! ";
			}
			else if (Restrain2(atk, target) == 0) {
				hurt *= 0.5;
				cout << "收效甚微……";
			}

			cout << " 造成了 " << hurt << " 点伤害。";
			p_target->HitPoints() -= hurt;

			system("pause");
		}
	}
}

bool Fight::AttackTurn(int atk) {
	int targetnum = 1;
	int choose = 0;
	int n = 0;//可以自由选择的首索引尾索引
	int front = 0;//可以自由选择的首索引

	if (atk < 4) {

		//判断是玩家还是男主
		if (atk == 0) {
			player patk = atk;
			targetnum = 1;

			cout << "可攻击人数为：" << targetnum << endl;

			front = Front1();

			if (front == targetnum) {//前排锁定(已经自动将前排输入攻击队列
				cout << "已经锁定前排：";
				for (int i = 0; i < front; i++) {
					cout << static_cast<enemy>(targets[i])->Name() << "  ";
				}
				cout << endl;
			}
			else
			{
				if (front > targetnum) {//选择前排
					targets.clear();//清空含有前排的攻击队列

					front = 0;
					n = Enemy.size() / 2;
				}
				else {
					n = Enemy.size();
				}

				if (targets.size() > 0) {
					cout << "已经锁定前排：";
					for (int i = 0; i < front; i++) {
						cout << static_cast<enemy>(targets[i])->Name() << "  ";
					}
					cout << endl;
				}

				//未全部锁定
				//输出可以选择的敌人
				cout << "要攻击谁？(自由选择环节)" << endl;//选择攻击谁
				for (int i = front; i < n; i++) {
					if (isLive(Enemy[i])) {
						cout << "ID:" << left << setw(3) << i + 1 << "   Name:" << static_cast<enemy>(Enemy[i])->Name() << endl;
						cout << endl;
					}
				}

				//选择攻击的敌人
				for (int i = 0; i < targetnum - targets.size(); i++) {
					cout << "请输入ID（输入0，取消攻击)" << endl;
					cout << "> ";
					cin >> choose;

					while (choose < front + 1 || choose > n || !isLive(Enemy[choose - 1])) {//输入数组索引 + 1
						if (choose == 0) {
							return false;
						}

						cout << "错误！请重新输入！" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());

						cin >> choose;
					}

					targets.push_back(Enemy[choose - 1]);
					cout << static_cast<enemy>(Enemy[choose - 1])->Name() << "已加入攻击队列";

					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
			}
			for (int i = 0; i < targetnum; i++) {
				Atk1(patk, targets[i]);
			}
		}
		else {
			npc patk = atk;
			targetnum = patk->getTarget();

			cout << "可攻击人数为：" << targetnum << endl;

			front = Front1();

			if (front == targetnum) {//前排锁定(已经自动将前排输入攻击队列
				cout << "已经锁定前排：";
				for (int i = 0; i < front; i++) {
					cout << static_cast<enemy>(targets[i])->Name() << "  ";
				}
				cout << endl;
			}
			else
			{
				if (front > targetnum) {//选择前排
					targets.clear();//清空含有前排的攻击队列

					front = 0;
					n = Enemy.size() / 2;
				}
				else {
					n = Enemy.size();
				}

				if (targets.size() > 0) {
					cout << "已经锁定前排：";
					for (int i = 0; i < front; i++) {
						cout << static_cast<enemy>(targets[i])->Name() << "  ";
					}
					cout << endl;
				}

				//未全部锁定
				//输出可以选择的敌人
				cout << "要攻击谁？(自由选择环节)" << endl;//选择攻击谁
				for (int i = front; i < n; i++) {
					if (isLive(Enemy[i])) {
						cout << "ID:" << left << setw(3) << i + 1 << "   Name:" << static_cast<enemy>(Enemy[i])->Name() << endl;
						cout << endl;
					}
				}

				//选择攻击的敌人
				for (int i = 0; i < targetnum - targets.size(); i++) {
					cout << "请输入ID（输入0，取消攻击)" << endl;
					cout << "> ";
					cin >> choose;

					while (choose < front + 1 || choose > n || !isLive(Enemy[choose - 1])) {//输入数组索引 + 1
						if (choose == 0) {
							return false;
						}

						cout << "错误！请重新输入！" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());

						cin >> choose;
					}

					targets.push_back(Enemy[choose - 1]);
					cout << static_cast<enemy>(Enemy[choose - 1])->Name() << "已加入攻击队列";

					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
			}
			for (int i = 0; i < targetnum; i++) {
				Atk1(patk, targets[i]);
			}
		}
	}
	else {
		enemy patk = atk;
		targetnum = patk->getTarget();

		cout << "可攻击人数为：" << targetnum << endl;

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

	return true;
}

bool Fight::UseMedical(int atk) {
	int choose = 0;

	system("cls");

	cout << "-------------------------------- 你的背包 --------------------------------" << endl;
	cout << " ID:  |药品:" << endl;

	for (int i = 0; i < m_player->Items(); i++)
	{
		if (m_player->getItem(i)->Type() == HEALING) {
			cout << left << setw(2) << i + 1 << "  |" << m_player->getItem(i)->Name() << endl;
		}
	}

	cout << "---------------------------------------------------------------------------" << endl;

	cout << "请选择要使用的药品的ID(输入0，取消操作)" << endl;
	cout << "> ";
	cin >> choose;

	while (choose < 1 || choose > m_player->Items() || m_player->getItem(choose - 1)->Type() != HEALING) {//输入数组索引+1
		if (choose == 0) {
			return false;
		}

		cout << "错误！请重新输入！" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		cin >> choose;
	}

	if (atk == 0) {
		m_player->useHealing(choose - 1);
	}
	else {
		npc m_atk = atk;
		m_atk->useHealing(m_player->getItem(choose - 1));
	}

	m_player->dropItem(choose - 1);
	return true;
}

bool Fight::isWin() {
	int cnt = 0;

	for (int i = 0; i < Enemy.size(); i++) {
		if (!isLive(Enemy[i])) {
			cnt++;
		}
	}

	if (cnt == Enemy.size()) {
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

	if (cnt == Me.size()) {
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
	BattleTurn();//排序出手顺序
	while (1) {
		int atk = *(Turn.begin());

		if (!isLive(atk)) {//死亡的pop出Turn队列
			Turn.pop_front();
			total--;
			continue;
		}

		system("cls");
		cout << endl << "\t\t\t\t\t   当前回合：" << Round + 1;
		ShowBattle();

		if (atk < 4) {//是我方攻击
			choose = Choice(Round, atk);//选择界面

			if (choose == 1) {
				if (!AttackTurn(atk)) {
					continue;
				}
			}
			else if (choose == 2) {
				if (!UseMedical(atk)) {
					continue;
				}
			}
			else if (choose == 3) {
				if (rand() % 10 < 8) {
					cout << "逃跑成功！" << endl;
					break;
				}
				else {
					cout << "逃跑失败！" << endl;
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

	cout << "恭喜获得:" << endl;
	for (int i = 0; i < Enemy.size(); i++) {
		enemy p_enemy = Enemy[i];

		list<loot>::iterator itm = p_enemy->LootList().begin();
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

		money += p_enemy->MoneyMin() + rand() % (p_enemy->MoneyMax() - p_enemy->MoneyMin() + 1);
		exp += p_enemy->Exp();
	}

	m_player->addExp(exp);

	for (int i = 1; i < Me.size(); i++) {
		npc m_npc = Me[i];

		m_npc->addExp(exp);
	}

	m_player->Money() += money;
	cout << "￥ " << money << endl;

	cout << "获得经验EXP:" << left << setw(4) << exp;

	if (m_player->currentRoom() == 10 || m_player->currentRoom() == 7) {
		m_player->addNPC();
	}
}

void Fight::loseEXP() {
	system("cls");

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
