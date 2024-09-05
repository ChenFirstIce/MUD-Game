#include "stdc++.h"
#include <Windows.h>
#include <cctype>
#include "Maze.h"
#include "Story.h"
#include "Fight.h"
using namespace std;

extern string lowerCase(string str);

void Story::showStory(int id) {

	if (id == 2) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    你来到了信息南楼";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    同学们三三两两地坐在一起小声地讨论，树影婆娑，阳光透过巨大的落地窗洒落下来，还能看到小小的灰尘在空中漫漫飘落。你依旧坐在平时常坐的第一排，开始准备课本，等待着上课。上课后，你的导师向你们介绍了新的助教，居然就是之前的陆陈。在他进来的瞬间，你闻到一股浓郁的雪松味，这让你想到了遥远的童年时期，外婆家门后就是一片巨大的森林，在冬天，厚厚的雪覆盖在大地上，一整个季节你都可以沐浴在这样清凉的芳香中。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    你不禁问旁边的同学，“你闻到什么奇特的味道了吗？”她摇摇头，说：“没有啊，我没闻到什么奇怪的味道啊。”一整堂课你都处于震惊之中，心不在焉地在课本上写下了“奇怪奇怪奇怪……”下课铃将你拉到了现实，你收拾东西准备离开。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    他急忙追上你，说：“我们是时空局派来拯救你的，只有你和我们三个中的一个恋爱，才能拯救你的未来！”你感到十分疑惑,他刚想开口和你说什么，但电梯已经到了，你被人群挤到电梯里的角落，而陆陈却被人群挤在门外，你只看到陆陈大张着嘴在电梯外喊着什么的样子，但你却一个字也没听见。 ";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    电梯门缓缓闭上，你扭头一看，一片新鲜的四叶草却静静地出现在了你的肩头。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 3) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    你度过了平静的一个早上，来到望海苑准备享受美味的饭菜。但明明是午餐时间，平时嘈杂的食堂今天却空无一人，你买了一份美味的烧鸭饭便坐下开始享用。你的面前是一份美味的烧鸭饭，一块经过精心烹制的鸭腿摆在米饭中间，外皮烤得金黄酥脆，表面可能还涂有一层秘制的酱料，内里肉质鲜嫩多汁，轻轻一咬，肉汁便在口中四溢，散发出浓郁的香气。旁边的咸菜又为甜中增添了咸味的复杂口感。而米饭吸收了鸭肉的精华，每一粒都显得格外饱满。青菜和黄瓜片不仅为整道菜增添了一抹清新的色彩，也为口感带来了一丝爽脆。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    不一会，总裁坐到了你的面前，说：“这栋楼被我承包了，我已经让闲杂人等都离开了，现在只有我们两个，我有很重要的事情告诉你。总裁说到：“我们是时空局派来拯救你的，只有你和我们三个中的一个恋爱，才能拯救你的未来！”你问到：“你们三个是合伙来骗我吗，这也太无聊了吧。”";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    总裁刚想开口，但你却突然晕倒了，意识模糊间你只看到总裁将你抱在怀中不断地摇晃你的身体，你想清醒过来，但眼皮却越来越沉，最终闭上了双眼。醒来时你已经躺在了校医院的床上，周围空无一人，旁边的柜子上的花瓶里插着一只向日葵，直直地朝着窗户的方向，你朝着那个方向望去，周围一片寂静，天空被染残阳染得几近血色。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 4) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    叮铃铃……，你的手机铃声响了，你接通了这个陌生电话，里面传来一个自称是缅甸绑匪的男人的声音：“我是来自M78星云，光之国的MINMIN，我们的星球距离你们地球有300万光年。那天的三个男人是我们星球的叛徒，他们想要改变你的命运，不惜违法了我们星球的法律，穿越虫洞来到了你们星球。不过他们现在就在缅甸z城被我绑着，快来拯救他们吧，成功的话我会给你三个亿的奖励并且开具一份实习证明，最后再让你听听他们绝望的声音吧！”\n    “别来！这里实在是太危险了！”，你听到他们三人齐声喊道。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    原来是他们三人接到了AI合成的你的被绑架录像。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		background = "    教授说：“实验暂停，我去救人！”\n    总裁说：“会议暂停，我去救人！”\n    影帝说：“拍戏暂停，我去救人！”\n    结果可想而知，三人全军覆没。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    三个亿并没有打动聪明睿智、冰雪聪明的你，但想到前几天的怪异事件，以及实习证明，你心动了。就这样，你踏上了拯救从天而降的三个男人的道路.....";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << endl;
		cout << "\033[0m`";
	}

	else if (id == 5) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    听了着三个人莫名其妙的话，你来到综合体图书馆想要查阅相关书籍。“灵异事件吗？要看哪方面的书呢？”实在没有头绪，你只能先向存放超自然方面书籍的书柜走去。 但不知为什么，这层楼的学生出乎意料地少。空气中也泛着丝丝冷意，可能是空调坏了吧，你心想。继续往书架后面走，灯光也不知道为什么越来越暗，你加快了脚步，想着赶紧找到了快出来。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    “第五排23D47号……找到了！”你刚站起来，一个人拍了拍你的肩膀。你回头一看，原来是影帝。只见他拿着笔在本子上焦急地写着什么，然后撕下来揉成团紧紧塞到你的手里。你被他手心的温度烫到，呆呆地看着眼前的人，想问他到底是怎么回事，他却突然像故障的电子屏幕一般，变成了红蓝黄的线条，在闪烁几次后就凝聚成一个小点，消失了。你的脑子宕机了几秒后，你急忙将手中的纸团展开，字迹也全部消失得无影无踪，只留下浅浅的印子，你可以模糊地看到几个字：";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    高纬度，快逃!!!";
		cout << "\033[31m";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		SetConsoleTextAttribute(hConsole, 14);
		background = "    寂静的房间里只剩下你和头顶昏暗的灯光，如果不是你的手心还攥着那团纸，你甚至开始怀疑刚刚发生的一切是不是你的幻觉。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 6) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    机智的你在前往火车站的路上拨打了报警电话。突然，电闪雷鸣，厚厚的乌云突然聚集成一团，仿佛要朝着地面压来，一下子就挡住了原本晴朗的天空。一艘UFO从乌云中冲出来，一束强烈的光打到你的身上，剧烈的风扬起泥土和灰尘，仿佛要把一切物体撕碎，你不由得闭上了眼，再一睁眼，一个长着四只眼睛，八条腿，和科幻片里长得十分相似的外星人出现在你的眼前，周围的行人和车辆也全部突然暂停，连树叶也停止了颤抖。“哈哈哈哈哈，我是来自HD227号星球的想攻占地球的小A想要去救那三个男人得先通过我这关，让我们通过一场小游戏来决一死战吧！！！！！";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		//迷宫
		Maze maz(m_player);
		maz.maze();
		m_player->addNPC();

		//HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		background = "    成功走出迷宫后，外星人却突然化作泡沫消失了，一切恢复正常，仿佛不曾发生。时间终于按下了启动键，路人开始行走，车辆开始疾驰，树叶开始沙沙作响。你的眼前突然出现一行字，“成功击败小A，你可以拯救陆陈、陈凡、陈冰三人中的一人，你要选择谁？”";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		background = "    刚刚选择好后，一束光便出现在你的身旁，他出现在了你的面前，一脸震惊。他激动地抱住你，“太好了，终于见到你了……”你们的眼睛都忍不住泛起了泪花。沉默了几分钟后，你向他说明了发生的一切，经过一致同意，你们决定去z城一探究竟。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    低头一看，地上还留下了两张前往缅甸的火车票和一柄魔杖，这柄魔杖内部似乎镶嵌了什么宝石，木质的杖身，外表的纹路深入魔杖内部，可以清晰地看到里面闪着绿色光的宝石，火车票上清清楚楚地写着你们的名字。于是你们捡起火车票和魔杖前往了最近的火车站台。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[31m" << "成功拯救一名男主，获得前往缅甸的车票和魔杖！" << "\033[0m" << endl;
		cout << "\033[0m`";
		Sleep(1500);
	}

	else if (id == 7) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    你们三人进入了废弃工厂，眼前是一片望不到头的黑暗，一大片空地上只立着两排生锈的铁柱还有不知道荒废了多久的机器，屋顶也几近崩塌，破了无数个大大小小的孔，不过照进来的光倒使得这个工厂不至于什么也看见，不知从哪渗进来的水留下一片青苔，又最终滴到地上，那里形成了几个大小不均的水洼。耳边还传来窸窸窣窣的声音，你猜那可能是老鼠、蟑螂或是其他的什么东西……你朝前一步一步走着，喊道：“你快出来！我按和你的约定来了！”";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    一群黑压压的的巨大怪物出现在你们的眼前。最左边的是一只绿色的形如果冻的怪物，目测有两米多高，以一种难以置信的速度朝你跳过来，你的眼前突然出现一行字：QQ弹弹史莱姆。之前发生的一系列事情已经让你见怪不怪了。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    史莱姆的旁边是一个魁梧的人形怪物，它的全身覆盖着蓝色皮肤，左右各四只翅膀，每一只翅膀都宽大无比，羽毛如锋利的刀刃。他手里拿着一柄足足有一头成年棕熊这么大的锤子，表面刻满了古老的符文。随着他的走近，周围的温度也越来越低。随着一声怒吼从头顶传来。一只巨大的绿色蜘蛛怪物缓缓地降落来。它的身躯庞大无比，每一只腿都有树干那么粗，外面覆盖着坚硬的绿色鳞甲，在微弱的阳光下闪烁着幽暗的光泽。八只眼睛如同燃烧的绿色火焰，冷冷地扫视着四周，令你们一阵恶寒。它的獠牙锋利如刀，滴落着令人胆寒的毒液。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 8) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    商店并不难找，就在z城进出口的位置，屋外挂了一大块木牌，上面刻着“宝鼎轩”三个大字。进入商店，鸟笼里的八哥先发出“欢迎光临”的一声。映入眼帘的是一位和蔼的妇人站在收银柜台后面，她穿着一袭暗红的旗袍，外披一件雪白的皮草外套，头发被一只素雅的白玉发簪绾着，就这样安静地注视着你们，八哥在鸟笼里蹦蹦跳跳，把头歪来歪去，也好奇地盯着你们。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    小小的商店挤满了各种物品，全部都放在木质的展示柜里，暖黄的灯光照着，金属反射出微光，显得这个孤独的小店温馨了许多。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    “本店已经许久没有人光顾了呢。这三位客人，您们需要什么呢？本店应有尽有。”你沉默不语，只是开始挑选需要的武器。其他两个人也在一左一右询问你需要什么样的武器。没想到这么不起眼的小店却卖着这么多种类的武器。 ";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 9) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    “宝鼎轩”的对面是一家咖啡店，同样是木质风格，一只胖胖的橘猫躺在门口打盹。老板是一位年轻的男性，看到你们很是惊讶，然后热情的将你们拉进了咖啡店，“天呐，我有小半年没有顾客了，你们快看看想吃什么，我的店里的东西可是可以恢复生命的哦！” ";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "\033[0m`";
	}

	else if (id == 10) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    火车缓慢地前进着，火车里人群熙熙攘攘，每一站都有人上车，也有人下车。但车上的人越来越少，在到达终点站的前一站，所有人都下了车，车上只剩你们两个乘客，还有留下来的只剩火车长和列车员。最终经过两天两夜火车的颠簸，你和他到达了缅甸边境。你们也第一次看清了列车长，他从驾驶室走出来，虽然身材消瘦，上了年纪，但看起来精神很不错。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    他遗憾地通知你们，这就是终点了站，火车无法继续向内部深入，你们只能下了火车，开始寻找前往z城的方法。在火车门关上的前一刻，你听到列车长充满希冀的声音“要加油啊，小姑娘！”。终点火车站周围是一处繁华热闹的集市，这里汇聚了各式各样的商品，叫卖声不绝于耳，玉石，玛瑙……，层层叠叠地摆在摊贩前的架子上，他们的架子前还特意用中文和缅甸语各写了广告，来往的人群中也能看到一两个熟悉的面孔。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    再往里面走，便是酒楼、饭店和提供住宿的酒店。这里大多都是两层的木质建筑，二楼的窗户大开着，还能听见传来的大笑声和你听不懂的缅甸语。当你们向当地的商贩打听z城后，大家要么用疑惑的眼神看你，缄口不言；要么就是听到后立刻大发雷霆，把你赶开。 ";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    最终，一个流浪汉悄悄地在你耳边说：“请我吃顿饱饭，我就告诉你们z城怎么去。”，于是你带他去了旁边的小饭馆，看着他狼吞虎咽地吃下了一大桌饭菜。你这才知道，原来z城是缅甸大部分传销诈骗家族的窝点，那里有重兵把守，而且需要信物，否则根本进不去。“如果你们真的钱利来吧，他就住在山上那栋木屋里，不过别怪我没有告诉你，他可不是个好惹的角色。”，你抬头顺着乞丐的手指着的方向看过去，一栋小小的木屋就矗立在那。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    山下有一条唯一的小路通往山上，你们俩不疾不徐地走着，你心里想到开弓没有回头箭，都走到这里了，只能继续走下去了，希望警察能够尽快赶到。不一会儿，你们就到达了木屋前。依旧是一栋两层的木质建筑，已入深秋，屋顶的烟囱已经冒起了白烟，一切倒也显得岁月静好。一条体型硕大的黄狗被栓在门口，还没到门前，它就开始冲着你们叫。而钱利来就等在门口，那是一个身材魁梧，长满胡子的中年男人，虽然两鬓已经有些斑白，但仍能看出他身上早年间经历过腥风血雨的痕迹。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    “居然来了一个女人要去z城，你的事都在我们这传开了，小姑娘，我劝你别太不自量力……”。你打断他的话，说到：“是不是打败你就能拿到去z城的地图，别废话了，决一死战吧！” ";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    徒步走过危险的沼泽，毒蛇密布的丛林，跨过湍急的河流。你们越来越深入这片土地。到达缅甸z城后，绑匪发来GPS定位，说：“早在你打败钱利来后我就知道你们要来了，没想到你们三个人竟然能走到这。你这个小姑娘还真是女人中的女人，雌性中的雌性，太娘们了！我允许你有们一天的时间准备，明天再来见我吧！”";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}

	else if (id == 11) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		system("cls");
		string background = "    “启动自动驾驶模式，前往光之国。”陈冰说完边开始和你解释起来。原来XXX是光之国的一名科学家，但他十分痛恨地球人，而银河三号就是他研发的准备毁灭地球的飞船，如果不及时阻止他，后果不堪设想。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		background = "    你疑惑不已，问到：“为什么你们要这样帮助地球呢，他不是你们星球的人吗？”“我们隶属于国际组织维和部，我们是反对这样对其他星球的侵略行为的，因此我们想要阻止他。而你的身上有着可以对抗XXX的光之力量，因此，我们需要你的协助。”陆陈向你解释道。“所以我们来到了地球找你，xxx实在是太恶趣味了，他设定的毁灭制止装置就是让你和我们三个恋爱，但他又反悔了，所以把我们抓了回去！”陈凡也愤愤的说着。你看着窗外的景象，他们说话的瞬间，你们就已经到了地球外层，你看着这个蓝色的星球，思绪万千。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    众人陷入了沉默之中。“前方光之国即将到达。”飞船的广播传来。“你愿意和我们一起拯救地球吗？”，他们三人就这样直直地望着你。你们四人将手搭在一起，你回答：“当然！”";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		background = "    角落里突然传来一阵吼叫，你们四人向着声音来源看去，一只奇异的怪兽出现在你们面前。他的头部如狮子，但却长着人脸，嘴巴异常宽阔，牙齿锋利。但身体又是鸟类的样子，有着长长的脖子，脖子周围还有一圈深蓝色的毛发。通体红色，一双翅膀如蝙蝠一般，但足足有三四米长，也透露着淡淡的红色。四只脚如老鹰一般，但粗壮得多。发现你们的位置后，他如同利剑一般朝你们冲来。一场战斗在飞船中展开。";
		for (int i = 0; i < background.length(); i++) {
			Sleep(10);
			cout << background[i];
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\033[0m`";
	}
}

void Story::Arriving() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	system("cls");
	string background = "    徒步走过危险的沼泽，毒蛇密布的丛林，跨过湍急的河流。你们越来越深入这片土地。到达缅甸z城后，绑匪发来GPS定位，说：“早在你打败钱利来后我就知道你们要来了，没想到你们三个人竟然能走到这。你这个小姑娘还真是女人中的女人，雌性中的雌性，太娘们了！我允许你有们一天的时间准备，明天再来见我吧！";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Story::Change(){
	char choice;
	room m_room = m_player->currentRoom();
	Fight fight(m_player);
	
	cout << "\t\t\t是否继续下面的剧情？[Y/N]\n";
	cout << "> ";
	cin >> choice;

	choice = tolower(choice);

	while (choice != 'y' && choice != 'n') {
		system("cls");

		cout << "\t\t\t是否继续下面的剧情？[Y/N]\n";
		cout << "> ";
		cin >> choice;

		choice = tolower(choice);
	}

	if (choice == 'y') {
		//青岛北车站
		showStory(6);//剧情+迷宫
		m_room->Task() = false;//插入

		//木屋
		m_room = 10;
		showStory(10);//木屋剧情
		m_room->Task() = false;

		fight.ProceedFight();
		if (fight.isWin()) {
			cout << "\033[31m" << "成功拯救一名男主，获得信物一份和z城地图一份！" << "\033[0m" << endl;
			Sleep(1500);
		}

		//进入缅甸的剧情
		Arriving();
		m_player->currentRoom() = 7;

		map_points = 2;
	}
}

void Story::Run(){
	int id = m_player->currentRoom();
	room m_room = m_player->currentRoom();
	Fight fight(m_player);

	if (m_room->Task()) {
		if (!static_cast<room>(2)->Task() && !static_cast<room>(4)->Task() && !static_cast<room>(5)->Task() && id == 6) {
			showStory(4);
			static_cast<room>(6)->Task() = false;

			Change();
		}
		else if(id !=6){
			showStory(id);
			m_room->Task() = false;
		}
	}
	else if (id == 6) {
		Change();
	}
}
