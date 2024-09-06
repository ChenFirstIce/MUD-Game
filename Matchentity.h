#pragma once
#include "stdc++.h"
#include "Entity.h"
using namespace std;

//可以用find_if()查找value【find()只能通过key查找】
struct matchEntityFull {//完全匹配函数对象functor
	string m_str;
	matchEntityFull(const string& p_str) :m_str(p_str) {}//事先准备好的
	bool operator()(Entity& p_entity) {
		return p_entity.fullMatch(m_str);
	}
	bool operator()(Entity* p_entity) {
		return p_entity != nullptr && p_entity->fullMatch(m_str);
	}
};

struct matchEntity {//部分匹配函数对象functor
	string m_str;
	matchEntity(const string& p_str) :m_str(p_str) {}//事先准备好的
	bool operator()(Entity& p_entity) {
		return p_entity.Match(m_str);
	}
	bool operator()(Entity* p_entity) {
		return p_entity != nullptr && p_entity->Match(m_str);
	}
};