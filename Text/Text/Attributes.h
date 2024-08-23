#pragma once
#include <iostream>
using namespace std;

const int NUMATTRIBUTES = 4;//属性数量

enum Attribute { MAXHITPOINTS,ATTACK,CRITING,DODGING };//属性,对应AttributeSet下标

enum ItemType { WEAPON, ARMOR, HEALING, EXP };//物品类型

class AttributeSet {//属性集，相当于包含属性的数组
public:
	AttributeSet();

	int& operator[](int p_attr);//重载[]，可以当成数组使用，通过下标（枚举名称）访问m_attributes[]中的元素
	friend ostream& operator <<(ostream& p_stream, AttributeSet& a);//打印属性集中的所有属性
	friend istream& operator>>(istream& p_stream, AttributeSet& a);//读写入属性集中
	int getPoint(int i) { return m_attributes[i]; }
protected:
	int m_attributes[NUMATTRIBUTES];//包含属性的点数
};