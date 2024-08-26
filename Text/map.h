#ifndef MAP_H
#define MAP_H
#include <string>
using namespace std;

class Map
{
public:
	Map();//初始位置为地图0
	Map(int pos); //由参数pos为所在位置
	~Map();
	void ShowMap();			//显示大地图
	void showRoom();		//显示身处的地方的信息，（有什么人可以交谈或者战斗）
	void Store();
	void Move(char order);
	bool isThereChat();
	bool isThereFight();
	int getPosition();

	string getNpcName();		//得到当前npc名字
	void setNpc(Npc newNpc);
	Role chatToNpc(Role player);
	int getNpcGoodsId();
	int getNpcGoodsNum();
	string getName();

private:
	string name;
	int position; //当前位置
	string mapName1[6] = { "操场","信息南楼","望海餐厅","警察局","校医院","青岛北站"};
	string mapName2[3] = { "废弃工厂","商店","咖啡馆"};
	int mapNum;
	char pos[3][3];
	int dx;
	int dy;
	Npc npc;
};

#endif