#pragma once
#include <bits/stdc++.h>
#include "Entity.h"
#include "DatabasePointer.h"
using namespace std;

class Store :public Entity {
public:
	//��������װ
	typedef list<item>::iterator iterator;

	iterator begin() { return m_items.begin(); }
	iterator end() { return m_items.end(); }
	size_t size() { return m_items.size(); }

	//��Ʒ����
	item find(string& p_item);
	bool has(entityid p_item);

	//��������
	friend istream& operator>>(istream& p_stream, Store& s);
protected:
	list<item> m_items;
};