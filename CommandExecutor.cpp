#include "CommandExecutor.h"
#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;

extern string lowerCase(string str);

//��Ҫ����NPC�Ľ�����߼�����
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
        cout << "ɶ��" << endl;    
    }
    return false;
}

//��ҵ���ǳ�
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

    cout << "��������ǣ������磺��ӥ��" << endl;
    cout << "> ";
    getline(cin, name);

    cout << "��Ĺ��������ǣ�������1���򹥻�����Ϊ�⣩" << endl;
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
        cout << "û�д浵֮ǰ����Ϸ��" << endl;
        return false;
    }

    return true;
}

//bool CommandExecutor::Quit(const Command& cmd){
//    if (!cmd.argus.empty()) {
//        cout << "ɶ" << endl;
//        return false;
//    }
//
//    exit(0);
//}

//��ӡ����
void CommandExecutor::PrintHelp(){

}

void CommandExecutor::PrintInventory(){
    Player& p = *m_player;

    cout << "-------------------------------- ��ı��� --------------------------------" << endl;
    cout << " ID:  |��Ʒ:" << endl;

    for (int i = 0; i < p.Items(); i++){
        cout << left << setw(2) << p.getItem(i)->ID() << "  |" << p.getItem(i)->Name() << endl;
    }

    cout << "\n-------------------------------- ���װ�� --------------------------------" << endl;

    if (p.Weapon() == 0) {
        cout << "û�����������޿�Ѽ֮����" << endl;
    }
    else {
        cout << " ����:  " << p.Weapon()->Name() << endl;
    }

    if (p.Armor() == 0) {
        cout << "û�л��ߣ�" << endl;
    }
    else {
        cout << " ����:  " << p.Armor()->Name() << endl;
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

//��Ʒ��������
bool CommandExecutor::UseItem(const Command& cmd){
    string p_item = cmd.argus;
    int i = m_player->getItemIndex(p_item);

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return false;
    }

    if (i == -1)
    {
        cout << "�Ҳ�������Ʒ��" << endl;
        return false;
    }

    Item& itm = *(m_player->getItem(i));


    switch (itm.Type())
    {
    case WEAPON:
        m_player->useWeapon(i);
        cout << "װ����" << itm.Name() << endl;

        return true;

    case ARMOR:
        m_player->useArmor(i);
        cout << "����" << itm.Name() << endl;

        return true;

    case HEALING:
        m_player->useHealing(i);
        m_player->dropItem(i);
        cout << "ʹ��" << itm.Name() << endl;

        return true;
    case EXP:
        m_player->addExp(i);
        m_player->dropItem(i);
        cout << "ʹ��" << itm.Name() << endl;

        return true;
    }

    return false;
}

bool CommandExecutor::RemoveItem(const Command& cmd){
    string p_item = cmd.argus;
    p_item = lowerCase(p_item);

    if (p_item == "weapon" && m_player->Weapon() != 0)
    {
        cout << "ж��" << m_player->Weapon()->Name() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "armor" && m_player->Armor() != 0)
    {
        cout << "����" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }
    

    /*if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
        return;
    }

    if (p_item == "����" && m_player->Weapon() != 0)
    {
        cout << "ж��" << m_player->Weapon()->Nmae() << endl;
        m_player->removeWeapon();

        return true;
    }

    if (p_item == "����" && m_player->Armor() != 0)
    {
        cout << "����" << m_player->Armor()->Name() << endl;
        m_player->removeArmor();

        return true;
    }*/

    cout << "�޷�ж��" << p_item << endl;
    return false;
}

//���以������
void CommandExecutor::PrintRoom(){
    room p_room = m_player->currentRoom();
    stringstream temp;
    int count = 0;

    cout << "�����ڵ�λ��Ϊ\033[32m" << p_room->Name() << "\033[0m\n\n";

    //�����Ǯ
    temp << "��Ǯ�� ";
    if (p_room->Money() > 0)
    {
        temp << "\033[33m$" << p_room->Money() << "\033[0m\n";
        cout << temp.str();
    }

    temp.str("");
    temp.clear();
    

    //��Ʒ
    temp << "��Ʒ��  ";
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

    //����
    temp <<  "���ˣ�  \n";
    count = 0;
    list<enemy>::iterator enemyitr = p_room->Enemies().begin();
    while (enemyitr != p_room->Enemies().end()){
        temp << "\033[35m"<< left << setw(25) << (*enemyitr)->Name() << "\033[0m(" << (*enemyitr)->EnName() << ")" << " \033[31m(Ѫ��:   " << (*enemyitr)->HitPoints() << ")" << "\033[0m\n";
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
        cout << "ɶ��" << endl;
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
            cout << "û����ô��Ǯ�������Σ�" << endl;
            Sleep(500);

            return false;
        }
        else
        {
            m_player->Money() += m;
            m_player->currentRoom()->Money() -= m;
            cout << "���� $" << m << "Ԫ" << endl;
            cout << "tips��Ȱ�㽻�������:)" << endl;

            Sleep(1000);
        }

        return true;
    }

    item i = m_player->currentRoom()->findItem(p_item);

    if (i == 0){
        cout << "����û����Ҫ�Ķ�����" << endl;
        Sleep(500);

        return false;
    }
    
    if (!m_player->pickItem(i)){
        cout << "���ò�����ô�ණ���ˣ���̫̰��" << endl;
        Sleep(500);

        return false;
    }

    m_player->currentRoom()->removeItem(i);
    cout << "��ӵ��ϼ������ǻҳ���" << i->Name() << endl;
    Sleep(500);

    return true;
}

bool CommandExecutor::DropItem(const Command& cmd){
    string p_item = cmd.argus;

    if (cmd.argus.empty()) {
        cout << "ɶ��" << endl;
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
            cout << "��û��ô��Ǯ����" << endl;
            Sleep(500);

            return false;
        }
        else{
            m_player->Money() -= m;
            m_player->currentRoom()->Money() += m;
            cout << "��ϲ�㣡��������" << m << "ԪǮ��" << endl;
            Sleep(500);
        }

        return true;
    }

    int i = m_player->getItemIndex(p_item);

    if (i == -1)
    {
        cout << "�㲻��ӵ��" << p_item << endl;
        Sleep(500);

        return false;
    }

    cout << "��������" << p_item << endl;
    Sleep(500);

    m_player->currentRoom()->addItem(m_player->getItem(i));
    m_player->dropItem(i);

    return true;
}

void CommandExecutor::StoreList(entityid p_store){//��ʽ����δ���
    Store& s = StoreDatabase::get(p_store);

    cout << "--------------------------------------------------------------------------------\n";
    cout << " ��ӭ���� " + s.Name() + "!\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << " ��Ʒ                           | �۸�\n";
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
        cout << "ɶ��" << endl;
        Sleep(500);

        return false;
    }

    item i = s.find(p_item);
    if (i == 0)
    {
        cout << "����û������Ҫ�Ķ���" << endl;
        Sleep(500);
        
        return false;
    }

    if (p.Money() < i->Price())
    {
        cout << "������ѽ���е㵣������" << endl;
        Sleep(500);

        return false;
    }

    if (!p.pickItem(i))
    {
        cout << "�����Ѿ�װ�����ˣ�" << endl;
        Sleep(500);

        return false;
    }

    p.Money() -= i->Price();
    cout << "����" << p_item << ",�Ѿ����뱳���ˣ�" << endl;
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
        cout << "�㲻��ӵ��" << p_item << endl;
        Sleep(500);

        return false;
    }

    item i = p.getItem(index);
    if (!s.has(i))
    {
        cout << "�����Ѿ���" << p_item << "������ȡ��" << endl;
        Sleep(500);

        return false;
    }

    p.dropItem(index);
    p.Money() += i->Price();
    cout << "�ɹ�����" << p_item << "����ϲǮ���ֶ���" << i->Price() << "Ԫ" << endl;
    Sleep(500);

    return true;
}

////NPC��������
//npc CommandExecutor::ChooseNPC(string p_item){
//    int id = m_player->findNPC(p_item);
//
//    if (id = 0) {
//        cout << "�Ҳ�������\n" << "�������˭��" << endl;
//        return 0;
//    }
//
//    cout << "> " << endl;
//    cin >>
//
//    return static_cast<npc>(id);
//}

bool CommandExecutor::UseItemToNPC(const Command& cmd, npc& m_npc){
    //������Ʒ�ڲ���
    string p_item = cmd.argus;

    int index = m_player->getItemIndex(p_item);

    if (index == 0) {
        cout << "�㲻��ӵ��" << p_item << endl;
        Sleep(500);

        return false;
    }
    //�ж�װ����û�б�װ����
    if (index == m_player->Weapon()||index == m_player->Armor()) {
        cout << "���Ѿ�װ����������Ʒ�ɲ��������" << endl;
        Sleep(500);

        return false;
    }

    item itm = m_player->getItem(index);

    switch (itm->Type())
    {
    case WEAPON:
        m_npc->useWeapon(itm);
        cout << "��" << m_npc->Name() << "װ����" << itm->Name() << endl;
        Sleep(500);

        return true;
    case ARMOR:
        m_npc->useArmor(itm);
        cout << "��" << m_npc->Name() << "����" << itm->Name() << endl;
        Sleep(500);

        return true;
    case HEALING:
        m_npc->useHealing(itm);
        m_player->dropItem(index);
        cout << "��" << m_npc->Name() << "ʹ��" << itm->Name() << endl;
        Sleep(500);

        return true;
    case EXP:
        m_npc->addExp(itm);
        m_player->dropItem(index);
        cout <<"��" << m_npc->Name() << "ʹ��" << itm->Name() << endl;
        Sleep(500);

        return true;
    default:
        cout << "����ʧ��" << endl;
        Sleep(500);

        return false;
    }
}

bool CommandExecutor::RemoveItemFromNPC(const Command& cmd, npc& p_npc){
    //�ж���û��װ����
    string p_item = cmd.argus;

    if (p_item == "����" && p_npc->Weapon() != 0)
    {
        cout << "ж��" << p_npc->Weapon()->Name() << endl;
        p_npc->removeWeapon();
        Sleep(500);

        return true;
    }

    if (p_item == "����" && p_npc->Armor() != 0)
    {
        cout << "����" << p_npc->Armor()->Name() << endl;
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





