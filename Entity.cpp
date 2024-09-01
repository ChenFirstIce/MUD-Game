#include <iostream>
#include <string>
#include <algorithm>
#include "Entity.h"
#include "EntityDatabase.h"
using namespace std;

string lowerCase(string str) {// 全部转写成小写字母,但实参不改变
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

string Entity::compName(){//输出全小写英文名字	
	return lowerCase(m_enname);
}

bool Entity::fullMatch(const string p_str){
	return compName() == lowerCase(p_str);
}

bool Entity::Match(const string p_str){
	if (p_str.size() == 0) {//如果只有一实体可以不标注名字
		return true;
	}

	string name = compName();
	string search = lowerCase(p_str);
	size_t pos = name.find(search);
	while (pos != string::npos) {//多次检查
		if (pos == 0 || m_name[pos - 1] == ' ') {//==0表示无修饰词的物品，==' '表示有修饰词的物品后的名词部分匹配
			return true;
		}
	}

	return false;
}

