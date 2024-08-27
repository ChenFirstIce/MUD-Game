#include <iostream>
#include <string>
#include "Attributes.h"
using namespace std;

//将字符串转换成Attribute
Attribute getAttribute(string p_arr) {
	char chr = p_arr[0];

	switch (chr) {
	case 'M':return MAXHITPOINTS;
	case 'A':return ATTACK;
	case 'C':return CRITING;
	case 'D':return DODGING;
	case 'S':return SPEED;
	default:cout << "Error" << endl;
	}
}
//将Attribute转换成字符串
string getAttributesString(Attribute p_arr) {
	int i = static_cast<int>(p_arr);

	switch (i) {
	case 0:return "MHP";
	case 1:return "ATTACK";
	case 2:return "CRITING";
	case 3:return "DODGING";
	case 4:return "SPEED";
	default:cout << "Error" << endl;
	}
}

AttributeSet::AttributeSet(){
	for (int i = 0; i < NUMATTRIBUTES; i++) {
		m_attributes[i] = 0;
	}
}

int& AttributeSet::operator[](int p_attr){
	return m_attributes[p_attr];
}

ostream& operator<<(ostream& p_stream, AttributeSet& a)
{
	for (int i = 0; i < NUMATTRIBUTES; i++) {
		p_stream << "[" << getAttributesString((Attribute)i) << "]" << a.getPoint(i)<< "\n";
	}
	return p_stream;
}

istream& operator>>(istream& p_stream, AttributeSet& a)
{
	string temp;
	for (int i = 0; i < NUMATTRIBUTES; i++) {
		p_stream >> temp >> a.m_attributes[i];
	}
	return p_stream;
}
