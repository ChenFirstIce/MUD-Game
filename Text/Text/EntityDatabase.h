#pragma once
#include <bits/stdc++.h>
#include <iterator>
#include "Entity.h"
#include "Matchentity.h"
using namespace std;

template<class datatype>
class EntityDatabase {
public:
    using Iterator = typename map<entityid, datatype>::iterator;
    using ConstIterator = typename map<entityid, datatype>::const_iterator;

    EntityDatabase() = default;

    Iterator begin();
    Iterator end();
    size_t size();

    // 用id搜索
    bool has(entityid p_id);
    Iterator find(entityid p_id);
    datatype& get(entityid p_id = 0);

    // 用名称搜索
    bool has(const string& p_name);
    bool hasFull(const string& p_name);
    Iterator find(const string& p_name);
    Iterator findFull(const string& p_name);

protected:
    static map<entityid, datatype> m_map;
};

// 静态成员初始化
template<class datatype>
map<entityid, datatype> EntityDatabase<datatype>::m_map;

//迭代器封装
template<class datatype>
typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::begin() {
    return m_map.begin();
}

template<class datatype>
typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::end() {
    return m_map.end();
}

//通过id查找
template<class datatype>
bool EntityDatabase<datatype>::has(entityid p_id) {
    return (m_map.find(p_id) != m_map.end());
}

template<class datatype>
typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::find(entityid p_id) {
    return m_map.find(p_id);
}

template<class datatype>
datatype& EntityDatabase<datatype>::get(entityid p_id) {
    return m_map[p_id];
}

//通过datatype查找
template<class datatype>
bool EntityDatabase<datatype>::has(const string& p_name){
    return （find_if(begin(), end(), matchEntity(p_name) != end());
}

template<class datatype>
bool EntityDatabase<datatype>::hasFull(const string& p_name) {
    return (find_if(begin(), end(), matchEntityFull(p_name)) != end());
}

template<class datatype>
typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::find(const string& p_name){
    return find_if(begin(), end(), matchEntity(p_name));
}

template<class datatype>
typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::findFull(const string& p_name) {
    return find_if(begin(), end(), matchEntityFull(p_name));
}

template<class datatype>
size_t EntityDatabase<datatype>::size() {
    return m_map.size();
}


//using namespace std;
////未完成
//template<class datatype>
//class EntityDatabase {
//public:
//	using Iterator = typename std::map<entityid, datatype>::iterator;
//	EntityDatabase() = default;
//	//封装迭代器
//	iterator begin();
//	Iterator end();
//	size_t size();
//	//用id搜索
//	bool has(entityid p_id);//建存在返回true
//	Iterator find(entityid p_id);//返回迭代器
//	datatype& get(entityid p_id);//返回m_map[p_id]的引用
//	//用名称搜索
//	Iterator findfull(string p_name);//返回迭代器
//	bool hasfull(string p_name);//返回true
//protected:
//	static map<entityid, datatype> m_map;
//};
//
//template<class datatype>
//inline typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::begin(){
//	return m_map.begin();
//}
//
//template<class datatype>
//inline typename EntityDatabase<datatype>::Iterator EntityDatabase<datatype>::end(){
//	return m_map.end();
//}
//
//template<class datatype>
//inline bool EntityDatabase<datatype>::has(entityid p_id){
//	return (m_map.find(p_id) != m_map.end());
//}
//
//template<class datatype>
//inline iterator EntityDatabase<datatype>::find(entityid p_id){
//	return m_map.find(p_id);
//}
//
//template<class datatype>
//inline bool EntityDatabase<datatype>::hasfull(string p_name) {
//	return (m_map.find(p_id) != m_map.end());
//}
//
//template<class datatype>//未完成
//inline iterator EntityDatabase<datatype>::findfull(string str)
//{
//	return find_if(begin(), end(), matchentity(str));
//}
//
//template<class datatype>
//inline datatype& EntityDatabase<datatype>::get(entityid id)
//{
//	return m_map[p_id];
//}
//
//template<class datatype>//未完成
//inline size_t EntityDatabase<datatype>::size(){
//	return m_map.size();
//}
