#include "CommandExecutor.h"
#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;

extern string lowerCase(string str);

//需要完善NPC的界面和逻辑部分
bool CommandExecutor::Execute(const Command& cmd) {
    if (cmd.action == "drop") {
        return (DropItem(cmd));
    }
    else if (cmd.action == "pick") {
        return (GetItem(cmd));
    }
    else if (cmd.action == "buy") {
        return (Buy(cmd));
    }
    else if (cmd.action == "sell") {
        return (Sell(cmd));
    }
    else if (cmd.action == "use") {
        return (UseItem(cmd));
    }
    else if (cmd.action == "remove") {
        return (RemoveItem(cmd));
    }
   /* else if (cmd.action == "quit") {
        return (Quit(cmd));
    }*/
    else if (cmd.action == "help") {
        PrintHelp();
        return true;
    }
    else{
        cout << "啥？" << endl;    
    }
    return false;
}

//玩家登入登出
void CommandExecutor::New() {
    string name;
    int choice = 0;
    string type;

    system("cls");
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());

    if (Player::getPlayer() != nullptr) {
        Player::deletePlayer();
    }

    cout << "你的名字是？（例如：雌鹰）" << endl;
    cout << "> ";
    getline(cin, name);

    cout << "你的攻击类型是？（输入1，则攻击类型为光）" << endl;
    cout << "> ";
    cin >> choice;

    switch (choice) {
    case 1:
        type = "LIGHT";
        break;
    case 2:
        type = "GOLD";
        break;
    case 3:
        type = "FIRE";
        break;
    case 4:
        type = "GRASS";
        break;
    }

   Player::creatPlayer(name, type);
   m_player = Player::getPlayer();
}

bool CommandExecutor::Continue() {
    m_player = Player::addPlayer();

    if (m_player == nullptr) {
        cout << "没有存档之前的游戏。" << endl;
        return false;
    }

    return true;
}

//bool CommandExecutor::Quit(const Command& cmd){
//    if (!cmd.argus.empty()) {
//        cout << "啥" << endl;
//        return false;
//    }
//
//    exit(0);
//}

//打印函数
void CommandExecutor::PrintHelp(){

}

void CommandExecutor::PrintInventory(){
    Player& p = *m_player;

    cout << "-------------------------------- 你的背包 --------------------------------" << endl;
    cout << " ID:  |物品:" << endl;

    for (int i = 0; i < p.Items(); i++){
        cout << left << setw(2) << p.getItem(i)->ID() << "  |" << p.getItem(i)->Name() << endl;
    }

    cout << "\n-------------------------------- 你的装备 --------------------------------" << endl;

    if (p.Weapon() == 0) {
        cout << "没有武器！手无烤鸭之力！" << endl;
    }
    else {
        cout << " 武器:  " << p.Weapon()->Name() << endl;
    }

    if (p.Armor() == 0) {
        cout << "没有护具！" << endl;
    }
    else {
        cout << " 护具:  " << p.Armor()->Name() << endl;
    }

    cout << "Money:  $" << p.Money() << endl;

    cout << "------------------------------------------------------------------------------" << endl;
}

void CommandExecutor::PrintMyNPC(){
    list<npc>::iterator itr = m_player->Npces().begin();

    while (itr != m_player->Npces().end()) {
        (*itr)->showNPC();
        cout << endl;
    }
}

//物品互动函数
bool CommandExecutor::UseItem(const Command& cmd){
    string p_item = cmd.argus;
    int i = m_player->getItemIndex(p_item);

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return false;
    }

    if (i == -1)
    {
        cout << "找不到该物品。" << endl;
        return false;
    }

    Item& itm = *(m_player->getItem(i));


    switch (itm.Type())
    {
    case WEAPON:
        m_player->useWeapon(i);
        cout << "装备上" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player->useArmor(i);
        cout << "穿上" << itm.Name() << endl;

        return true;

    case HEALING:
        m_player->useHealing(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    case EXP:
        m_player->addExp(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    }

    return false;
}

bool CommandExecutor::RemoveItem(const Command& cmd){
    string p_item = cmd.argus;
    p_item = lowerCase(p_item);

    if (p_item == "weapon" && m_player->Weapon() != 0)
    {
        cout << "卸下" << m_player->Weapon()->Name() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "armor" && m_player->Armor() != 0)
    {
        cout << "脱下" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }
    

    /*if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    if (p_item == "武器" && m_player->Weapon() != 0)
    {
        cout << "卸下" << m_player->Weapon()->Nmae() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "护具" && m_player->Armor() != 0)
    {
        cout << "脱下" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }*/

    cout << "无法卸掉" << p_item << endl;
    return false;
}

//房间互动函数
void CommandExecutor::PrintRoom(){
    room p_room = m_player->currentRoom();
    stringstream temp;
    int count = 0;

    cout << "您现在的位置为\033[32m" << p_room->Name() << "\033[0m\n\n";

    //房间金钱
    temp << "金钱： ";
    if (p_room->Money() > 0)
    {
        temp << "\033[33m$" << p_room->Money() << "\033[0m\n";
        cout << temp.str();
    }

    temp.str("");
    temp.clear();
    

    //物品
    temp << "物品：  ";
    list<item>::iterator itemitr = p_room->Item().begin();
    while (itemitr != p_room->Item().end())
    {
        count++;
        temp << (*itemitr)->Name() <<"( "<< (*itemitr)->EnName() <<")" << ", ";
        itemitr++;
    }

    if (count > 0){
        string foo = temp.str();
        temp.str("");
        temp.clear();
        foo.erase(foo.size() - 2, 2);
        temp << foo << "\n\n";

        cout << temp.str();
    }

    temp.str("");
    temp.clear();

    //敌人
    temp <<  "敌人：  \n";
    count = 0;
    list<enemy>::iterator enemyitr = p_room->Enemies().begin();
    while (enemyitr != p_room->Enemies().end()){
        temp << "\033[35m"<< left << setw(25) << (*enemyitr)->Name() << "\033[0m(" << (*enemyitr)->EnName() << ")" << " \033[31m(血量:   " << (*enemyitr)->HitPoints() << ")" << "\033[0m\n";
        count++;
        enemyitr++;
    }

    if (count > 0 || p_room == 6){
        string foo = temp.str();
        temp.str("");
        temp.clear();
        foo.erase(foo.size() - 1, 1);
        temp << foo << "\n\n";

        cout << temp.str();
    }

    temp.str("");
    temp.clear();
}

bool CommandExecutor::GetItem(const Command& cmd){
    string p_item = cmd.argus;
    

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return false;
    }

    if (p_item[0] == '$') {
        stringstream p_money; 
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;
       
        if (m > m_player->currentRoom()->Money())
        {
            cout << "没有那么多钱，少做梦！" << endl;
            Sleep(500);

            return false;
        }
        else
        {
            m_player->Money() += m;
            m_player->currentRoom()->Money() -= m;
            cout << "捡起 $" << m << "元" << endl;
            cout << "tips：劝你交到警察局:)" << endl;

            Sleep(1000);
        }

        return true;
    }

    item i = m_player->currentRoom()->findItem(p_item);

    if (i == 0){
        cout << "这里没你想要的东西。" << endl;
        Sleep(500);

        return false;
    }
    
    if (!m_player->pickItem(i)){
        cout << "你拿不下这么多东西了，别太贪。" << endl;
        Sleep(500);

        return false;
    }

    m_player->currentRoom()->removeItem(i);
    cout << "你从地上捡起满是灰尘的" << i->Name() << endl;
    Sleep(500);

    return true;
}

bool CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        Sleep(500);

        return false;
    }

    if (p_item[0] == '$'){
        stringstream p_money;
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;

        if (m > m_player->Money()){
            cout << "你没那么多钱……" << endl;
            Sleep(500);

            return false;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "恭喜你！你又少了" << m << "元钱！" << endl;
            Sleep(500);
        }

        return true;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "你不曾拥有" << p_item << endl;
        Sleep(500);

        return false;
    }

    cout << "你抛弃了" << p_item << endl;
    Sleep(500);

    m_player->currentRoom()->addItem(m_player->getItem(i));
    m_player->dropItem(i);

    return true;
}

void CommandExecutor::StoreList(entityid p_store){//格式控制未完成
    Store& s = StoreDatabase::get(p_store);

    cout << "--------------------------------------------------------------------------------\n";
    cout << " 欢迎来到 " + s.Name() + "!\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << " 物品                           | 价格\n";
    cout << "--------------------------------------------------------------------------------\n";

    Store::iterator itr = s.begin();
    while (itr != s.end())
    {
        cout << left << setw(40) << (*itr)->Name() << "| ";
        cout << left << setw(4) << (*itr)->Price() << '\n';
        itr++;
    }
    cout << "--------------------------------------------------------------------------------\n";
        
}

bool CommandExecutor::Buy(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        Sleep(500);

        return false;
    }

    item i = s.find(p_item);
    if (i == 0)
    {
        cout << "这里没有你想要的东西" << endl;
        Sleep(500);
        
        return false;
    }

    if (p.Money() < i->Price())
    {
        cout << "……诶呀，有点担负不起" << endl;
        Sleep(500);

        return false;
    }

    if (!p.pickItem(i))
    {
        cout << "背包已经装不下了！" << endl;
        Sleep(500);

        return false;
    }

    p.Money() -= i->Price();
    cout << "购入" << p_item << ",已经放入背包了！" << endl;
    Sleep(500);
    
    return true;
}

bool CommandExecutor::Sell(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    int index = p.getItemIndex(p_item);
    if (index == -1)
    {
        cout << "你不曾拥有" << p_item << endl;
        Sleep(500);

        return false;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "我们已经有" << p_item << "，交易取消" << endl;
        Sleep(500);

        return false;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "成功卖出" << p_item << "，恭喜钱包又多了" << i->Price() << "元" << endl;
    Sleep(500);

    return true;
}

////NPC互动函数
//npc CommandExecutor::ChooseNPC(string p_item){
//    int id = m_player->findNPC(p_item);
//
//    if (id = 0) {
//        cout << "找不到他。\n" << "他是你的谁？" << endl;
//        return 0;
//    }
//
//    cout << "> " << endl;
//    cin >>
//
//    return static_cast<npc>(id);
//}

bool CommandExecutor::UseItemToNPC(const Command& cmd, npc& m_npc){
    //检验物品在不在
    string p_item = cmd.argus;

    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "你不曾拥有" << p_item << endl;
        Sleep(500);

        return false;
    }
    //判断装备有没有被装备过
    if (index == m_player->Weapon()||index == m_player->Armor()) {
        cout << "你已经装备过来，物品可不会分身……" << endl;
        Sleep(500);

        return false;
    }

    item itm = m_player->getItem(index);

    switch (itm->Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "给" << m_npc->Name() << "装备上" << itm->Name() << endl;
        Sleep(500);

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "给" << m_npc->Name() << "穿上" << itm->Name() << endl;
        Sleep(500);

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "给" << m_npc->Name() << "使用" << itm->Name() << endl;
        Sleep(500);

        return true;
    case EXP:
        m_npc->addExp(itm);
        m_player->dropItem(index);
        cout <<"给" << m_npc->Name() << "使用" << itm->Name() << endl;
        Sleep(500);

        return true;
    default:
        cout << "给予失败" << endl;
        Sleep(500);

        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd, npc& p_npc){
    //判断有没有装备过
    string p_item = cmd.argus;

    if (p_item == "武器" && p_npc->Weapon() != 0)
    {
        cout << "卸下" << p_npc->Weapon()->Name() << endl;
        p_npc->removeWeapon();
        Sleep(500);

        return true;
    }

    if (p_item == "护具" && p_npc->Armor() != 0)
    {
        cout << "脱下" << p_npc->Armor()->Name() << endl;
        p_npc->removeArmor();
        Sleep(500);

        return true;
    }
}

bool CommandExecutor::ShowFace(npc p_npc) {
    int id = p_npc;

    if (p_npc == 1) {

        cout << ".ii,...EGKLWt,,KKWijiLtjijKiEEiELtiELGKWKtjtGELEiG" << endl;
        cout << " ti   #EWGLKLttE     LLttitEiGEWLGGiEKEKKEEjtEEtGti" << endl;
        cout << " ti.iKWLKEGiiEtt      LLEiiGtiGKjGWLiEKEKK#WKLGE,E,i" << endl;
        cout << " tt    tGKKGLKij       LLGiiKiLKE GtLLEKKGKWjjiGK,G,i" << endl;
        cout << " ti   .#EEWELKL.      GKGLLiELiE L,EGEEKGK#jjiGE,E,i" << endl;
        cout << " tt    EWWEEGKL        KGLKLWLiG E jGEEKWE#WjtGKjGji" << endl;
        cout << " tt .WE#WWEEGKi       GGGLGLKWWWKGGEEKWE#jitGEjEji" << endl;
        cout << " tt    #KWEEGGL.EKWWKEiLLELEELj,,jLEEKKG#jjtGKjGji" << endl;
        cout << " ti    .LWEEEGWt.,,,,,,KLjL #######EGWKWEjjtGEGGGE" << endl;
        cout << " ti     ,#K#GGLtWKKKEGKLEt ii#####i#GiLKjWjtGLLLGG" << endl;
        cout << ".tt   . .GKKGG#G#####j,E  # LjWWKE,#LLGGjjjtGKKKKW" << endl;
        cout << ".ti     .GWGLKG#EWKWL..K,,G   GGt .KLiGKjjjtGKKKKK" << endl;
        cout << " ti    G.jKWG# G ,i    .          jt#GjKjjjjtGWKKEK" << endl;
        cout << " ti.    ..Wt#KL        L .  #        WiLjjjjjjtGKELtE" << endl;
        cout << " ti     .,LGW        #  .    W   tK   G LjjjjjtGKEijG" << endl;
        cout << ".ti..    E.Ej#####W     .             tKLjjjjjtGKEijE" << endl;
        cout << " tt.  .   # L                        WiGjjjjjtGKGLjE" << endl;
        cout << ",ti    .   WW           .            tEiGjjjjttGKGLjG" << endl;
        cout << "iit.,j.......W                       #.iGjjjjjtGKEGLE" << endl;
        cout << "iLiLiij.  ..  L                     , .iG,jjjjiGKELiE" << endl;
        cout << ".LLi,  .. ..  .j      iiiiLL       .iGjjjjttGKGLiE" << endl;
        cout << "GLL,,,.  .....  L,                 E.,LGjjjjjiGKELiE" << endl;
        cout << "GEGGGGG...      #t                Li.,LGjjjttiGKEGiE" << endl;
        cout << "..,iLEiiiiiiiiiiiK t          ,ttttiiG#GEjjtttLGKEGiE" << endl;
        cout << ",.,iLELLLLLiLiLLGt#tW.      tttt ttttLtWitijjjttLiE" << endl;
        cout << ",.jLLEjjtjtjjjjWtiWjtjjtjjjttijtKtGjjttttGGKEEGE" << endl;
        cout << "j.tLLEtttjtjtjWjtKijjji,,jjtjEjjtijjLjttttLGGLGGG" << endl;
        cout << "GjiLLEjjtttttKjjjWjjj  K,  jK, jjtLtjjKjtttLGEEEKK" << endl;
        cout << "          .#E,,,jWjt.   K  W    jtii,,,WWjj,,,,,jj" << endl;
        cout << "EGGEEEEEE#EL,.. j#t,     j,     .tGi,,,,GWWKWWWWWW" << endl;
        cout << "EEEEEEE#it,,.   j#i     ####    .j#i ,,,jiLL#KKWWW" << endl;
        cout << "EEEEKWj,LLE     tWW    WGLGK#   .tWL    .L.tttiWKW" << endl;
        return true;
    }
    else if (p_npc == 2) {

        cout << "!!!&......   #$@$%#**#oo@#&@@&$!*&&&   .......;!$." << endl;
        cout << "##@@&$%*#**#;;     .@**%&@&%$$$$$&&$.%%;" << endl;
        cout << "  o;!&$!!!#!&#&&$$$#*%%*!       &o&#&#.!!!!!&&!! ;% " << endl;
        cout << "  o. %.     o#&&$$#$$&%%        &#$&#@#     **   ;% " << endl;
        cout << "  o. *.    #@#$&$&%$#&$@         *$&@&#     **   ;% " << endl;
        cout << "  o. *.     @#&#&&&&!&&@          &&@#;#    **   ;% " << endl;
        cout << "  !. *.     #&@&&@&!!&&#    o#    #@!#      **   ;% " << endl;
        cout << "  !. *.    # @#@&&%  &&@ #.;@@@ @$o@      **   ;* " << endl;
        cout << "  !. *.   o  ##@$@###@&o  #%*   #!!       o*   !% " << endl;
        cout << "  !. *.      !@&#@@@%@;              o.       oo   !* " << endl;
        cout << "  !. o.      !&#! oo   *             .;.       oo   !* " << endl;
        cout << "  ;. o.      #&&          .           *         oo   !* " << endl;
        cout << "  ;. o                   .           $@        !!   !* " << endl;
        cout << "  ;. !       @#          $;          @         !!   !o " << endl;
        cout << "  ;  !        *!         .          &@         !!   !o " << endl;
        cout << "  ;  !                             !          !!   ;o " << endl;
        cout << "  ;  !           @       ;         oo          !!   ;o " << endl;
        cout << "  ;  !            $             ;o;          ;!   ;o " << endl;
        cout << "  ;  !             @           o*;.          ;;   ;o " << endl;
        cout << "  .  ;               &  .%;  %      ...;;.. ;o$" << endl;
        cout << "  .  ;             o**;.*;!  o      ...;;.. ;oo" << endl;
        cout << ". .  ;            $!!!%!;;@ ;!#     ...;;.. ;oo" << endl;
        cout << "  .  ;           ;*!**;;*.  ;!#     ...;... .!o" << endl;
        cout << "$    .          o@oo!!;;    ;;###      .. . .;o" << endl;
        cout << "     .         #%%!!.#      ;!&&&#     ..   ;!*" << endl;
        cout << "     .        @&@*!.o;$     ;@$$$$$@   ..   ;!;" << endl;
        cout << "*           #&&&#!.#%%%.    @**%$@$$%&;     .;." << endl;
        cout << "*o       @#$&&&#@!!#%%%#   ..********$$$&@% ..." << endl;
        cout << "    #@@#&$$$%&&&&&o#;&%%#;@  .%*****%o**o***%%$&@" << endl;
        cout << "    &$$$%%$%@%%##!. *&%#    ;$@*****@*o*******o$$" << endl;
        cout << "   $$$$$%%%%$%%%*   $%%! ... *****#*******$@*o**%" << endl;
        cout << "  @$$%%%%%%%%%%%@.  #&&..   *@*****@*****$%%*%**%" << endl;
        return true;
    }
    else if (p_npc == 3) {
        cout << "                GEEGjLjEWWELtEE                 " << endl;
        cout << "               KKKKGGKjLW#KKjGK#W                 " << endl;
        cout << "             i#KWKWGKKjG   WWKWKW                 " << endl;
        cout << "             W#KKEWK#KKK    WW#WW                 " << endl;
        cout << "              KWK#WEWKEE    .WKKLG                " << endl;
        cout << "              W#KWKKGEWG WWW W#KW K               " << endl;
        cout << "              W#KWiKGEE##E## W,LW                 " << endl;
        cout << "             #WKKjLK#i  E##L#WEt                  " << endl;
        cout << "              WiWWE###K  t   EGi                  " << endl;
        cout << "                KKL   W W    #  ,.                  " << endl;
        cout << "                 Wi  #t        jK                   " << endl;
        cout << "                      t        GK                   " << endl;
        cout << "                  .    t       j.                   " << endl;
        cout << "                   j          Kj                    " << endl;
        cout << "                    ,        tti                    " << endl;
        cout << "                      , . .  j .E                   " << endl;
        cout << "                          jt  E                   " << endl;
        cout << "                     LEGLjt.  tKW                 " << endl;
        cout << "                    EjGjjt , iiiWj                " << endl;
        cout << "                   KitKjt  L,,,i#E                " << endl;
        cout << "                 iG itLj  .   ,tWEKj              " << endl;
        cout << "                .GWW ttj  tG   #WEEjG             " << endl;
        cout << "              WiEEtW ttL  tji  WKGGKKiW           " << endl;
        cout << "            .GjEEWGjWit,,itWW  KKGGGEEEj          " << endl;
        cout << "         t GK#EE#WWtK  i.LLKWi GKLtLWKEGEt        " << endl;
        cout << "       ijjKjWWGGKEi WL..jtEK,tLLEtttWEGjjjGj      " << endl;
        cout << "      KtWtttjttGGL, WKWjKjj.  #LEtttjjLtjjtjG#K   " << endl;
        cout << "      EEttttttt#LE  ,GEEEE   .GLEttttEGttttjWKGW  " << endl;
        return true;
    }

    return false;
}





