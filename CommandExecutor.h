#include "Command.h"
#include "Player.h"
using namespace std;
//未完成
class CommandExecutor {
public:
    CommandExecutor() = default;
    CommandExecutor(Player& player):player(player){}
    
    //解析命令并执行
    void Execute(const Command& cmd);

    void New();
    void Continue();
    void Quit();

    // ------------------------------------------------------------------------
    //  various status-printing functions
    // ------------------------------------------------------------------------
    static string WhoList(const string& p_who);
    static string PrintHelp(PlayerRank p_rank = REGULAR);
    string PrintStats();
    string PrintExperience();
    string PrintInventory();

    // ------------------------------------------------------------------------
    //  Inventory Functions
    // ------------------------------------------------------------------------
    bool UseItem(const string& p_item);
    bool RemoveItem(string p_item);

    // ------------------------------------------------------------------------
    //  Accessors
    // ------------------------------------------------------------------------
    inline static BasicLib::Timer& GetTimer() { return s_timer; }
    inline static bool& Running() { return s_running; }


    // ------------------------------------------------------------------------
    //  Map Functions Added in Chapter 9
    // ------------------------------------------------------------------------
    void PrintMap();
    static string PrintRoom(room p_room);
    static void SendRoom(string p_text, room p_room);
    void Move(int p_direction);
    void GetItem(string p_item);
    void DropItem(string p_item);
    static string StoreList(entityid p_store);
    void Buy(const string& p_item);
    void Sell(const string& p_item);


    // ------------------------------------------------------------------------
    //  Enemy Functions Added in Chapter 10
    // ------------------------------------------------------------------------
    static void EnemyAttack(enemy p_enemy);
    static void PlayerKilled(player p_player);
    void PlayerAttack(const string& p_enemy);
    static void EnemyKilled(enemy p_enemy, player p_player);

protected:
    Player* m_player;
};