#pragma once
#include <bits/stdc++.h>
#include "Attributes.h"
using namespace std;
//ʵ��
typedef unsigned int entityid;
typedef unsigned long int money;

template< typename type >
inline type& extract(istream& s, type& t){//����ID��ǩ�ļ��أ��������ƺ͸�����Ʒ��IDΪ0����
	s >> t;
	return t;
}

class Entity {
public:
	Entity(string p_name = "UNDEFINED", entityid p_id = 0) :m_id(p_id), m_name(p_name) {}//Ĭ����ƷIDΪ0��0Ϊ��ЧID
	friend string lowerCase(string);
	string& Name() { return m_name; }//���ÿ���ֱ���޸ı���
	entityid& ID() { return m_id; }
	string compName();//���ֵ�Сд��ʾ
	bool fullMatch(const string p_str);//��ʵ��������ȫƥ��
	bool Match(const string p_str);//��ʵ�����ֲ���ƥ��
protected:
	string m_name;
	entityid m_id;
};


