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
//δ���
class CommandExecutor {
public:
    CommandExecutor() = default;
    CommandExecutor(Player* player):m_player(player){}
    
    //�������ִ��
    void Execute(const Command& cmd);
    

    //��ҵ���ǳ�
    void New();//Ӧ������һ�����ƹ�ϵ�����
    void Continue();
    void Quit(const Command& cmd);//������һ��

    //���״̬��ӡ����
    static void PrintHelp();
    void PrintInventory();
    void PrintMyNPC();
   
    //��Ʒ��������
    void PrintRoom();
    bool UseItem(const Command& cmd);
    bool RemoveItem(const Command& cmd);

    //���以������
    //void Move(const Command& cmd);
    bool GetItem(const Command& cmd);
    bool DropItem(const Command& cmd);

    //�̵꺯����//�������������̵겻����yuan���жϣ�
    static void StoreList(entityid p_store);//��ʱ��֪����ô���뺯��
    bool Buy(const Command& cmd);
    bool Sell(const Command& cmd);

    //NPC��������
    npc ChooseNPC(string p_item);
    bool UseItemToNPC(const Command& cmd, npc& p_npc);
    bool RemoveItemFromNPC(const Command& cmd, npc& p_npc);
    bool ShowFace(npc p_npc);

    //Fight��������(Ӧ���ò���)
    //bool EnterFight(const Command& cmd);//δ���
   /* static void EnemyAttack(enemy p_enemy);
    static void PlayerKilled(player p_player);
    void PlayerAttack(const string& p_enemy);
    static void EnemyKilled(enemy p_enemy, player p_player);*/

protected:
    Player* m_player;
};