#pragma once
#include <bits/stdc++.h>
#include <iterator>
#include "Entity.h"
#include "Matchentity.h"
using namespace std;

template<class datatype>
class EntityDatabase {
public:
    using iterator = typename map<entityid, datatype>::iterator;
    using constIterator = typename map<entityid, datatype>::const_iterator;

    EntityDatabase() = default;

    iterator begin();
    iterator end();
    size_t size();

    // ��id����
    static bool has(entityid p_id);
    static iterator find(entityid p_id);
    static datatype& get(entityid p_id = 0);

    // ����������
    static bool has(const string& p_name);
    static bool hasFull(const string& p_name);
    static iterator find(const string& p_name);
    static iterator findFull(const string& p_name);

protected:
    static map<entityid, datatype> m_map;
};

// ��̬��Ա��ʼ��
template<class datatype>
map<entityid, datatype> EntityDatabase<datatype>::m_map;

//��������װ
template<class datatype>
typename EntityDatabase<datatype>::iterator EntityDatabase<datatype>::begin() {
    return m_map.begin();
}

template<class datatype>
typename EntityDatabase<datatype>::iterator EntityDatabase<datatype>::end() {
    return m_map.end();
}

//ͨ��id����
template<class datatype>
bool EntityDatabase<datatype>::has(entityid p_id) {
    return (m_map.find(p_id) != m_map.end());
}

template<class datatype>
typename EntityDatabase<datatype>::iterator EntityDatabase<datatype>::find(entityid p_id) {
    return m_map.find(p_id);
}

template<class datatype>
datatype& EntityDatabase<datatype>::get(entityid p_id) {
    return m_map[p_id];
}

//ͨ��datatype����
template<class datatype>
bool EntityDatabase<datatype>::has(const string& p_name){
    return ��find_if(begin(), end(), matchEntity(p_name) != end());
}

template<class datatype>
bool EntityDatabase<datatype>::hasFull(const string& p_name) {
    return (find_if(begin(), end(), matchEntityFull(p_name)) != end());
}

template<class datatype>
typename EntityDatabase<datatype>::iterator EntityDatabase<datatype>::find(const string& p_name){
    return find_if(begin(), end(), matchEntity(p_name));
}

template<class datatype>
typename EntityDatabase<datatype>::iterator EntityDatabase<datatype>::findFull(const string& p_name) {
    return find_if(begin(), end(), matchEntityFull(p_name));
}

template<class datatype>
size_t EntityDatabase<datatype>::size() {
    return m_map.size();
}