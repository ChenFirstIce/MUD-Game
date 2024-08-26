#pragma once
#include <string>
#include "Attributes.h"
#include "Entity.h"
using namespace std;

class Item : public Entity {
public:
    Item() = default;
    Item(string p_name, entityid p_id) :Entity(p_name, p_id)
    {
        m_type = WEAPON;
        m_min = 0;
        m_max = 0;
        m_price = 0;
    }

    ItemType& Type() { return m_type; }
    int& Max() { return m_max; }
    int& Min() { return m_min; }
    money& Price() { return m_price; }
    int& getAttr(int attr) { return m_attributeset[attr]; }
    void setItemType(string p_arr);//°Ñ×Ö·û´®×ª»»³Ém_type

    friend istream& operator>>(istream& p_stream, Item& i);
private:
    ItemType m_type;
    int m_min;
    int m_max;
    money m_price;
    AttributeSet m_attributeset;
};
