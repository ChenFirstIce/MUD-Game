#include "stdc++.h"
#include "Item.h"
using namespace std;

extern string UTF8ToGB(const char* str);

void Item::setItemType(string p_arr) {
    char chr = p_arr[0];

    switch (chr) {
    case 'W':
        m_type = WEAPON;
        break;
    case 'A':
        m_type = ARMOR;
        break;
    case 'H':
        m_type = HEALING;
        break;
    case 'E':
        m_type = EXP;
        break;
    default:cout << "Error" << endl;
    }
}


istream& operator>>(istream& p_stream, Item& i)
{
    string temp;

    p_stream >> temp >> ws;     //扔掉Id
    getline(p_stream, i.m_name);//输入名字
    i.m_name = UTF8ToGB(i.m_name.c_str()).c_str();
    cout << i.m_name << endl;
    p_stream >> temp >> ws;
    getline(p_stream, i.m_enname);//输入英文名字
    cout << i.m_enname << endl;
    p_stream >> temp >> temp;    
    i.setItemType(temp);        //输入type
    cout << i.m_type << endl;
    p_stream >> temp >> i.m_min;
    p_stream >> temp >> i.m_max;
    p_stream >> temp >> i.m_price;
    p_stream >> i.m_attributeset;
    cout << endl << endl;

    return p_stream;
}