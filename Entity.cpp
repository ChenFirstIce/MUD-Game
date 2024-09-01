#include <iostream>
#include <string>
#include <algorithm>
#include "Entity.h"
#include "EntityDatabase.h"
using namespace std;

string lowerCase(string str) {// ȫ��תд��Сд��ĸ,��ʵ�β��ı�
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

string Entity::compName(){//���ȫСдӢ������	
	return lowerCase(m_enname);
}

bool Entity::fullMatch(const string p_str){
	return compName() == lowerCase(p_str);
}

bool Entity::Match(const string p_str){
	if (p_str.size() == 0) {//���ֻ��һʵ����Բ���ע����
		return true;
	}

	string name = compName();
	string search = lowerCase(p_str);
	size_t pos = name.find(search);
	while (pos != string::npos) {//��μ��
		if (pos == 0 || m_name[pos - 1] == ' ') {//==0��ʾ�����δʵ���Ʒ��==' '��ʾ�����δʵ���Ʒ������ʲ���ƥ��
			return true;
		}
	}

	return false;
}

