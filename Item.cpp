#include <bits/stdc++.h>
#include "Item.h"
using namespace std;

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

    p_stream >> temp >> ws;     //ÈÓµôId
    getline(p_stream, i.m_name);//ÊäÈëÃû×Ö
    p_stream >> temp >> ws;     //ÈÓµôId
    getline(p_stream, i.m_enname);//ÊäÈëÓ¢ÎÄÃû×Ö
    p_stream >> temp >> temp;    
    i.setItemType(temp);        //ÊäÈëtype
    p_stream >> temp >> i.m_min;
    p_stream >> temp >> i.m_max;
    p_stream >> temp >> i.m_price;
    p_stream >> i.m_attributeset;

    return p_stream;
}