#include <bits/stdc++.h>
#include "Entity.h"
#include "Player.h"
using namespace std;

int main() {
	Player oc = Player::getNewPlayer("Nami");
	ItemDatabase Itembase = ItemDatabase::getInstance();

	Itembase.Load();
	oc.showPlayer();
	return 0;
}
