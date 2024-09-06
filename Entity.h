#pragma once
#include "stdc++.h"
#include "Attributes.h"
#include "func.h"
using namespace std;
//ʵ��
typedef unsigned int entityid;
typedef unsigned long int money;

class Entity {
public:
	Entity(string p_name = "UNDEFINED", string p_enname = "UNDEFINED", entityid p_id = 0) :m_id(p_id), m_name(p_name),m_enname(p_enname) {}//Ĭ����ƷIDΪ0��0Ϊ��ЧID
	friend string lowerCase(string);
	string& Name() { return m_name; }//���ÿ���ֱ���޸ı���
	string& EnName() { return m_enname; }
	entityid& ID() { return m_id; }
	string compName();//���ֵ�Сд��ʾ
	bool fullMatch(const string p_str);//��ʵ��������ȫƥ��
	bool Match(const string p_str);//��ʵ�����ֲ���ƥ��
protected:
	string m_name;
	string m_enname;
	entityid m_id;
};


