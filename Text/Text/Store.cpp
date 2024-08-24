#include "Store.h"
using namespace std;

template< typename type >
inline type& extract(istream& s, type& t)
{
    s >> t;
    return t;
}

istream& operator>>(istream& p_stream, Store& s){
    string temp;

    p_stream >> temp >> ws;    
    getline(p_stream, s.Name());

    s.m_items.clear();

    entityid last;
    p_stream >> temp;                           // chew up "[ITEMS]" tag

    while (extract(p_stream, last) != 0)     // loop while item ID's valid
        s.m_items.push_back(last);            // add item

    return p_stream;
}
