#include "DatabasePointer.h"
#include "CommandParser.h"
#include "RoomDatabase.h"
#include "ItemDatabase.h"
#include "StoreDatabase.h"
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
    void Quit();//������һ��

    //���״̬��ӡ����
    static void PrintHelp();
    void PrintStats();
    void PrintExperience();
    void PrintInventory();
    void PrintMyNPC();

    //��Ʒ��������
    bool UseItem(const Command& cmd);
    bool RemoveItem(const Command& cmd);

    //���以������
    void PrintMap();
    void PrintRoom();
    void Move(const Command& cmd);
    void GetItem(const Command& cmd);
    void DropItem(const Command& cmd);

    //�̵꺯����//�������������̵겻����yuan���жϣ�
    static void StoreList();//��ʱ��֪����ô���뺯��
    void Buy(const Command& cmd);
    void Sell(const Command& cmd);

    //NPC��������
    npc ChooseNPC(string p_item);
    void UseItemToNPC(const Command& cmd);
    void RemoveItemFromNPC(const Command& cmd);

    //Fight��������(Ӧ���ò���)
   /* static void EnemyAttack(enemy p_enemy);
    static void PlayerKilled(player p_player);
    void PlayerAttack(const string& p_enemy);
    static void EnemyKilled(enemy p_enemy, player p_player);*/

protected:
    Player* m_player;

    int situation = 0;
};