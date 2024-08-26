#include "Command.h"
#include "Player.h"
using namespace std;
//δ���
class CommandExecutor {
public:
    CommandExecutor() = default;
    void execute(const Command& cmd);

private:
    //�������״̬
    //����
    void handleNew(Player& player, const Command& cmd);
    void handleContinue(Player& player, const Command& cmd);
    //�˳�
    void handleQuit(Player& player, const Command& cmd);

    //��ӡ��Ϣ
    static string printHelp();
    string printStats(Player& player, const Command& cmd);
    string printExperience(Player& player, const Command& cmd);
    string printInventory(Player& player, const Command& cmd);

    //��Ʒ����
    void handlePick(Player& player, const Command& cmd);
    void handleUse(Player& player, const Command& cmd);
    void handleRemove(Player& player, const Command& cmd);
    //void handleStats(const Command& cmd);
    //void handleBuy(const Command& cmd);
};