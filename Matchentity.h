#pragma once
#include "stdc++.h"
#include "Entity.h"
using namespace std;

//������find_if()����value��find()ֻ��ͨ��key���ҡ�
struct matchEntityFull {//��ȫƥ�亯������functor
	string m_str;
	matchEntityFull(const string& p_str) :m_str(p_str) {}//����׼���õ�
	bool operator()(Entity& p_entity) {
		return p_entity.fullMatch(m_str);
	}
	bool operator()(Entity* p_entity) {
		return p_entity != nullptr && p_entity->fullMatch(m_str);
	}
};

struct matchEntity {//����ƥ�亯������functor
	string m_str;
	matchEntity(const string& p_str) :m_str(p_str) {}//����׼���õ�
	bool operator()(Entity& p_entity) {
		return p_entity.Match(m_str);
	}
	bool operator()(Entity* p_entity) {
		return p_entity != nullptr && p_entity->Match(m_str);
	}
};