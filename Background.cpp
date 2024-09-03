#include <bits/stdc++.h>
#include<fstream>
#include <Windows.h>
#include "Maze.h"
#include "Story.h"
using namespace std;

void Story::ShowBackground() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	system("cls");
	cout << endl;
	string background = "    你是O大一名正在忙于实习的大三女学生";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	for (int i = 0; i < m_player->Name().length(); i++) {
		Sleep(10); // 每个字符输出前等待10毫秒
		cout << m_player->Name();
	}
	background = "。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl ;
	background = "    你的美丽如同初升的朝阳，温暖而耀眼，让人不禁为之心动。你的笑容犹如春日里绽放的花朵，清新脱俗，充满了生机与活力。你的眼睛闪烁着星辰般的光芒，深邃而迷人，仿佛能洞察人心。你的每一次微笑，都如同春风拂面，让人沉醉在这份温柔与美好之中。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    这天晚上你正在操场上散步，突然三个英俊的男人出现在你的面前，并说他们才是你未来的的真爱，你疑惑地看了他们一眼。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl ;
	system("pause");
	cout << endl;
	background = "    他们在你面前从左到右依次介绍自己。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    他们分别是：年轻的大学教授陆陈（草）、上市公司总裁陈凡（金）、实力派影帝陈冰（火）。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "    陆陈先开口了：“";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	for (int i = 0; i < m_player->Name().length(); i++) {
		Sleep(10); // 每个字符输出前等待10毫秒
		cout << m_player->Name();
	}
	background = ",你难道不记得我了吗？在我六百岁这年，因为我实在是太爱写人类作业了，飞船里面堆满了我写完的作业。我的母亲实在是受不了了，就让我去飞船旁边的公园帮其他的小朋友写作业。我等了整整一天都没有人来找我 ，根本就没有人相信我。不过，后来……你来了，你把你的寒假作业全部都给我了。当时，我特别特别高兴(〃'▽'〃)……”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    你想起来了，当时好像是因为你不想写作业，想把它们都藏起来，才去的公园，结果才刚把作业交给一个自称可以帮你写作业的大哥哥你妈就把你拽走了，还因为作业不在了又给你买了三本60页的“快乐寒假”。 ";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    “还有我还有我，我来人类世界的第一天实在是太饿了，就进了一家兰州拉面店。我看到你只吃了一碗牛肉面就走了，旁边还有一碗牛肉面却没有动。我就把剩下的吃了……我现在都还记得那个味道o(╥﹏╥)o”陈冰赶忙说。 ";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl<<endl;
	system("pause");
	cout << endl;
	background = "    原来是因为你平时去那家面馆都吃两碗面，老板以为你还和平时一样，就给你煮了两碗面。但那天你其实已经吃饱了，只吃得下一碗，就离开了。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    “至于我嘛……”陈凡淡淡开口。“只是看到一个小女孩在游乐园门口哭着拉着她爸妈的手要继续玩，不想回家才记住你的，仅此而已。ᗜ ‸ᗜ”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    “你别听这么说，他自从那天后就收购了那个游乐园，想要再次见到你（>_<），结果那之后你就再也没来过了。”陈冰笑嘻嘻地说道。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	cout << endl;
	background = "    不过最后你白了他们一眼便离开了，心想：学校怎么让这些莫名其妙的人进来了。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
}