#include <bits/stdc++.h>
#include<fstream>
#include <Windows.h>

void end(){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "幸亏和肥遗的战斗并没有破坏飞船，飞船降最终落在了实验室。在这个外星实验室中，一切都超出了你的想象。实验室的墙壁和天花板由一种未知的透明材料构成，它们散发着淡淡的蓝光，仿佛是外星夜空的缩影。和你从前看到了科技大片的景象截然不同，这里生机盎然，被绿色植物包裹"  << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " 植物藤蔓代替了精密的机械手臂，加工着不知道什么物品。墙壁上镶嵌着无数的符号和图案，这些可能是他们星球的文字和符号，在光线的照射下闪烁着奇异的光芒。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "实验室的中心是一个巨大的环形平台，平台上悬浮着各种未知的实验设备，它们悬浮在空中，没有任何支撑。平台的中间，一个全息投影仪正在展示太阳系的星系模型，星系中的每一颗星星都以不同的颜色和亮度闪烁着，而地球格外明显。上面显示了一行你看不懂的文字，而陈冰看了一眼，急忙对你说：“不好！还有十分钟毁灭装置就要启动了！我们得赶紧关闭这个装置！”";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "“你们就别白费力气了！知道我为什么要毁灭地球吗？”一个男人从实验室底部缓缓升上来。他的身材高大而瘦削，穿着一件破旧的白大褂，上面有各式各样的痕迹和烧焦的洞。他的皮肤苍白，几乎透明，显露出底下的血管和神经，脸上戴着一副方形的金属框眼镜，镜片后的眼睛此时变得猩红。";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "他没有在意你们的反应，继续自言自语。“从地球形成之初，我就注意到你们这个星球了。起初我也没在意，但没想到你们名为人类的物种进化得如此之快。恐龙是我给过时间最多的物种了，但他们还是太愚蠢了，我给了他们这么长的时间也没有达到让我满意的智慧，所以我最终让他们消失了。而你们人类，没想到就在我眨眼的这么点时间就进化成了这样。于是我降下了疾病，战争，人和人之间的猜忌，没想到你们还是发展得如此之好。没办法，你们已经有科学家发现了我们星球的痕迹，我只能消灭你们了……”";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "毁灭装置应该如何暂停？你们四人又该何去何从？地球是否会被毁灭？欲知后续如何，请期待《光之国奇遇记》……";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
}

