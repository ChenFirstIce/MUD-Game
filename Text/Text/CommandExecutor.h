#include "Command.h"
#include "Player.h"
using namespace std;
//未完成
class CommandExecutor {
public:
    CommandExecutor() = default;
    void execute(const Command& cmd);

private:
    //更新玩家状态
    //登入
    void handleNew(Player& player, const Command& cmd);
    void handleContinue(Player& player, const Command& cmd);
    //退出
    void handleQuit(Player& player, const Command& cmd);

    //打印信息
    static string printHelp();
    string printStats(Player& player, const Command& cmd);
    string printExperience(Player& player, const Command& cmd);
    string printInventory(Player& player, const Command& cmd);

    //物品互动
    void handlePick(Player& player, const Command& cmd);
    void handleUse(Player& player, const Command& cmd);
    void handleRemove(Player& player, const Command& cmd);
    //void handleStats(const Command& cmd);
    //void handleBuy(const Command& cmd);
};