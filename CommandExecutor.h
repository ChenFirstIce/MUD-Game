#pragma once
#include "DatabasePointer.h"
#include "CommandParser.h"
#include "RoomDatabase.h"
#include "ItemDatabase.h"
#include "StoreDatabase.h"
#include "NPCDatabase.h"
#include "Player.h"
#include "NPC.h"
using namespace std;
//未完成
class CommandExecutor {
public:
    CommandExecutor() = default;
    CommandExecutor(Player* player):m_player(player){}
    
    //解析命令并执行
    void Execute(const Command& cmd);
    

    //玩家登入登出
    void New();//应该增加一个克制关系的输出
    void Continue();
    void Quit(const Command& cmd);//更完善一点

    //玩家状态打印函数
    static void PrintHelp();
    void PrintInventory();
    void PrintMyNPC();
   
    //物品互动函数
    void PrintRoom();
    bool UseItem(const Command& cmd);
    bool RemoveItem(const Command& cmd);

    //房间互动函数
    //void Move(const Command& cmd);
    bool GetItem(const Command& cmd);
    bool DropItem(const Command& cmd);

    //商店函数（//可以增加缅甸的商店不适用yuan的判断）
    static void StoreList(entityid p_store);//暂时不知道怎么进入函数
    bool Buy(const Command& cmd);
    bool Sell(const Command& cmd);

    //NPC互动函数
    npc ChooseNPC(string p_item);
    bool UseItemToNPC(const Command& cmd, npc& p_npc);
    bool RemoveItemFromNPC(const Command& cmd, npc& p_npc);
    bool ShowFace(npc p_npc);

    //Fight互动函数(应该用不到)
    //bool EnterFight(const Command& cmd);//未完成
   /* static void EnemyAttack(enemy p_enemy);
    static void PlayerKilled(player p_player);
    void PlayerAttack(const string& p_enemy);
    static void EnemyKilled(enemy p_enemy, player p_player);*/

protected:
    Player* m_player;
};