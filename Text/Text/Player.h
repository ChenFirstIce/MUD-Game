#pragma once
#include <bits/stdc++.h>
#include "Entity.h"
#include "DatabasePointer.h"
using namespace std;
//δ���

const int PLAYERITEMS = 20;

class Player{
public:
	//���캯��
	static Player& getNewPlayer(string p_name = "��ӥ");//ֻ��һ��ʵ��
	static Player& getPlayer() { return *Instance; }
	~Player() = default;
	void showPlayer();

	//�ȼ�&����
	int getLevel() { return m_level; }
	void addExp(int exp);
	int needforLevel(int p_level);
	int needforNextLevel();

	//���Ժ���
	int getBaseAttr(int attr) { return m_baseattributes[attr]; }//���ĳ�������Ե���
	int getAttr(int p_attr);//��������Ե���
	void setBaseAttr(int p_attr, int p_val);//��������ĳ���Ի�������
	void addToBaseAttr(int p_attr, int p_val);//����ĳ���Ի�������

	//װ���ӳ�
	void addDynamicBonuses(item p_item);//������ֵ
	void addBonuses(item p_item);//������ֵ

	//Ѫ��
	int hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

	void recalculateStats();//���¼�������ֵ
	//��Ʒ����
	item GetItem(int p_index) { return m_inventory[p_index]; }
	int Items() { return m_items; }
	int MaxItems() { return PLAYERITEMS; }
	int getItemIndex(string& p_name);

	//��������
	item Weapon();
	item Armor();

	//�޸�װ����
	bool pickItem(item p_item);
	bool dropItem(int p_index);

	//��Ʒ����
	void removeWeapon();
	void removeArmor();
	void useWeapon(int p_index);
	void useArmor(int p_index);
	void useHealing(int p_index);
	void useExp(int p_index);

	//�����������
	friend ostream& operator <<(ostream& p_stream, Player& p);
	friend istream& operator >>(istream& p_stream, Player& p);

	//��Ҵ����
	static void savePlayer();
	static Player& addPlayer();
private:
	//���캯��������ģʽ��
	Player(string p_name);//δ���

	//�����Ϣ
	static Player* Instance;
	string name;

	//�������
	int m_level;//�ȼ�
	int m_exp;//����ֵ����ȼ����ã�
	money m_money;//��Ǯ
	int m_hitpoints;//Ѫ��;
	AttributeSet m_baseattributes;//��������ֵ
	AttributeSet m_attributes;//������ֵ

	//���װ����
	item m_inventory[PLAYERITEMS];//item���ݿ�ָ������
	int m_items;
	int m_weapon;//�������е�����
	int m_armor;

	//����
	int m_statpoints;
	int m_room;
};