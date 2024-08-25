#include "DatabasePointer.h"
#include "RoomDatabase.h"
#include "ItemDatabase.h"
using namespace std;

#define DATABASEPOINTERIMPL( pt, t, db )                \
t& pt::operator*()                                      \
{                                                       \
    return db::get( m_id );                             \
}                                                       \
                                                        \
t* pt::operator->()                                     \
{                                                       \
    return &( db::get( m_id ) );                       \
}                                                       \
                                                        \
pt::operator t*()                                       \
{                                                       \
    if( m_id == 0 )                                     \
        return 0;                                       \
    return &( db::get( m_id ) );                       \
}

DATABASEPOINTERIMPL(item, Item, ItemDatabase)
DATABASEPOINTERIMPL(room, Room, RoomDatabase)
DATABASEPOINTERIMPL(enemy, Enemy, EnemyDatabase)
DATABASEPOINTERIMPL(enemytemplate, EnemyTemplate, EnemyTemplateDatabase)