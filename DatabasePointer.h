#pragma once
#include <iostream>
#include "Entity.h"
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
DATABASEPOINTER(enemy, Enemy)
DATABASEPOINTER(npc, NPC)
DATABASEPOINTER(enemytemplate, EnemyTemplate)
DATABASEPOINTER(player, Player)
DATABASEPOINTER(store, Store)