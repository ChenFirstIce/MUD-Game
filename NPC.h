#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include "DatabasePointer.h"
#include "Attributes.h"
#include "Entity.h"
#include "Item.h"
using namespace std;

class NPC :public Entity {
public:
	NPC(string p_name = "UNDEFINED");
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

	//�Ƿ�����
	bool getStats();
	void setStats(bool p_stats);

	//װ���ӳ�
	void addDynamicBonuses(item p_item);//������ֵ
	void addBonuses(item p_item);//������ֵ

	//Ѫ��
	int hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

	//���¼�������ֵ
	void recalculateStats();

	//��������
	int getTarget(){return m_target;}

	//��������
	item Weapon();
	item Armor();

	//�����������
	friend ostream& operator <<(ostream& p_stream, NPC& p);
	friend istream& operator >>(istream& p_stream, NPC& p);

	//��Ʒ����
	void removeWeapon();
	void removeArmor();
	void useWeapon(int p_index);
	void useArmor(int p_index);
	void useHealing(int p_index);
	void useExp(int p_index);
protected:
	//��Ϣ
	string m_name;
	bool m_stats;

	//NPC����
	int m_level;//�ȼ�
	int m_exp;//����ֵ����ȼ����ã�
	int m_hitpoints;//Ѫ��;
	int m_target;//���ӿɹ������˸���
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//��������ֵ
	AttributeSet m_attributes;//������ֵ

	//���װ����
	int m_weapon;//�������е�����
	int m_armor;

	//����
	/*int m_statpoints;*/
	int m_room;
};