#include <iostream>
#include<fstream>
#include <Windows.h>
#include "Bag.h"
#include "Enemy.h"
#include "Fight.h"
#include "Goods.h"
#include "Map.h"
#include "Npc.h"
#include "Role.h"
#include "Skill.h"
#include "Store.h"
#include"Save.h"
#include"Task.h"

using namespace std;

//强制界面全屏
/*
void FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	char setting[30];
	sprintf_s(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, x, y, NULL);
	MoveWindow(hwnd, 0, 0, x, y, 1);
	printf("\n\n");
}
*/

//欢迎界面
int welcomePage()
{
	HANDLE hConsole;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY| FOREGROUND_RED);//增加亮度，设置文本颜色
	/*
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	*/
	for(int i = 0;i < 8;i++)
		cout << endl;
	cout << "\t\t    0                    0                   0                0000000                     " << endl;
	cout << "\t\t   00   00000000000     0000000000      00000000000       0   0  0  0       00  00000000  " << endl;
	cout << "\t\t  00         0         00        0          000               0  0  0           00000000  " << endl;
	cout << "\t\t 00          0        00         0         00 00         00   0000000       00        00  " << endl;
	cout << "\t\t00   0       0           0000000 0        00   00         0   0  0  0      000        00  " << endl;
	cout << "\t\t000 00  00000000000      0  0  0 0       00     00        0   0  0  0       00        00  " << endl;
	cout << "\t\t   00   0  0   0  0      0  0  0 0    000000000000000     0   0000000       00        00  " << endl;
	cout << "\t\t  00    0  0   0  0      0000000 0                0       0      0          00  00000000  " << endl;
	cout << "\t\t 0000   0  00000  0      0  0  0 0         0000   0       0  000000000      00  00000000  " << endl;
	cout << "\t\t0000    0  0   0  0      0  0  0 0         0  0   0       0  0   0 0 0      00  00        " << endl;
	cout << "\t\t        0  0   0  0      0000000 0         0  0   0       0  0 00000 0      00  00        " << endl;
	cout << "\t\t    0   0  00000  0              0         0000   0       0  0     0 0      00  00        " << endl;
	cout << "\t\t   00   0  0   0  0              0                0       0  0      00      000 00    00  " << endl;
	cout << "\t\t  00    0  0   0  0            000              000      00                000  00000000  " << endl;
	cout << "\t\t 0      00000000000            000              000       00000000000000   00   00000000  " << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
	cout << '\t' << '\t' << '\t' << '\t' ;
	cout << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "       游戏制作信息" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   ********************" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "   制作人：中国海洋大学2017夏季学期c++课程设计16组" << endl;
	cout << '\t' << '\t' << '\t' << '\t' <<"   梁同学、张同学与孟同学" << endl<<endl;
	cout << '\t' << '\t' << '\t' << '\t';
	for (int i = 0;i < newGameMenu.length();i++) {
		Sleep(50);
		cout << newGameMenu[i];
	}
	cout << endl << endl << '\t' << '\t' << '\t' << '\t'<<"   ";
	return 0;
}

//显示游戏背景
int backgroundGame()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "背景" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "    你是O大一名正在忙于实习的大三女学生。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    你的美丽如同初升的朝阳，温暖而耀眼，让人不禁为之心动。你的笑容犹如春日里绽放的花朵，清新脱俗，充满了生机与活力。你的眼睛闪烁着星辰般的光芒，深邃而迷人，仿佛能洞察人心。你的每一次微笑，都如同春风拂面，让人沉醉在这份温柔与美好之中。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    这天晚上你正在操场上散步，突然三个英俊的男人出现在你的面前，并说他们才是你未来的的真爱，你疑惑地看了他们一眼，他们在你面前从左到右依次介绍自己。他们分别是：年轻的大学教授陆陈、上市公司总裁陈凡、实力派影帝陈冰。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    你白了他们一眼便离开了，心想：学校怎么让这些莫名其妙的人进来了。";
	return 0;
}
int story()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	string story = "    你来到了信息南楼上课，同学们三三两两地坐在一起小声地讨论，树影婆娑，阳光透过巨大的落地窗洒落下来，还能看到小小的灰尘在空中漫漫飘落。你依旧坐在平时常坐的第一排，开始准备课本，等待着上课。上课后，你的导师向你们介绍了新的助教，居然就是之前的陆陈。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    在他进来的瞬间，你闻到一股浓郁的雪松味，这让你想到了遥远的童年时期，外婆家门后就是一片巨大的森林，在冬天，厚厚的雪覆盖在大地上，一整个季节你都可以沐浴在这样清凉的芳香中。你不禁问旁边的同学，“你闻到什么奇特的味道了吗？”\n    她摇摇头，说：“没有啊，我没闻到什么奇怪的味道啊。”\n    一整堂课你都处于震惊之中，心不在焉地在课本上写下了“奇怪奇怪奇怪……”\n    下课铃将你拉到了现实，你收拾东西准备离开。\n    他急忙追上你，说：“XX，我们是国际组织维和部派来拯救你的，只有你和我们三个中的一个恋爱，才能拯救你的未来！”。\n    你感到十分疑惑，说：";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    A、“你怎么不告诉我，我们的世界其实是一个小说世界，我是需要男主拯救的女主呢？！”  \n    B、“真的吗？”  \n    C、“什么是国际组织维和部？你们又是谁？”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    他刚想开口和你说什么，但电梯已经到了，你被人群挤到电梯里的角落，而陆陈却被人群挤在门外，你只看到陆陈大张着嘴在电梯外喊着什么的样子，但你却一个字也没听见。电梯门缓缓闭上，你扭头一看，一片新鲜的四叶草却静静地出现在了你的肩头。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    你度过了平静的一个早上，来到望海苑准备享受美味的饭菜。但明明是午餐时间，平时嘈杂的食堂今天却空无一人，你买了一份美味的烧鸭饭便坐下开始享用。(你的面前是一份美味的烧鸭饭，一块经过精心烹制的鸭腿摆在米饭中间，外皮烤得金黄酥脆，表面还涂有一层秘制的酱料，内里肉质鲜嫩多汁，轻轻一咬，肉汁便在口中四溢，散发出浓郁的香气。旁边的咸菜又为甜中增添了咸味的复杂口感。而米饭吸收了鸭肉的精华，每一粒都显得格外饱满。旁边的青菜和黄瓜片，不仅为整道菜增添了一抹清新的色彩，也为口感带来了一丝爽脆。）";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    不一会，总裁坐到了你的面前，说：“这栋楼被我承包了，我已经让闲杂人等都离开了，现在只有我们两个，我有很重要的事情告诉你。”\n    总裁说到：“XX，我们是国际组织维和部派来拯救你的，只有你和我们三个中的一个恋爱，才能拯救你和地球的未来！”。你问到：";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    A、“你们三个是合伙来骗我吗，这也太无聊了吧。”  \n    B、“那你可以告诉我时空局是什么吗？” \n    C、“为什么一定是要和你们恋爱呢？”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    总裁刚想开口，但你却突然晕倒了，意识模糊间你只看到总裁将你抱在怀中不断地摇晃你的身体，你想清醒过来，但眼皮却越来越沉，最终闭上了双眼。\n    醒来时你已经躺在了校医院的床上，周围空无一人，旁边的柜子上的花瓶里插着一只向日葵，直直地朝着窗户的方向，你朝着那个方向望去，周围一片寂静，天空被染残阳染得几近血色。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    听了着三个人莫名其妙的话，你来到综合体图书馆想要查阅相关书籍。\n    “灵异事件吗？要看哪方面的书呢？”\n    实在没有头绪，你只能先向存放超自然方面书籍的书柜走去。但不知为什么，这层楼的学生出乎意料地少。空气中也泛着丝丝冷意，可能是空调坏了吧，你心想。继续往书架后面走，灯光也不知道为什么越来越暗，你加快了脚步，想着赶紧找到了快出来。\n    “第五排23D47号……找到了！”\n    你刚站起来，一个人拍了拍你的肩膀。你回头一看，原来是影帝。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	
	story = "    只见他拿着笔在本子上焦急地写着什么，然后撕下来揉成团紧紧塞到你的手里。你被他手心的温度烫到，呆呆地看着眼前的人，想问他到底是怎么回事，他却突然像故障的电子屏幕一般，变成了红蓝黄的线条，在闪烁几次后就凝聚成一个小点，消失了。\n    你的脑子宕机了几秒后，你急忙将手中的纸团展开，字迹也全部消失得无影无踪，只留下浅浅的印子，你可以模糊地看到几个字，高纬度，快逃……寂静的房间里只剩下你和头顶昏暗的灯光，如果不是你的手心还攥着那团纸，你甚至开始怀疑刚刚发生的一切是不是你的幻觉。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    叮铃铃……，你的手机铃声响了，你接通了这个陌生电话，里面传来一个自称是缅甸绑匪的男人的声音：“我是来自M78星云，光之国的MINMIN，我们的星球距离你们地球有300万光年。那天的三个男人是我们星球的叛徒，他们想要改变你的命运，不惜违法了我们星球的法律，穿越虫洞来到了你们星球。不过他们现在就在缅甸z城被我绑着，快来拯救他们吧，成功的话我会给你三个亿的奖励并且开具一份实习证明，最后再让你听听他们绝望的声音吧！”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    “别来！这里实在是太危险了！”，你听到他们三人齐声喊道。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    A、那咋了  B、放心，我一定会来救你们的！  C、那好吧，我不来了。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    原来是他们三人接到了AI合成的你的被绑架录像。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    教授说：“实验暂停，我去救人！”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    总裁说：“会议暂停，我去救人！”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    影帝说：“拍戏暂停，我去救人！”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    结果可想而知，三人全军覆没。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    三个亿并没有打动聪明睿智、冰雪聪明的你，但想到前几天的怪异事件，以及实习证明，你心动了。就这样，你踏上了拯救从天而降的三个男人的道路.....";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    【拯救的第一步：】";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    A、医院检查  B、警局  C、辅导员办公室  D、转身离开  E、乘坐火车站前往缅甸";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    机智的你在前往火车站的路上拨打了报警电话。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "    突然，电闪雷鸣，厚厚的乌云突然聚集成一团，仿佛要朝着地面压来，一下子就挡住了原本晴朗的天空。一艘UFO从乌云中冲出来，一束强烈的光打到你的身上，剧烈的风扬起泥土和灰尘，仿佛要把一切物体撕碎，你不由得闭上了眼.\n    再一睁眼，一个长着四只眼睛，八条腿，和科幻片里长得十分相似的外星人出现在你的眼前，周围的行人和车辆也全部突然暂停，连树叶也停止了颤抖。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	story = "   “哈哈哈哈哈，我是来自HD227号星球的想攻占地球的小A想要去救那三个男人得先通过我这关，让我们通过一场小游戏来决一死战吧！！！！！”";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	
	story = "    成功走出迷宫后，外星人却突然化作泡沫消失了，一切恢复正常，仿佛不曾发生。时间终于按下了启动键，路人开始行走，车辆开始疾驰，树叶开始沙沙作响。\n    你的眼前突然出现一行字，“成功击败小A，你可以拯救陆陈、陈凡、陈冰三人中的一人，你要选择谁”。刚刚选择好后，一束光便出现在你的身旁，他出现在了你的面前，一脸震惊。\n    XX激动地抱住你，“XX，太好了，终于见到你了……”你们的眼睛都忍不住泛起了泪花。\n    沉默了几分钟后，你向他说明了发生的一切，经过一致同意，你们决定去z城一探究竟。低头一看，地上还留下了两张前往缅甸的火车票和一柄魔杖，这柄魔杖内部似乎镶嵌了什么宝石，木质的杖身，外表的纹路深入魔杖内部，可以清晰地看到里面闪着绿色光的宝石，火车票上清清楚楚地写着你们的名字。于是你们捡起火车票和魔杖前往了最近的火车站。";
	for (int i = 0; i < story.length(); i++) {
		Sleep(10);
		cout << story[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	return 0;
}
int plot()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	string plot = "    火车缓慢地前进着，火车里人群熙熙攘攘，每一站都有人上车，也有人下车。但车上的人越来越少，在到达终点站的前一站，所有人都下了车，车上只剩你们两个乘客，还有留下来的只剩火车长和列车员。\n    最终经过两天两夜火车的颠簸，你和XX到达了缅甸边境。你们也第一次看清了列车长，他从驾驶室走出来，虽然身材消瘦，上了年纪，但看起来精神很不错。他遗憾地通知你们，这就是终点了站，火车无法继续向内部深入，你们只能下了火车，开始寻找前往z城的方法。在火车门关上的前一刻，你听到列车长充满希冀的声音“要加油啊，小姑娘！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    终点火车站周围是一处繁华热闹的集市，这里汇聚了各式各样的商品，叫卖声不绝于耳，玉石，玛瑙……，层层叠叠地摆在摊贩前的架子上，他们的架子前还特意用中文和缅甸语各写了广告，来往的人群中也能看到一两个熟悉的面孔。\n    再往里面走，便是酒楼、饭店和提供住宿的酒店。这里大多都是两层的木质建筑，二楼的窗户大开着，还能听见传来的大笑声和你听不懂的缅甸语。XX和你解释他们正在讨论前几天发现的玉石脉。\n    但当你们向当地的商贩打听z城后，大家要么用疑惑的眼神看你，缄口不言；要么就是听到后立刻大发雷霆，把你赶开。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    最终，一个流浪汉悄悄地在你耳边说：“请我吃顿饱饭，我就告诉你们z城怎么去。”\n    于是你带他去了旁边的小饭馆，看着他狼吞虎咽地吃下了一大桌饭菜。你这才知道，原来z城是缅甸大部分传销诈骗家族的窝点，那里有重兵把守，而且需要信物，否则根本进不去。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “如果你真的想去的话，就去找钱利来吧，他就住在山上那栋木屋里，不过别怪我没有告诉你，他可不是个好惹的角色。”，你抬头顺着乞丐的手指着的方向看过去，一栋小小的木屋就矗立在那。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    山下有一条唯一的小路通往山上，你们俩不疾不徐地走着，你心里想到开弓没有回头箭，都走到这里了，只能继续走下去了，希望警察能够尽快赶到。不一会儿，你们就到达了木屋前。依旧是一栋两层的木质建筑，已入深秋，屋顶的烟囱已经冒起了白烟，一切倒也显得岁月静好。一条体型硕大的黄狗被栓在门口，还没到门前，它就开始冲着你们叫。\n    而钱利来就等在门口，那是一个身材魁梧，长满胡子的中年男人，虽然两鬓已经有些斑白，但仍能看出他身上早年间经历过腥风血雨的痕迹。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “居然来了一个女人和小白脸要去z城，你的事都在我们这传开了，小姑娘，我劝你别太不自量力……”。你打断他的话，说到：“是不是打败你就能拿到去z城的地图，别废话了，决一死战吧！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “小姑娘，是我小看你了，还真是青出于蓝而胜于蓝，想当年我也是一个人单枪匹马地就去了z城。这是地图和我的信物。不过小姑娘，我再提醒你一次，z城真的是一个很危险的地方，我把这把天空之刃给你，希望你能成功。打败我之后你还可以选择拯救一个人，你要救谁呢，小姑娘？”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “谢谢您。我要救XX”接过天空之刃，XX从钱利来的木屋里走了出来。你看得出他的脸色惨白，但他还是对你笑了笑，抱住了你。\n    XX在旁边看着，你们三人默契地什么都没有多说，感受着来之不易的安静。最终你们三人又继续踏上了前往z城的道路。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    徒步走过危险的沼泽，毒蛇密布的丛林，跨过湍急的河流。你们越来越深入这片土地。\n    到达缅甸z城后，绑匪发来GPS定位，说：“早在你们打败钱利来是我就知道你要来了，是我特意让守卫放你们进来的。你这个小姑娘还真是女人中的女人，雌性中的雌性，太娘们了！我允许你们有一天的时间准备，明天再来见我吧！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    A、前往商店  B、前往咖啡店  C、查看人质安全  D、直接开战";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    【商店】";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    商店并不难找，就在z城进出口的位置，屋外挂了一大块木牌，上面刻着“宝鼎轩”三个大字。\n    进入商店，鸟笼里的八哥先发出“欢迎光临”的一声。映入眼帘的是一位和蔼的妇人站在收银柜台后面，她穿着一袭暗红的旗袍，外披一件雪白的皮草外套，头发被一只素雅的白玉发簪绾着，就这样安静地注视着你们，八哥在鸟笼里蹦蹦跳跳，把头歪来歪去，也好奇地盯着你们。\n    小小的商店挤满了各种物品，全部都放在木质的展示柜里，暖黄的灯光照着，金属反射出微光，显得这个孤独的小店温馨了许多。\n    “本店已经许久没有人光顾了呢。这三位客人，您们需要什么呢？本店应有尽有。”\n    你沉默不语，只是开始挑选需要的武器。其他两个人也在一左一右询问你需要什么样的武器。没想到这么不起眼的小店却卖着这么多种类的武器。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    A、铁剑  B、UZI  C、火之法杖  D、SCAR突击步枪  E、RPD轻机枪  F、圣光守护者铠甲  G、经验瓶";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    【咖啡店】";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “宝鼎轩”的对面是一家咖啡店，同样是木质风格，一只胖胖的橘猫躺在门口打盹。\n    老板是一位年轻的男性，看到你们很是惊讶，然后热情的将你们拉进了咖啡店，“天呐，我有小半年没有顾客了，你们快看看想吃什么，我的店里的东西可是可以恢复生命的哦！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    A、甜甜花酿鸡  B、蒙德土豆饼  C、野菇鸡肉串  D、嘟嘟莲海鲜羹  E、绝对不是下酒菜  F、风神杂烩汤";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    第二天到来";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    【废弃工厂】";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "   你们三人进入了废弃工厂，眼前是一片望不到头的黑暗，一大片空地上只立着两排生锈的铁柱还有不知道荒废了多久的机器，屋顶也几近崩塌，破了无数个大大小小的孔，不过照进来的光倒使得这个工厂不至于什么也看见，不知从哪渗进来的水留下一片青苔，又最终滴到地上，那里形成了几个大小不均的水洼。\n    耳边还传来窸窸窣窣的声音，你猜那可能是老鼠、蟑螂或是其他的什么东西……你朝前一步一步走着，喊道：“你快出来！我按和你的约定来了！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    一只绿色的形如果冻的巨大怪物出现在你们的眼前，目测有两米多高，以一种难以置信的速度朝你跳过来，你的眼前突然出现一行字：QQ弹弹史莱姆。之前发生的一系列事情已经让你见怪不怪了，你拿出武器便开始战斗。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    史莱姆刚刚消失，下一波怪物就来了。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    只见一个魁梧的人形怪物缓缓走了出来，它的全身覆盖着蓝色皮肤，左右各四只翅膀，每一只翅膀都宽大无比，羽毛如锋利的刀刃。他手里拿着一柄足足有一头成年棕熊这么大的锤子，表面刻满了古老的符文。随着他的走近，周围的温度也越来越低。你和其他二人默契地什么都没有多说便开始了战斗。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    终于击败了八翼冰巨人";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    你们三个还来不及多说什么，一声怒吼从黑暗中传来。一只巨大的绿色蜘蛛怪物缓缓地爬出来。它的身躯庞大无比，每一只腿都有树干那么粗，外面覆盖着坚硬的绿色鳞甲，在微弱的阳光下闪烁着幽暗的光泽。八只眼睛如同燃烧的绿色火焰，冷冷地扫视着四周，令你们一阵恶寒。它的獠牙锋利如刀，滴落着令人胆寒的毒液，每走一步，地面都为之震颤。又是一场恶战。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    终于击败了这只巨大的蜘蛛。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    转眼间，一个消瘦的男人出现在了你们面前。“你们最后的对手是我，准备好了吗？哈哈哈哈哈哈哈……”他捂住脸大笑起来，甚至最后不顾形象地跪在了地下。你们对视一眼，向他发起了攻击。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    最终，他呜咽一声“没想到居然会输给你们！！”，说着，就消失在了空气中。\n    而XX也从工厂黑暗深处向你们跑了过来。“不好了，xxx回到了光之国，准备启动银河三号向地球发起攻击！”。\n    周围两人齐声道：“不好！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;	
	plot = "    “你还没来得及搞清楚这一切，一艘飞船就出现在了你的眼前，通体白色，形如水滴。他们三人簇拥着将你带到了船上。“启动自动驾驶模式，前往光之国。”\n    陈冰说完边开始和你解释起来。原来XXX是光之国的一名科学家，但他十分痛恨地球人，而银河三号就是他研发的准备毁灭地球的飞船，如果不及时阻止他，后果不堪设想。\n    你疑惑不已，问到：“为什么你们要这样帮助地球呢，他不是你们星球的人吗？”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “我们隶属于国际组织维和部，我们是反对这样对其他星球的侵略行为的，因此我们想要阻止他。而你的身上有着可以对抗XXX的光之力量，因此，我们需要你的协助。”陆陈向你解释道。\n    “所以我们来到了地球找你，xxx实在是太恶趣味了，他设定的毁灭制止装置就是让你和我们三个恋爱，但他又反悔了，所以把我们抓了回去！”陈凡也愤愤的说着。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    你看着窗外的景象，他们说话的瞬间，你们就已经到了地球外层，你看着这个蓝色的星球，思绪万千。众人陷入了沉默之中。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “前方光之国即将到达。”飞船的广播传来。\n    “你愿意和我们一起拯救地球吗？”，他们三人就这样直直地望着你。\n    你们四人将手搭在一起，你回答：“当然！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    角落里突然传来一阵吼叫，你们四人向着声音来源看去，一只奇异的怪兽出现在你们面前。他的头部如狮子，但却长着人脸，嘴巴异常宽阔，牙齿锋利。但身体又是鸟类的样子，有着长长的脖子，脖子周围还有一圈深蓝色的毛发。通体红色，一双翅膀如蝙蝠一般，但足足有三四米长，也透露着淡淡的红色。四只脚如老鹰一般，但粗壮得多。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “不好！是肥遗！肯定是他在我们去地球的时候上了我们的飞船！”陆陈大喊道。\n    发现你们的位置后，他如同利剑一般朝你们冲来。一场战斗在飞船中展开。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    幸亏和肥遗的战斗并没有破坏飞船，飞船降最终落在了实验室。\n    在这个外星实验室中，一切都超出了你的想象。实验室的墙壁和天花板由一种未知的透明材料构成，它们散发着淡淡的蓝光，仿佛是外星夜空的缩影。\n    和你从前看到了科技大片的景象截然不同，这里生机盎然，被绿色植物包裹。植物藤蔓代替了精密的机械手臂，加工着不知道什么物品。墙壁上镶嵌着无数的符号和图案，这些可能是他们星球的文字和符号，在光线的照射下闪烁着奇异的光芒。";
	for (int i = 0;i < plot.length();i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    实验室的中心是一个巨大的环形平台，平台上悬浮着各种未知的实验设备，它们悬浮在空中，没有任何支撑。平台的中间，一个全息投影仪正在展示太阳系的星系模型，星系中的每一颗星星都以不同的颜色和亮度闪烁着，而地球格外明显。\n    上面显示了一行你看不懂的文字，而陈冰看了一眼，急忙对你说：“不好！还有十分钟毁灭装置就要启动了！我们得赶紧关闭这个装置！”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    “你们就别白费力气了！知道我为什么要毁灭地球吗？”一个男人从实验室底部缓缓升上来。\n    他的身材高大而瘦削，穿着一件破旧的白大褂，上面有各式各样的痕迹和烧焦的洞。他的皮肤苍白，几乎透明，显露出底下的血管和神经，脸上戴着一副方形的金属框眼镜，镜片后的眼睛此时变得猩红。";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    他没有在意你们的反应，继续自言自语。\n    “从地球形成之初，我就注意到你们这个星球了。起初我也没在意，但没想到你们名为人类的物种进化得如此之快。恐龙是我给过时间最多的物种了，但他们还是太愚蠢了，我给了他们这么长的时间也没有达到让我满意的智慧，所以我最终让他们消失了。而你们人类，没想到就在我眨眼的这么点时间就进化成了这样。于是我降下了疾病，战争，人和人之间的猜忌，没想到你们还是发展得如此之好。没办法，你们已经有科学家发现了我们星球的痕迹，我只能消灭你们了……”";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	plot = "    毁灭装置应该如何暂停？你们四人又该何去何从？地球是否会被毁灭？欲知后续如何，请期待《光之国奇遇记》……";
	for (int i = 0; i < plot.length(); i++) {
		Sleep(10);
		cout << plot[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;

	return 0;
}

//游戏运行函数
void newGame(Role player,Map map) {

	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	Store store;
	int chatNum = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
menu:
	Sleep(2000);
	system("cls");
	cout <<endl<< "位于 :" << map.getName() << endl;
	map.showRoom();
	if (map.isThereFight()) {
		Enemy_Boss  boss(map.getPosition());

		if(map.isThereChat() == false)
			cout << "这里有：" << '\t' ;
		cout << boss.getName() <<'\t'<<"三头小野怪"<< endl;
	}
	player.showRole();											//显示人物信息
	cout << endl << "1.交谈 2.战斗 3.移动 4.状态 5.商店 6.退出 7.保存并退出" << endl;
	int choice;
	while (true) {
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			cout << "选择错误，请重新选择。" << endl;
		else break;
	}
	if (choice == 1) {
		if (map.isThereChat()) {
			//交谈
			Npc npc(map.getPosition());
			map.setNpc(npc);
			cout << endl << "可以对话的人物:" << endl ;
			cout << map.getNpcName() << endl;
			player = map.chatToNpc(player);
		}
	}
	else if (choice == 2) {
		if (map.isThereFight()) {
			Enemy_Boss  boss(map.getPosition());
			Enemy_Small smallEnemy;
			boss.showEnemy();
			Fight fight(player, boss);
			system("cls");
			cout << "正在进入战斗......." << endl;
			while (!fight.isFightEnd()) {
				Sleep(3000);
				system("cls");
				if (fight.fightRound() == true) {
					player = fight.runEndFight();
					goto menu;
				}
			}
			player = fight.endFight();		//战斗正常结束，获得增益
			smallEnemy.~Enemy_Small();
		}
		else
		{
			cout << "这里没有战斗可以发生" << endl;
		}
	}
	else if (choice == 3) {
		while (true)
		{
			map.ShowMap();
			cout << "使用w a s d来移动 按1进入地图" << endl;
			char order;
			cin >> order;
			if (order == '1') {
				system("cls");
				break;
			}
			else {
				map.Move(order);
				chatNum = 0;
				player.setMapId(map.getPosition());
			}

		}

	}
	else if (choice == 4) {
		cout << "1.属性 2.背包 3.技能 4.装备 5.任务 6.返回" << endl;
		int choice;
		while (true) {
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
				cout << "选择错误，请重新选择。" << endl;
			else break;
		}
		if (choice == 2) {
			player.showBag();		//显示背包
			player.useDrug();		//是否使用药品
		}

		else if (choice == 3) player.showSkill();//显示技能
		else if (choice == 4) {
			player.showEquip();
			cout << "1.更换装备		2.取下装备		3.退出" << endl;
			int choiceEquip;
			cin >> choiceEquip;
			if (choiceEquip == 1) {
				player.showBag();
				cout << "请选择要换上的装备(24.取消)" << endl;
				int id;
				cin >> id;
				if (id >= 24 || id < 0)
					goto menu;
				player.wearEquip(id);
				player.getBag().reduceGoods(id, 1);
			}
			if (choiceEquip == 2) {
				cout << "请输入要换下的装备" << endl;
				cout << "1." << goods[player.getWeapon()].getName() << endl;
				cout << "2." << goods[player.getClothes()].getName() << endl;
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					player.removeEquip(player.getWeapon());
					player.getBag().addGoods(player.getWeapon(), 1);
				}
				if (choice == 2)
				{
					player.removeEquip(player.getClothes());
					player.getBag().addGoods(player.getClothes(), 1);
				}
			}
			if (choiceEquip == 3)
				goto menu;
		}
		else if (choice == 5) {
			cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;
		}
		else if (choice == 6) goto menu;
		else if (choice == 1)		//这里跳转到menu开头那里显示人物信息
			cout << "以上就为人物属性。" << endl;
	}
	else if (choice == 5) {
		cout << "1.购买物品		2.售出物品		3.退出" << endl;
		int choiceStore;
		cin >> choiceStore;
		if (choiceStore == 1) {
			store.showStores();
			player = store.storeToPlayer(player);
		}
		if (choiceStore == 2) {
			player.showBag();
			player = store.playerToStore(player);

		}
		if (choiceStore == 3)
			goto menu;
	}

	else if (choice == 6) {
		cout << "成功退出！" << endl;
		exit(0);
	}

	else if (choice == 7) {
		Save::setToFile(player);
		exit(0);
	}
	goto menu;

}

//读取游戏
void readFile() {
	ifstream fileRole("SaveRole.dat", ios_base::in | ios_base::binary);
	ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);
	ifstream fileSkill("SaveSkill.dat");
	ifstream fileTask("SaveTask.dat");
	if (!fileRole) {
		cout << "没有保存的游戏！" << endl;
		cout << "请重新选择:" << endl;
	}
	else {
		string name;
		int type, health_max, health, magic_max, magic, attack, exp, level, defend, money, mapId, story, weapon, clothes;
		fileRole >> name >> type >> health_max >> health >> magic >> magic_max >> attack >> exp >> level >> defend >> money >> mapId >> story >> weapon >> clothes;

		Role player(type);
		player.setHealth_max(health_max);
		player.setHealth(health);
		player.setMagic_max(magic_max);
		player.setMagic(magic);
		player.setAttack(attack);
		player.setExpSave(exp);
		player.setLevelSave(level);
		player.setDefend(defend);
		player.setMoney(money);
		player.setMapId(mapId);
		player.setStory(story);
		player.setWeapon(weapon);
		player.setClothes(clothes);

		Skill skill;
		fileSkill.read(reinterpret_cast<char *>(&skill), sizeof(Skill));
		Skill &newSkill = skill;
		player.setSkill(newSkill);

		Task task(0);
		fileTask.read(reinterpret_cast<char *>(&task), sizeof(Task));
		player.setTask(task);


		for (int key2 = 24;!fileBag.eof();) {

			int key;
			int value;
			fileBag >> key >> value;
			if (key2 == key)
				break;
			player.addSaveGoodsToBag(key, value);
			key2 = key;

		}
		fileRole.close();
		fileBag.close();
		fileSkill.close();
		Map newMap(player.getMapId());

		cout << "读入成功！" << endl;
		newGame(player,newMap);
	}
}

//程序入口
int main(){
	//FullScreen();
	welcomePage();
	int choice;
	while (true) {
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3)
				cout << "选择错误，请重新选择。" << endl;
			else break;
	}
		if (choice == 3)
			exit(0);
		//人物创建
		if (choice == 1) {
			backgroundGame();
			story();
			plot();
			int choiceRole;
			cout << "职业简介: " << endl <<
				"1.人道" << endl << "认为“道”是宇宙万物的本原和主宰，无所不在，无所不包，万物都是从“道”演化而来的。" << endl <<
				"2.阐教" << endl << "阐者，明也。阐教主张崇尚自然，提倡道法自然，无所不容，自然无为，与自然和谐相处。" << endl <<
				"3.截教" << endl << "主张上道无德，下道唯德。大道五十衍四十九为定数，一线生机遁去，截教的教义正是截取这一线生机，演变六道。" << endl;
			cout << endl << "请输入要创建的职业" << endl;

			while (true) {
				cin >> choiceRole;
				if (choiceRole != 1 && choiceRole != 2 && choiceRole != 3 )
					cout << "选择错误，请重新选择。" << endl;
				else break;
			}
			Role player(choiceRole);
			system("cls");
			cout << "创建成功" << endl;
			Map map;
			newGame(player,map);
		}
		if (choice == 2) {
			readFile();
	}
	return 0;
}



