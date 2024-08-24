#pragma once
#include <iostream>
#include "ItemDatabase.h"
#include "Entity.h"
#include "Item.h"
using namespace std;

typedef unsigned int entityid;

#define DATABASEPOINTER( pt, t )                        \
class t;                                                \
class pt                                                \
{                                                       \
public:                                                 \
    pt( entityid p_id = 0 )                             \
        : m_id( p_id ) {}                               \
                                                        \
    pt& operator=( entityid p_id )                      \
    {                                                   \
        m_id = p_id;                                    \
        return *this;                                   \
    }                                                   \
                                                        \
    operator entityid()                                 \
    {                                                   \
        return m_id;                                    \
    }                                                   \
                                                        \
    t& operator*();                                     \
    t* operator->();                                    \
    operator t*();                                      \
                                                        \
    entityid m_id;                                      \
};                                                      \
                                                        \
inline ostream& operator<<( ostream& s, const pt& p )   \
{                                                       \
    s << p.m_id;                                        \
    return s;                                           \
}                                                       \
                                                        \
inline istream& operator>>( istream& s, pt& p )         \
{                                                       \
    s >> p.m_id;                                        \
    return s;                                           \
}

DATABASEPOINTER(item, Item)
DATABASEPOINTER(room, Room)
//
//
//#define DATABASEPOINTERIMPL( pt, t, db )                \
//t& pt::operator*()                                      \
//{                                                       \
//    return db.get( m_id );                             \
//}                                                       \
//                                                        \
//t* pt::operator->()                                     \
//{                                                       \
//    return &( db.get( m_id ) );                       \
//}                                                       \
//                                                        \
//pt::operator t*()                                       \
//{                                                       \
//    if( m_id == 0 )                                     \
//        return 0;                                       \
//    return &( db.get( m_id ) );                       \
//}
//
//DATABASEPOINTERIMPL(item, Item, ItemDatabase::getInstance())