#ifndef MAP_H
#define MAP_H
#include <string>
using namespace std;

class Map
{
public:
	Map();//��ʼλ��Ϊ��ͼ0
	Map(int pos); //�ɲ���posΪ����λ��
	~Map();
	void ShowMap();			//��ʾ���ͼ
	void showRoom();		//��ʾ���ĵط�����Ϣ������ʲô�˿��Խ�̸����ս����
	void Store();
	void Move(char order);
	bool isThereChat();
	bool isThereFight();
	int getPosition();

	string getNpcName();		//�õ���ǰnpc����
	void setNpc(Npc newNpc);
	Role chatToNpc(Role player);
	int getNpcGoodsId();
	int getNpcGoodsNum();
	string getName();

private:
	string name;
	int position; //��ǰλ��
	string mapName1[6] = { "�ٳ�","��Ϣ��¥","��������","�����","УҽԺ","�ൺ��վ"};
	string mapName2[3] = { "��������","�̵�","���ȹ�"};
	int mapNum;
	char pos[3][3];
	int dx;
	int dy;
	Npc npc;
};

#endif