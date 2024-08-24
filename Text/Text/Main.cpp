#include <bits/stdc++.h>
#include "Entity.h"
#include "Player.h"
using namespace std;

int main() {
	Player oc = Player::getNewPlayer();
	ItemDatabase Itembase;

	Itembase.Load();
	oc.showPlayer();
	return 0;
}
