#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include "Entity.h"
#include "Player.h"
#include "DatabasePointer.h"
#include "Game.h"
#include "CommandExecutor.h"
#include "Fight.h"
using namespace std;

extern string lowerCase(string str);

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

void End() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "幸亏和肥遗的战斗并没有破坏飞船，飞船降最终落在了实验室。在这个外星实验室中，一切都超出了你的想象。实验室的墙壁和天花板由一种未知的透明材料构成，它们散发着淡淡的蓝光，仿佛是外星夜空的缩影。和你从前看到了科技大片的景象截然不同，这里生机盎然，被绿色植物包裹" << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " 植物藤蔓代替了精密的机械手臂，加工着不知道什么物品。墙壁上镶嵌着无数的符号和图案，这些可能是他们星球的文字和符号，在光线的照射下闪烁着奇异的光芒。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "实验室的中心是一个巨大的环形平台，平台上悬浮着各种未知的实验设备，它们悬浮在空中，没有任何支撑。平台的中间，一个全息投影仪正在展示太阳系的星系模型，星系中的每一颗星星都以不同的颜色和亮度闪烁着，而地球格外明显。上面显示了一行你看不懂的文字，而陈冰看了一眼，急忙对你说：“不好！还有十分钟毁灭装置就要启动了！我们得赶紧关闭这个装置！”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "“你们就别白费力气了！知道我为什么要毁灭地球吗？”一个男人从实验室底部缓缓升上来。他的身材高大而瘦削，穿着一件破旧的白大褂，上面有各式各样的痕迹和烧焦的洞。他的皮肤苍白，几乎透明，显露出底下的血管和神经，脸上戴着一副方形的金属框眼镜，镜片后的眼睛此时变得猩红。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "他没有在意你们的反应，继续自言自语。“从地球形成之初，我就注意到你们这个星球了。起初我也没在意，但没想到你们名为人类的物种进化得如此之快。恐龙是我给过时间最多的物种了，但他们还是太愚蠢了，我给了他们这么长的时间也没有达到让我满意的智慧，所以我最终让他们消失了。而你们人类，没想到就在我眨眼的这么点时间就进化成了这样。于是我降下了疾病，战争，人和人之间的猜忌，没想到你们还是发展得如此之好。没办法，你们已经有科学家发现了我们星球的痕迹，我只能消灭你们了……”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "毁灭装置应该如何暂停？你们四人又该何去何从？地球是否会被毁灭？欲知后续如何，请期待《光之国奇遇记》……";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
}


void ShowBackground(Player* m_player) {
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
	cout << m_player->Name();
	background = "。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	background = "    你的美丽如同初升的朝阳，温暖而耀眼，让人不禁为之心动。你的笑容犹如春日里绽放的花朵，清新脱俗，充满了生机与活力。你的眼睛闪烁着星辰般的光芒，深邃而迷人，仿佛能洞察人心。你的每一次微笑，都如同春风拂面，让人沉醉在这份温柔与美好之中。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	system("cls");
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	background = "    这天晚上你正在操场上散步，突然三个英俊的男人出现在你的面前，并说他们才是你未来的的真爱，你疑惑地看了他们一眼。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	background = "    他们在你面前从左到右依次介绍自己。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	//cout << endl;
	//system("pause");
	cout << endl;
	background = "    他们分别是：年轻的大学教授陆陈（草）、上市公司总裁陈凡（金）、实力派影帝陈冰（火）。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	SetConsoleTextAttribute(hConsole, 14);
	system("cls");
	cout << endl;
	background = "    陆陈先开口了：“";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << m_player->Name();
	background = ",你难道不记得我了吗？在我六百岁这年，因为我实在是太爱写人类作业了，飞船里面堆满了我写完的作业。我的母亲实在是受不了了，就让我去飞船旁边的公园帮其他的小朋友写作业。我等了整整一天都没有人来找我 ，根本就没有人相信我。不过，后来……你来了，你把你的寒假作业全部都给我了。当时，我特别特别高兴(〃'▽'〃)……”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl << endl;
	background = "    “你想起来了，当时好像是因为你不想写作业，想把它们都藏起来，才去的公园，结果才刚把作业交给一个自称可以帮你写作业的大哥哥你妈就把你拽走了，还因为作业不在了又给你买了三本60页的“快乐寒假”。 ";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	background = "    “还有我还有我，我来人类世界的第一天实在是太饿了，就进了一家兰州拉面店。我看到你只吃了一碗牛肉面就走了，旁边还有一碗牛肉面却没有动。我就把剩下的吃了……我现在都还记得那个味道o(╥﹏╥)o”陈冰赶忙说。 ";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl << endl;
	background = "    原来是因为你平时去那家面馆都吃两碗面，老板以为你还和平时一样，就给你煮了两碗面。但那天你其实已经吃饱了，只吃得下一碗，就离开了。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	background = "    “至于我嘛……”陈凡淡淡开口。“只是看到一个小女孩在游乐园门口哭着拉着她爸妈的手要继续玩，不想回家才记住你的，仅此而已。ㅎ.ㅎ”";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl << endl;
	background = "    “你别听这么说，他自从那天后就收购了那个游乐园，想要再次见到你（>_<），结果那之后你就再也没来过了。”陈冰笑嘻嘻地说道。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 0);
	system("pause");
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	background = "    不过最后你白了他们一眼便离开了，心想：学校怎么让这些莫名其妙的人进来了。";
	for (int i = 0; i < background.length(); i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);
	system("pause");
	system("cls");
	cout << endl;
}



void ShowTitle() {
	cout << "\033[33m";
	cout << "              $$                    $$                     $$$                 $       $   " << endl;
	cout << "            $$$$$$$$$$$$$$$       $$$                      $$     $      $$    $$$$$$$$$$$     $$           $ " << endl;
	cout << "           $$  $$$$$$$$$$$$$     $$$         $      $$$$$$$$$$$$$$$$      $$   $$$$$$$$$$       $$  $$$$$$$$$$$" << endl;
	cout << "           $$ $ $   $    $       $$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$       $$  $$$$$$$$$$        $$ $$$$$$$$$$ " << endl;
	cout << "          $$  $$$$$$$$$$$$$     $$$$$$$$$$$$$$$           $$$$             $$  $$$$$$$$$$        $          $$" << endl;
	cout << "          $  $$$$$$$$$$$$$$     $$       $   $$          $$  $$$$              $$  $$  $$        $          $$" << endl;
	cout << "         $$$$$$ $$ $$ $$ $$    $$$$$$$$$$$$  $$        $$$     $$$         $   $$$$$$$$$$    $$$$$$  $      $$ " << endl;
	cout << "       $$$$$$  $$ $$ $$ $$   $$$$$$$$$$$$$  $$      $$$        $$  $   $$$$$$$$$$$$$$$$$    $$$$$$  $$$$$$$$$ " << endl;
	cout << "         $  $$  $$ $$$$$ $$  $$ $$   $$  $$  $$   $$$$$$$$$$$$$$$$$$$$  $$$$$ $$$$$$$$$$$$      $$   $$$$$$$$$ " << endl;
	cout << "           $$   $$ $$$$$ $$  $  $$$$$$$$$$$  $$    $$$$$$$$$$$$$$$$$$$     $$ $$$$$$$$$$$$      $$   $$     $$ " << endl;
	cout << "           $    $$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$   $$$$ $$      $$   $$        " << endl;
	cout << "         $$$$$$$$$ $$$$$ $$     $$   $$  $$  $$       $$$$$$$   $$         $$ $$   $$$$$$$      $$   $$        " << endl;
	cout << "         $$$$$  $$ $$$$$ $$     $$   $$  $$  $$       $$   $$   $$         $$ $$$$$$$$$$$$      $$   $$       $$" << endl;
	cout << "         $      $$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$ $    $$$$      $$ $$$$       $$" << endl;
	cout << "            $$$$$$ $$ $$ $$     $$$$$$$$$$$  $$       $$$$$$$   $$         $$ $$      $$$$      $$$$ $$       $$ " << endl;
	cout << "        $$$$$$  $$$$$$$$$$$     $$       $$  $        $$   $$   $$        $$$ $$       $$$      $$$  $$       $$ " << endl;
	cout << "        $$     $$$$$$$$$$$     $           $$                  $$       $$  $$           $$   $$$   $$$$$$$$$$$  " << endl;
	cout << "                $$       $$              $$$$$               $$$$$      $$   $$$$$$$$$$$$$$     $     $$$$$$$$$  " << endl;
	cout << "                $$       $$                $$                  $$$              $$$$$$$$$$                       " << endl;
	cout << "\033[0m" << endl << endl << endl;

	cout << "\033[36m" << "\t\t\t\t\t\t开始新游戏【请输入new】" << endl << endl;
	cout << "\t\t\t\t\t\t继续游戏【请输入continue】" << endl << endl;
	cout << "\t\t\t\t\t\t退出游戏【请输入quit】" << "\033[0m" << endl << endl;

}




int main() {
	Game game;
	CommandParser commandpar;
	string input;
	bool isStart = false;

	do {
		system("cls");

		ShowTitle();

		cout << "\t\t\t\t\t\t> ";
		getline(cin, input);
		input = lowerCase(input);

		isStart = game.First(input);
	} while (!isStart);

	Player* m_player = Player::getPlayer();

	/*if (input == "new") {
		ShowBackground(m_player);
	}*/

	while (1) {
		system("cls");
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		game.PrintPrime();

		cout << "> ";
		getline(cin, input);
		input = lowerCase(input);

		if (input == "map") {
			system("cls");
			game.Mape();
		}
		else if (input == "attack") {
			if (m_player->currentRoom()->Enemies().size() == 0) {
				cout << "没有敌人，calm down。" << endl;
				Sleep(1500);

				continue;
			}

			Fight fight(m_player);
			fight.ProceedFight();
		}
		else if (input == "npc") {
			game.NPC();
		}
		else if (input == "bag") {
			game.Bag();
		}
		else if (input == "quit")
		{
			break;
		}
		else {
			CommandExecutor commandexec(m_player);
			Command cmd = commandpar.Parse(input);
			commandexec.Execute(cmd);
		}

		if (m_player->Task() == 3) {
			End();
			break;
		}
	}
}

