#pragma once
#include <bits/stdc++.h>
#include "Entity.h"
#include "DatabasePointer.h"
using namespace std;

class Store :public Entity {
public:
	//迭代器封装
	typedef list<item>::iterator iterator;

	iterator begin() { return m_items.begin(); }
	iterator end() { return m_items.end(); }
	size_t size() { return m_items.size(); }

	//物品互动
	item find(string& p_item);
	bool has(entityid p_item);

	//重载输入
	friend istream& operator>>(istream& p_stream, Store& s);
protected:
	list<item> m_items;
};