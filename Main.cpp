#include <bits/stdc++.h>
#include "Entity.h"
#include "Player.h"
#include "DatabasePointer.h"
#include "ItemDatabase.h"
using namespace std;



int main() {
	ItemDatabase Itembase;
	Player::creatPlayer();
	Player oc = *Player::getPlayer();
	Itembase.Load();
	oc.showPlayer();
	/*item i = 1;
	Item* m = i;
	item d = m;//Item*不能赋值给item
	cout << '\n' <<d->Max();*/

	vector<int> a = { 0,1,2,3,4 };
	a.erase(a.begin());
	return 0;
}
