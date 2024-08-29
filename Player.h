#pragma once
#include <bits/stdc++.h>
#include "DatabasePointer.h"
#include "Item.h"
#include "Attributes.h"
using namespace std;
//δ���

const int PLAYERITEMS = 20;
const int NPCNUM = 4;

class Player{
public:
	//���캯��
	static void creatPlayer(string p_name = "��ӥ", int type = 1);//
	static void deletePlayer();
	static Player* getPlayer();
	~Player() = default;

	//��Ϣ
	string& Name() { return name; }
	void showPlayer();
	//void setTask(int p_task) { m_task = p_task; }
	int& Task() { return m_task; }//�ı����ڵ�

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
	void addDynamicBonuses(item p_item);//�ɱ���ֵ����������װ����ж�£�
	void addBonuses(item p_item);//������ֵ�����ӾͲ���ı䣩

	//Ѫ��
	int hitPoints() { return m_hitpoints; }
	void addHitPoints(int p_hitpoints);

    //���¼�������ֵ
	void recalculateStats();
	
	//��Ʒ����
	item getItem(int p_index) { return m_inventory[p_index]; }
	int Items() { return m_items; }
	int MaxItems() { return PLAYERITEMS; }
	int getItemIndex(string& p_name);//���ұ����е���Ʒ��������Ʒ����Ʒ���ݿ��е�ID

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

	//���亯��
	room currentRoom() { return m_room; }

	//�����������
	friend ostream& operator <<(ostream& p_stream, Player& p);
	friend istream& operator >>(istream& p_stream, Player& p);

	//��Ҵ����
	static void savePlayer();
	static Player* addPlayer();
private:
	//���캯��������ģʽ��
	Player(string p_name = "��ӥ", AttackType p_type = LIGHT);//δ���

	//�����Ϣ
	static Player* Instance;
	string name;

	//�������
	int m_level;//�ȼ�
	int m_exp;//����ֵ����ȼ����ã�
	money m_money;//��Ǯ
	int m_hitpoints;//Ѫ��;
	//int m_statpoints;
	AttackType m_type;
	AttributeSet m_baseattributes;//��������ֵ
	AttributeSet m_attributes;//��������ֵ

	//���װ����
	item m_inventory[PLAYERITEMS];//item���ݿ�ָ������
	int m_items;
	int m_weapon;//�������е�����
	int m_armor;

	//������
	int m_task;//�����Ӿ�����

	//����
	/*int m_statpoints;*/
	int m_room;//�����ID
};