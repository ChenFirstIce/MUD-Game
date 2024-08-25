#include "Store.h"
using namespace std;

item Store::find(string& p_item){
    iterator itr = find_if(begin(), end(), matchEntityFull(p_item));

    if (itr != end()) {
        return *itr;
    }
    else {
        itr = find_if(begin(), end(), matchEntity(p_item));
        if (itr != end()) {
            return *itr;
        }
    }

    return 0;
}

bool Store::has(entityid p_item)
{
    return find(begin(), end(), p_item) != end();
}

istream& operator>>(istream& p_stream, Store& s){
    string temp;

    p_stream >> temp >> ws;    
    getline(p_stream, s.Name());

    s.m_items.clear();

    entityid last;
    p_stream >> temp;                           

    while (extract(p_stream, last) != 0)     
        s.m_items.push_back(last);            

    return p_stream;
}