#include "CommandExecutor.h"
#include <iostream>
#include <sstream>
using namespace std;

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
    else if (cmd.action == "quit") {
        return (Quit(cmd));
    }
    else{
        cout << "啥？" << endl;    
    }
    return false;
}

//玩家登入登出
void CommandExecutor::New() {
    string name;
    int type;

    if (Player::getPlayer() != nullptr) {
        Player::deletePlayer();
    }

    cout << "你的名字是？（例如：雌鹰）" << endl;
    cout << ">";
    cin >> name;

    cout << "你的攻击类型是？（输入1，则攻击类型为光）" << endl;
    cout << ">";
    cin >> type;

    //增加元素选择
    m_player = Player::creatPlayer(name, type);
}

bool CommandExecutor::Continue() {
    m_player = Player::addPlayer();

    if (m_player == nullptr) {
        cout << "没有存档之前的游戏。" << endl;
        return false;
    }

    return true;
}

bool CommandExecutor::Quit(const Command& cmd){
    if (!cmd.argus.empty()) {
        cout << "啥" << endl;
        return false;
    }

    exit(0);
}

//打印函数
void CommandExecutor::PrintHelp(){

}

void CommandExecutor::PrintInventory(){
    Player& p = *m_player;

    cout << "-------------------------------- 你的背包 --------------------------------" << endl;
    cout << " ID:  |物品:" << endl;

    for (int i = 0; i < p.Items(); i++)
    {
        cout << left << setw(2) << p->getItem(i)->ID() << "  |" << p->getItem(i)->Name() << endl;
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

    cout << "Money:  ￥" << p.Money() << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
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
        cout << "穿上" << itm.Name() < endl;

        return true;

    case HEALING:
        m_player->useHealing(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    case EXP:
        m_player->addEXP(i);
        m_player->dropItem(i);
        cout << "使用" << itm.Name() << endl;

        return true;
    }

    return false;
}

bool CommandExecutor::RemoveItem(const Command& cmd){
    string p_item = cmd.argus;
    p_item = lowerCase(p_item);

    if (p_item == "weapon" && m_player.Weapon() != 0)
    {
        cout << "卸下" << m_player.Weapon()->Nmae() << endl;
        m_player.RemoveWeapon();

        return true;
    }

    if (p_item == "armor" && m_player.Armor() != 0)
    {
        cout << "脱下" << m_player.Armor()->Name() << endl;
        m_player.RemoveArmor();

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

    temp << p_room->Description() << "\n\n";

    //房间金钱
    count = 0;
    temp << "金钱：  ";
    if (p_room->Money() > 0)
    {
        count++;
        temp << "$" << p_room->Money() << "\n ";
    }

    //物品
    temp << "物品：  ";
    list<item>::iterator itemitr = p_room->Items().begin();
    while (itemitr != p_room->Items().end())
    {
        count++;
        temp << (*itemitr)->Name() << ", ";
        itemitr++;
    }

    if (count > 0)
    {
        string foo = temp.str();
        temp.clear();
        foo.erase(temp.size() - 2, 2);
        temp << foo << "\n\n";
    }

    //敌人
    temp <<  "敌人：  ";
    cout = 0;
    list<enemy>::iterator enemyitr = p_room->Enemies().begin();
    while (enemyitr != p_room->Enemies().end()){
        temp << (*enemyitr)->Name() << " (血量:   " << (*enemyitr)->HitPoints() << " )" << ", ";
        count++;
        enemyitr++;
    }
    if (count > 0){
        string foo = temp.str();
        temp.clear();
        foo.erase(temp.size() - 2, 2);
        temp << foo << "\n\n";
    }

    //最后全部打印
    ccout << temp.str();
}

bool CommandExecutor::GetItem(const Command& cmd){
    string p_item = cmd.argus;
    

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return false;
    }

    if (p_item[0] == '￥'){
        sstream p_money; 
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;
       
        if (m > m_player->CurrentRoom()->Money())
        {
            cout << "没有那么多钱，少做梦！" << endl;

            return false;
        }
        else
        {
            m_player.Money() += m;
            m_player->CurrentRoom()->Money() -= m;
            cout << "捡起 ￥" << m << "元" << endl;
            cout << "tips：劝你交到警察局:)" << endl;
        }

        return true;
    }

    item i = m_player->CurrentRoom()->FindItem(p_item);

    if (i == 0){
        cout << "这里没你想要的东西。" << endl;

        return false;
    }
    
    if (!m_player->pickItem(i)){
        cout << "你拿不下这么多东西了，别太贪。" << endl;

        return false;
    }

    m_player->CurrentRoom()->removeItem(i);
    cout << "你从地上捡起满是灰尘的" << i->Name() << endl;

    return true;
}

bool CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;

        return false;
    }

    if (p_item[0] == '$'){
        sstream p_money;
        money m;

        p_item.erase(0, 1);
        p_money << p_item;
        p_money >> m;

        if (m > m_player->Money()){
            cout << "你没那么多钱……" << endl;

            return false;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "恭喜你！你又少了" << m << "元钱！" << endl;
        }

        return true;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "你不曾拥有" << p_item << endl;

        return false;
    }

    cout << "你抛弃了" << p_item << endl;

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
        cout << left << setw(40) << itr->Name() << "| ";
        cout << left << setw(4) << itr->Price() << '\n';
        itr++;
    }
    cout << "--------------------------------------------------------------------------------\n";
        
}

void CommandExecutor::Buy(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;
        return;
    }

    item i = s.find(p_item);
    if (i == 0)
    {
        cout << "这里没有你想要的东西" << endl;
        return;
    }

    if (p.Money() < i->Price())
    {
        cout << "……诶呀，有点担负不起" << endl;
        return;
    }

    if (!p.pickItem(i))
    {
        cout << "背包已经装不下了！" << endl;
        return;
    }

    p.Money() -= i->Price();
    cout << "购入" << p_item << ",已经放入背包了！" << endl;
}

void CommandExecutor::Sell(const Command& cmd){
    string p_item = cmd.argus;
    Player& p = *m_player;
    Store& s = StoreDatabase::get(p.currentRoom()->Data());

    int index = p.getItemIndex(p_item);
    if (index == -1)
    {
        cout << "你不曾拥有" << p_item << endl;

        return false;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "我们已经有" << p_item << "，交易取消" << endl;

        return false;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "成功卖出" << p_item << "，恭喜钱包又多了" << i->Price() << "元" << endl;

    return true;
}

//NPC互动函数
npc CommandExecutor::ChooseNPC(string p_item){
    int id = m_player->findNPC(p_item);

    if (id = 0) {
        cout << "找不到他。\n" << "他是你的谁？" << endl;
        return 0;
    }

    cout << "> " << endl;
    cin >>

    return id;
}

bool CommandExecutor::UseItemToNPC(const Command& cmd, npc& p_npc){//未完成
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;

        return false;
    }

    //检验物品在不在
    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "你不曾拥有" << p_item << endl;

        return false;
    }
    //判断装备有没有被装备过
    if (itm == m_player->Weapon()||itm == m_player->Armor()) {
        cout << "你已经装备过来，物品可不会分身……" << endl;

        return false;
    }

    switch (itm.Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "给" << m_npc->Name() << "装备上" << itm.Name() << endl;

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "给" << m_npc->Name() << "穿上" << itm.Name() < endl;

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "给" << m_npc->Name() << "使用" << itm.Name() << endl;

        return true;
    case EXP:
        m_npc->addEXP(itm);
        m_player->dropItem(index);
        cout << <<"给" << m_npc->Name() << "使用" << itm.Name() << endl;

        return true;
    default:
        cout << "给予失败" << endl;

        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd, npc& p_npc){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "啥？" << endl;

        return false;
    }

    npc p_npc = ChooseNPC(cmd.argus);

    //判断有没有装备过
    if (p_item == "武器" && p_npc->Weapon() != 0)
    {
        cout << "卸下" << p_npc->Weapon()->Nmae() << endl;
        p_npc->removeWeapon();

        return true;
    }

    if (p_item == "护具" && p_npc->Armor() != 0)
    {
        cout << "脱下" << p_npc->Armor()->Name() << endl;
        p_npc->removeArmor();

        return true;
    }
}

bool CommandExecutor::ShowFace(npc p_npc){
    int id = npc;
    switch (id) {
    case 1:
        firstFace();
        break;
    case 2:
        secondFace();
        break;
    case 3:
        thirdFace();
        break;
    case 4:
        forthFace();
        break;
    default:
        return false;
    }
    return true;
}

bool showFace(npc p_npc){
	if(p_npc==1){
	
cout<<".ii,...EGKLWt,,KKWijiLtjijKiEEiELtiELGKWKtjtGELEiG"<<endl;
cout<<" ti   #EWGLKLttE     LLttitEiGEWLGGiEKEKKEEjtEEtGti"<<endl;
cout<<" ti.iKWLKEGiiEtt      LLEiiGtiGKjGWLiEKEKK#WKLGE,E,i"<<endl;
cout<<" tt    tGKKGLKij       LLGiiKiLKE GtLLEKKGKWjjiGK,G,i"<<endl;
cout<<" ti   .#EEWELKL.      GKGLLiELiE L,EGEEKGK#jjiGE,E,i"<<endl;
cout<<" tt    EWWEEGKL        KGLKLWLiG E jGEEKWE#WjtGKjGji"<<endl;
cout<<" tt .WE#WWEEGKi       GGGLGLKWWWKGGEEKWE#jitGEjEji"<<endl;
cout<<" tt    #KWEEGGL.EKWWKEiLLELEELj,,jLEEKKG#jjtGKjGji"<<endl;
cout<<" ti    .LWEEEGWt.,,,,,,KLjL #######EGWKWEjjtGEGGGE"<<endl;
cout<<" ti     ,#K#GGLtWKKKEGKLEt ii#####i#GiLKjWjtGLLLGG"<<endl;
cout<<".tt   . .GKKGG#G#####j,E  # LjWWKE,#LLGGjjjtGKKKKW"<<endl;
cout<<".ti     .GWGLKG#EWKWL..K,,G   GGt .KLiGKjjjtGKKKKK"<<endl;
cout<<" ti    G.jKWG# G ,i    .          jt#GjKjjjjtGWKKEK"<<endl;
cout<<" ti.    ..Wt#KL        L .  #        WiLjjjjjjtGKELtE"<<endl;
cout<<" ti     .,LGW        #  .    W   tK   G LjjjjjtGKEijG"<<endl;
cout<<".ti..    E.Ej#####W     .             tKLjjjjjtGKEijE"<<endl;
cout<<" tt.  .   # L                        WiGjjjjjtGKGLjE"<<endl;
cout<<",ti    .   WW           .            tEiGjjjjttGKGLjG"<<endl;
cout<<"iit.,j.......W                       #.iGjjjjjtGKEGLE"<<endl;
cout<<"iLiLiij.  ..  L                     , .iG,jjjjiGKELiE"<<endl;
cout<<".LLi,  .. ..  .j      iiiiLL       .iGjjjjttGKGLiE"<<endl;
cout<<"GLL,,,.  .....  L,                 E.,LGjjjjjiGKELiE"<<endl;
cout<<"GEGGGGG...      #t                Li.,LGjjjttiGKEGiE"<<endl;
cout<<"..,iLEiiiiiiiiiiiK t          ,ttttiiG#GEjjtttLGKEGiE"<<endl;
cout<<",.,iLELLLLLiLiLLGt#tW.      tttt ttttLtWitijjjttLiE"<<endl;
cout<<",.jLLEjjtjtjjjjWtiWjtjjtjjjttijtKtGjjttttGGKEEGE"<<endl;
cout<<"j.tLLEtttjtjtjWjtKijjji,,jjtjEjjtijjLjttttLGGLGGG"<<endl;
cout<<"GjiLLEjjtttttKjjjWjjj  K,  jK, jjtLtjjKjtttLGEEEKK"<<endl;
cout<<"          .#E,,,jWjt.   K  W    jtii,,,WWjj,,,,,jj"<<endl;
cout<<"EGGEEEEEE#EL,.. j#t,     j,     .tGi,,,,GWWKWWWWWW"<<endl;
cout<<"EEEEEEE#it,,.   j#i     ####    .j#i ,,,jiLL#KKWWW"<<endl;
cout<<"EEEEKWj,LLE     tWW    WGLGK#   .tWL    .L.tttiWKW"<<endl;
	}
	if(p_npc==2){
	
cout<<"!!!&......   #$@$%#**#oo@#&@@&$!*&&&   .......;!$."<<endl;
cout<<"##@@&$%*#**#;;     .@**%&@&%$$$$$&&$.%%;"<<endl;
cout<<"  o;!&$!!!#!&#&&$$$#*%%*!       &o&#&#.!!!!!&&!! ;% "<<endl;
cout<<"  o. %.     o#&&$$#$$&%%        &#$&#@#     **   ;% "<<endl;
cout<<"  o. *.    #@#$&$&%$#&$@         *$&@&#     **   ;% "<<endl;
cout<<"  o. *.     @#&#&&&&!&&@          &&@#;#    **   ;% "<<endl;
cout<<"  !. *.     #&@&&@&!!&&#    o#    #@!#      **   ;% "<<endl;
cout<<"  !. *.    # @#@&&%  &&@ #.;@@@ @$o@      **   ;* "<<endl;
cout<<"  !. *.   o  ##@$@###@&o  #%*   #!!       o*   !% "<<endl;
cout<<"  !. *.      !@&#@@@%@;              o.       oo   !* "<<endl;
cout<<"  !. o.      !&#! oo   *             .;.       oo   !* "<<endl;
cout<<"  ;. o.      #&&          .           *         oo   !* "<<endl;
cout<<"  ;. o                   .           $@        !!   !* "<<endl;
cout<<"  ;. !       @#          $;          @         !!   !o "<<endl;
cout<<"  ;  !        *!         .          &@         !!   !o "<<endl;
cout<<"  ;  !                             !          !!   ;o "<<endl;
cout<<"  ;  !           @       ;         oo          !!   ;o "<<endl;
cout<<"  ;  !            $             ;o;          ;!   ;o "<<endl;
cout<<"  ;  !             @           o*;.          ;;   ;o "<<endl;
cout<<"  .  ;               &  .%;  %      ...;;.. ;o$"<<endl;
cout<<"  .  ;             o**;.*;!  o      ...;;.. ;oo"<<endl;
cout<<". .  ;            $!!!%!;;@ ;!#     ...;;.. ;oo"<<endl;
cout<<"  .  ;           ;*!**;;*.  ;!#     ...;... .!o"<<endl;
cout<<"$    .          o@oo!!;;    ;;###      .. . .;o"<<endl;
cout<<"     .         #%%!!.#      ;!&&&#     ..   ;!*"<<endl;
cout<<"     .        @&@*!.o;$     ;@$$$$$@   ..   ;!;"<<endl;
cout<<"*           #&&&#!.#%%%.    @**%$@$$%&;     .;."<<endl;
cout<<"*o       @#$&&&#@!!#%%%#   ..********$$$&@% ..."<<endl;
cout<<"    #@@#&$$$%&&&&&o#;&%%#;@  .%*****%o**o***%%$&@"<<endl;
cout<<"    &$$$%%$%@%%##!. *&%#    ;$@*****@*o*******o$$"<<endl;
cout<<"   $$$$$%%%%$%%%*   $%%! ... *****#*******$@*o**%"<<endl;
cout<<"  @$$%%%%%%%%%%%@.  #&&..   *@*****@*****$%%*%**%"<<endl;
	}
	if(p_npc==3){      
cout<<"                GEEGjLjEWWELtEE                 "<<endl;
cout<<"               KKKKGGKjLW#KKjGK#W                 "<<endl;
cout<<"             i#KWKWGKKjG   WWKWKW                 "<<endl;
cout<<"             W#KKEWK#KKK    WW#WW                 "<<endl;
cout<<"              KWK#WEWKEE    .WKKLG                "<<endl;
cout<<"              W#KWKKGEWG WWW W#KW K               "<<endl;
cout<<"              W#KWiKGEE##E## W,LW                 "<<endl;
cout<<"             #WKKjLK#i  E##L#WEt                  "<<endl;
cout<<"              WiWWE###K  t   EGi                  "<<endl;
cout<<"                KKL   W W    #  ,.                  "<<endl;
cout<<"                 Wi  #t        jK                   "<<endl;
cout<<"                      t        GK                   "<<endl;
cout<<"                  .    t       j.                   "<<endl;
cout<<"                   j          Kj                    "<<endl;
cout<<"                    ,        tti                    "<<endl;
cout<<"                      , . .  j .E                   "<<endl;
cout<<"                          jt  E                   "<<endl;
cout<<"                     LEGLjt.  tKW                 "<<endl;
cout<<"                    EjGjjt , iiiWj                "<<endl;
cout<<"                   KitKjt  L,,,i#E                "<<endl;
cout<<"                 iG itLj  .   ,tWEKj              "<<endl;
cout<<"                .GWW ttj  tG   #WEEjG             "<<endl;
cout<<"              WiEEtW ttL  tji  WKGGKKiW           "<<endl;
cout<<"            .GjEEWGjWit,,itWW  KKGGGEEEj          "<<endl;
cout<<"         t GK#EE#WWtK  i.LLKWi GKLtLWKEGEt        "<<endl;
cout<<"       ijjKjWWGGKEi WL..jtEK,tLLEtttWEGjjjGj      "<<endl;
cout<<"      KtWtttjttGGL, WKWjKjj.  #LEtttjjLtjjtjG#K   "<<endl;
cout<<"      EEttttttt#LE  ,GEEEE   .GLEttttEGttttjWKGW  "<<endl;
    }
}

