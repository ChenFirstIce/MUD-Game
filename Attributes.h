#pragma once
#include <iostream>
using namespace std;

const int NUMATTRIBUTES = 5;//��������

enum Attribute { MAXHITPOINTS,ATTACK,CRITING,DODGING,SPEED };//����,��ӦAttributeSet�±�

enum ItemType { WEAPON, ARMOR, HEALING, EXP};//��Ʒ����

enum RoomType { NORTH, SOUTH, WEST, EAST };

enum AttackType { LIGHT, GOLD, FIRE, GRASS };

class AttributeSet {//���Լ����൱�ڰ������Ե�����
public:
	AttributeSet();

	int& operator[](int p_attr);//����[]�����Ե�������ʹ�ã�ͨ���±꣨ö�����ƣ�����m_attributes[]�е�Ԫ��
	friend ostream& operator <<(ostream& p_stream, AttributeSet& a);//��ӡ���Լ��е���������
	friend istream& operator>>(istream& p_stream, AttributeSet& a);//��д�����Լ���
	int getPoint(int i) { return m_attributes[i]; }
protected:
	int m_attributes[NUMATTRIBUTES];//�������Եĵ���
};