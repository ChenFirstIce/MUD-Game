#pragma once 
#include <iostream>
#include <vector>
#include "Entity.h"
using namespace std;

class NPC :public Entity {
public:

	//void showNPC();δ���

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

	//ս������
	int getType();
	void setType(int p_attr);

	//װ���ӳ�
	void addDynamicBonuses(item p_item);//������ֵ
	void addBonuses(item p_item);//������ֵ

	//Ѫ��
	int hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

	//���¼�������ֵ
	void recalculateStats();

	//��Ʒ����
	item getItem(int p_index) { return m_inventory[p_index]; }
	int Items() { return m_items; }
	int MaxItems() { return PLAYERITEMS; }
	int getItemIndex(string& p_name);

	//��������
	int getTarget(){return m_target;}

	//��������
	item Weapon();
	item Armor();

	//�����������
	friend ostream& operator <<(ostream& p_stream, Player& p);
	friend istream& operator >>(istream& p_stream, Player& p);

	//��Ҵ����
	void saveNPC();
	static void addNPC();
protected:
	//�������
	int m_level;//�ȼ�
	int m_exp;//����ֵ����ȼ����ã�
	int m_hitpoints;//Ѫ��;
	int m_target;//���ӿɹ������˸���
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//��������ֵ
	AttributeSet m_attributes;//������ֵ

	//���װ����
	item m_inventory[PLAYERITEMS];//item���ݿ�ָ������
	int m_items;
	int m_weapon;//�������е�����
	int m_armor;

	//����
	/*int m_statpoints;*/
	int m_room;
};