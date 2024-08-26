#pragma once
#include <bits/stdc++.h>
#include "Attributes.h"
using namespace std;
//实体
typedef unsigned int entityid;
typedef unsigned long int money;

template< typename type >
inline type& extract(istream& s, type& t){//管理ID标签的加载，加载名称和各个物品，ID为0结束
	s >> t;
	return t;
}

class Entity {
public:
	Entity(string p_name = "UNDEFINED", entityid p_id = 0) :m_id(p_id), m_name(p_name) {}//默认物品ID为0，0为无效ID
	friend string lowerCase(string);
	string& Name() { return m_name; }//引用可以直接修改变量
	entityid& ID() { return m_id; }
	string compName();//名字的小写表示
	bool fullMatch(const string p_str);//与实体名字完全匹配
	bool Match(const string p_str);//与实体名字部分匹配
protected:
	string m_name;
	entityid m_id;
};


