#include <bits/stdc++.h>
#include<fstream>
#include <Windows.h>
#include "Maze.h"
#include "Story.h"
using namespace std;

void Story::showStory(int id){
	
	if (id == 2) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "����������Ϣ��¥��" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " ͬѧ����������������һ��С�������ۣ���Ӱ��涣�����͸���޴����ش��������������ܿ���СС�Ļҳ��ڿ�������Ʈ�䡣 ����������ƽʱ�����ĵ�һ�ţ���ʼ׼���α����ȴ����ϿΡ��Ͽκ���ĵ�ʦ�����ǽ������µ����̣���Ȼ����֮ǰ��½�¡� ����������˲�䣬���ŵ�һ��Ũ����ѩ��ζ���������뵽��ңԶ��ͯ��ʱ�ڣ����ż��ź����һƬ�޴��ɭ�֣��ڶ��죬����ѩ�����ڴ���ϣ�һ���������㶼������ԡ�����������ķ����С�";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = " �㲻�����Աߵ�ͬѧ�������ŵ�ʲô���ص�ζ�����𣿡���ҡҡͷ��˵����û�а�����û�ŵ�ʲô��ֵ�ζ�������� һ���ÿ��㶼������֮�У��Ĳ����ɵ��ڿα���д���ˡ���������֡������¿��彫����������ʵ������ʰ����׼���뿪��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "����æ׷���㣬˵����XX��������ʱ�վ�����������ģ�ֻ��������������е�һ�������������������δ��������е�ʮ���ɻ�,�����뿪�ں���˵ʲô���������Ѿ����ˣ��㱻��Ⱥ����������Ľ��䣬��½��ȴ����Ⱥ�������⣬��ֻ����½�´��������ڵ����⺰��ʲô�����ӣ�����ȴһ����Ҳû������ ";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "�����Ż������ϣ���Ťͷһ����һƬ���ʵ���Ҷ��ȴ�����س���������ļ�ͷ��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}
	
	else if(id==3){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�����塭��������ֻ��������ˣ����ͨ�����İ���绰�����洫��һ���Գ�������˵����˵�����������������M78���ƣ���֮����MINMIN�����ǵ�����������ǵ�����300����ꡣ��������������������������ͽ��������Ҫ�ı�������ˣ���ϧΥ������������ķ��ɣ���Խ�涴�������������򡣲����������ھ������z�Ǳ��Ұ��ţ������������ǰɣ��ɹ��Ļ��һ���������ڵĽ������ҿ���һ��ʵϰ֤��������������������Ǿ����������ɣ���������������ʵ����̫Σ���ˣ�����������������������������" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " ԭ�����������˽ӵ���AI�ϳɵ���ı����¼�񡣽���˵����ʵ����ͣ����ȥ���ˣ����ܲ�˵����������ͣ����ȥ���ˣ���Ӱ��˵������Ϸ��ͣ����ȥ���ˣ�����������֪������ȫ����û��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = " �����ڲ�û�д򶯴�����ǡ���ѩ�������㣬���뵽ǰ����Ĺ����¼����Լ�ʵϰ֤�������Ķ��ˡ�����������̤�������ȴ���������������˵ĵ�·.....";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}
	
	else if (id == 4) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "��ȹ���ƽ����һ�����ϣ���������Է׼��������ζ�ķ��ˡ������������ʱ�䣬ƽʱ���ӵ�ʳ�ý���ȴ����һ�ˣ�������һ����ζ����Ѽ�������¿�ʼ���á������ǰ��һ����ζ����Ѽ����һ�龭���������Ƶ�Ѽ�Ȱ����׷��м䣬��Ƥ���ý���ִ࣬������ܻ�Ϳ��һ�����ƵĽ��ϣ������������۶�֭������һҧ����֭���ڿ������磬ɢ����Ũ�����������Աߵ��̲���Ϊ������������ζ�ĸ��ӿڸС����׷�������Ѽ��ľ�����ÿһ�����Եø��ⱥ������˺ͻƹ�Ƭ����Ϊ������������һĨ���µ�ɫ�ʣ�ҲΪ�ڸд�����һ˿ˬ�ࡣ" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "��һ�ᣬ�ܲ������������ǰ��˵�����ⶰ¥���ҳа��ˣ����Ѿ��������˵ȶ��뿪�ˣ�����ֻ���������������к���Ҫ����������㡣�ܲ�˵������XX��������ʱ�վ�����������ģ�ֻ��������������е�һ�������������������δ���������ʵ��������������Ǻϻ���ƭ������Ҳ̫�����˰ɡ���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = " �ܲø��뿪�ڣ�����ȴͻȻ�ε��ˣ���ʶģ������ֻ�����ܲý��㱧�ڻ��в��ϵ�ҡ��������壬�������ѹ���������ƤȴԽ��Խ�������ձ�����˫�ۡ�����ʱ���Ѿ�������УҽԺ�Ĵ��ϣ���Χ����һ�ˣ��ԱߵĹ����ϵĻ�ƿ�����һֻ���տ���ֱֱ�س��Ŵ����ķ����㳯���Ǹ�������ȥ����ΧһƬ�ž�����ձ�Ⱦ����Ⱦ�ü���Ѫɫ��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	
	else if (id == 5) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "������������Ī������Ļ����������ۺ���ͼ�����Ҫ��������鼮���������¼���Ҫ���ķ�������أ�����ʵ��û��ͷ������ֻ�������ų���Ȼ�����鼮�������ȥ�� ����֪Ϊʲô�����¥��ѧ���������ϵ��١�������Ҳ����˿˿���⣬�����ǿյ����˰ɣ������롣 ��������ܺ����ߣ��ƹ�Ҳ��֪��ΪʲôԽ��Խ������ӿ��˽Ų������ŸϽ��ҵ��˿������" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "����������23D47�š����ҵ��ˣ��������վ������һ������������ļ�����ͷһ����ԭ����Ӱ�ۡ�ֻ�������ű��ڱ����Ͻ�����д��ʲô��Ȼ��˺��������Ž��������������㱻�����ĵ��¶��̵��������ؿ�����ǰ���ˣ���������������ô���£���ȴͻȻ����ϵĵ�����Ļһ�㣬����˺����Ƶ�����������˸���κ�����۳�һ��С�㣬��ʧ�ˡ��������崻��˼�����㼱æ�����е�ֽ��չ�����ּ�Ҳȫ����ʧ����Ӱ���٣�ֻ����ǳǳ��ӡ�ӣ������ģ���ؿ��������֣���γ�ȣ����ӡ���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = " �ž��ķ�����ֻʣ�����ͷ���谵�ĵƹ⣬�������������Ļ�߬������ֽ����������ʼ���ɸոշ�����һ���ǲ�����Ļþ���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}
	
	else if (id == 6) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "���ǵ�����ǰ����վ��·�ϲ����˱����绰��ͻȻ��������������������ͻȻ�ۼ���һ�ţ��·�Ҫ���ŵ���ѹ����һ���Ӿ͵�ס��ԭ�����ʵ���ա�һ��UFO�������г������һ��ǿ�ҵĹ��������ϣ����ҵķ����������ͻҳ����·�Ҫ��һ������˺�飬�㲻�ɵñ������ۣ���һ���ۣ�һ��������ֻ�۾��������ȣ��Ϳƻ�Ƭ�ﳤ��ʮ�����Ƶ������˳����������ǰ����Χ�����˺ͳ���Ҳȫ��ͻȻ��ͣ������ҶҲֹͣ�˲���������������������������HD227��������빥ռ�����СA��Ҫȥ�����������˵���ͨ������أ�������ͨ��һ��С��Ϸ����һ��ս�ɣ���������" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
		
		//�Թ�
		 
	Maze maz(m_player);
	
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�ɹ��߳��Թ���������ȴͻȻ������ĭ��ʧ�ˣ�һ�лָ��������·���������ʱ�����ڰ�������������·�˿�ʼ���ߣ�������ʼ���ۣ���Ҷ��ʼɳɳ���졣�����ǰͻȻ����һ���֣����ɹ�����СA�����������½�¡��·����±������е�һ�ˣ���Ҫѡ��˭����" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " �ո�ѡ��ú�һ����������������ԣ����������������ǰ��һ���𾪡��������ر�ס�㣬��̫���ˣ����ڼ������ˡ��������ǵ��۾����̲�ס�������Ứ����Ĭ�˼����Ӻ�������˵���˷�����һ�У�����һ��ͬ�⣬���Ǿ���ȥz��һ̽������";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "��ͷһ�������ϻ�����������ǰ�����Ļ�Ʊ��һ��ħ�ȣ����ħ���ڲ��ƺ���Ƕ��ʲô��ʯ��ľ�ʵ�����������·����ħ���ڲ������������ؿ�������������ɫ��ı�ʯ����Ʊ�����������д�����ǵ����֡��������Ǽ����Ʊ��ħ��ǰ��������Ļ�վ̨��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout<<"\033[31m"<<"�ɹ�����һ�����������ǰ�����ĳ�Ʊ��ħ�ȣ�"<<"\033[0m"<<endl;
	cout << endl;
	}
	
	else if (id == 7) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�������˽����˷�����������ǰ��һƬ������ͷ�ĺڰ���һ��Ƭ�յ���ֻ��������������������в�֪���ķ��˶�õĻ������ݶ�Ҳ�����������������������СС�Ŀף������ս����Ĺ⵹ʹ���������������ʲôҲ��������֪������������ˮ����һƬ��̦�������յε����ϣ������γ��˼�����С������ˮ�ݡ����߻������O�O�@�@������������ǿ���������������������ʲô���������㳯ǰһ��һ�����ţ������������������Ұ������Լ�����ˣ���" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "һȺ��ѹѹ�ĵľ޴������������ǵ���ǰ������ߵ���һֻ��ɫ����������Ĺ��Ŀ�������׶�ߣ���һ���������ŵ��ٶȳ����������������ǰͻȻ����һ���֣�QQ����ʷ��ķ��֮ǰ������һϵ�������Ѿ�������ֲ����ˡ�";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = " ʷ��ķ���Ա���һ����������ι������ȫ��������ɫƤ�������Ҹ���ֻ���ÿһֻ��򶼿���ޱȣ���ë������ĵ��С�����������һ��������һͷ����������ô��Ĵ��ӣ���������˹��ϵķ��ġ����������߽�����Χ���¶�ҲԽ��Խ�͡�����һ��ŭ���ͷ��������һֻ�޴����ɫ֩����ﻺ���ؽ����������������Ӵ��ޱȣ�ÿһֻ�ȶ���������ô�֣����渲���ż�Ӳ����ɫ�ۼף���΢������������˸���İ��Ĺ��󡣰�ֻ�۾���ͬȼ�յ���ɫ���棬�����ɨ�������ܣ�������һ��񺮡�������������絶�����������˵����Ķ�Һ��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}
	
	//ս��
	
	else if (id == 8) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�̵겢�����ң�����z�ǽ����ڵ�λ�ã��������һ���ľ�ƣ�������š����������������֡������̵꣬������İ˸��ȷ�������ӭ���١���һ����ӳ����������һλ�Ͱ��ĸ���վ��������̨���棬������һϮ��������ۣ�����һ��ѩ�׵�Ƥ�����ף�ͷ����һֻ���ŵİ�������ţ�������������ע�������ǣ��˸���������ı���������ͷ������ȥ��Ҳ����ض������ǡ�" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " СС���̵꼷���˸�����Ʒ��ȫ��������ľ�ʵ�չʾ���ů�Ƶĵƹ����ţ����������΢�⣬�Ե�����¶���С����ܰ����ࡣ";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "�������Ѿ����û���˹�����ء�����λ���ˣ�������Ҫʲô�أ�����Ӧ�о��С������Ĭ���ֻ�ǿ�ʼ��ѡ��Ҫ������������������Ҳ��һ��һ��ѯ������Ҫʲô����������û�뵽��ô�����۵�С��ȴ������ô������������� ";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}
	
	else if (id == 9) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�����������Ķ�����һ�ҿ��ȵ꣬ͬ����ľ�ʷ��һֻ���ֵ���è�����ſڴ���ϰ���һλ��������ԣ��������Ǻ��Ǿ��ȣ�Ȼ������Ľ����������˿��ȵ꣬�����ţ�����С����û�й˿��ˣ����ǿ쿴�����ʲô���ҵĵ���Ķ������ǿ��Իָ�������Ŷ����" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	}
	
	else if (id == 10) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�𳵻�����ǰ���ţ�������Ⱥ����������ÿһվ�������ϳ���Ҳ�����³��������ϵ���Խ��Խ�٣��ڵ����յ�վ��ǰһվ�������˶����˳�������ֻʣ���������˿ͣ�������������ֻʣ�𳵳����г�Ա�����վ���������ҹ�𳵵ĵ�������������������߾�������Ҳ��һ�ο������г��������Ӽ�ʻ���߳�������Ȼ������ݣ�������ͣ�������������ܲ���" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = " ���ź���֪ͨ���ǣ�������յ���վ�����޷��������ڲ����룬����ֻ�����˻𳵣���ʼѰ��ǰ��z�ǵķ������ڻ��Ź��ϵ�ǰһ�̣��������г�������ϣ����������Ҫ���Ͱ���С��������յ��վ��Χ��һ���������ֵļ��У��������˸�ʽ��������Ʒ�������������ڶ�����ʯ����觡������������ذ���̯��ǰ�ļ����ϣ����ǵļ���ǰ�����������ĺ�������д�˹�棬��������Ⱥ��Ҳ�ܿ���һ������Ϥ����ס�";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "���������ߣ����Ǿ�¥��������ṩס�޵ľƵꡣ�����඼�������ľ�ʽ�������¥�Ĵ������ţ��������������Ĵ�Ц�������������������������򵱵ص��̷�����z�Ǻ󣬴��Ҫô���ɻ�������㣬��ڲ��ԣ�Ҫô�������������̴�����������Ͽ��� ";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "���գ�һ�����˺����ĵ��������˵�������ҳԶٱ������Ҿ͸�������z����ôȥ���������������ȥ���Աߵ�С���ݣ����������̻��ʵس�����һ�������ˡ������֪����ԭ��z�������󲿷ִ���թƭ������ѵ㣬�������ر����أ�������Ҫ��������������ȥ��������������Ǯ�����ɣ�����ס��ɽ���Ƕ�ľ������������û�и����㣬���ɲ��Ǹ����ǵĽ�ɫ��������̧ͷ˳����ؤ����ָ�ŵķ��򿴹�ȥ��һ��СС��ľ�ݾʹ������ǡ�";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "ɽ����һ��Ψһ��С·ͨ��ɽ�ϣ�������������������ţ��������뵽����û�л�ͷ�������ߵ������ˣ�ֻ�ܼ�������ȥ�ˣ�ϣ�������ܹ�����ϵ�����һ��������Ǿ͵�����ľ��ǰ��������һ�������ľ�ʽ�������������ݶ����̴��Ѿ�ð���˰��̣�һ�е�Ҳ�Ե����¾��á�һ������˶��Ļƹ���˨���ſڣ���û����ǰ�����Ϳ�ʼ�������ǽС���Ǯ�����͵����ſڣ�����һ����Ŀ��࣬�������ӵ��������ˣ���Ȼ�����Ѿ���Щ�߰ף������ܿ�������������侭�����ȷ�Ѫ��ĺۼ���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "����Ȼ����һ��Ů��Ҫȥz�ǣ�����¶��������⴫���ˣ�С�����Ȱ���̫�����������������������Ļ���˵�������ǲ��Ǵ��������õ�ȥz�ǵĵ�ͼ����ϻ��ˣ���һ��ս�ɣ��� ";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout<<"\033[31m"<<"�ɹ�����һ���������������һ�ݺ�z�ǵ�ͼһ�ݣ�"<<"\033[0m"<<endl;
	cout << endl;
	background = "ͽ���߹�Σ�յ����󣬶����ܲ��Ĵ��֣�����ļ��ĺ���������Խ��Խ������Ƭ���ء��������z�Ǻ󣬰�˷���GPS��λ��˵������������Ǯ�������Ҿ�֪������Ҫ���ˣ�û�뵽���������˾�Ȼ���ߵ��⡣�����С���ﻹ����Ů���е�Ů�ˣ������еĴ��ԣ�̫�����ˣ�������������һ���ʱ��׼���������������Ұɣ���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
}

    else if (id == 11) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("cls");
	cout << "�������Զ���ʻģʽ��ǰ����֮�������±�˵��߿�ʼ�������������ԭ��XXX�ǹ�֮����һ����ѧ�ң�����ʮ��ʹ�޵����ˣ����������ž������з���׼���������ķɴ����������ʱ��ֹ��������������롣" << endl << endl;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	string background = "���ɻ��ѣ��ʵ�����Ϊʲô����Ҫ�������������أ�������������������𣿡������������ڹ�����֯ά�Ͳ��������Ƿ������������������������Ϊ�ģ����������Ҫ��ֹ����������������ſ��ԶԿ�XXX�Ĺ�֮��������ˣ�������Ҫ���Э������½��������͵������������������˵������㣬xxxʵ����̫��Ȥζ�ˣ����趨�Ļ�����ֹװ�þ���������������������������ַ����ˣ����԰�����ץ�˻�ȥ�����·�Ҳ�߷ߵ�˵�š��㿴�Ŵ���ľ�������˵����˲�䣬���Ǿ��Ѿ����˵�����㣬�㿴�������ɫ������˼����ǧ��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "���������˳�Ĭ֮�С���ǰ����֮������������ɴ��Ĺ㲥����������Ը�������һ�����ȵ����𣿡����������˾�����ֱֱ�������㡣�������˽��ִ���һ����ش𣺡���Ȼ����";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "������ͻȻ����һ���У�������������������Դ��ȥ��һֻ����Ĺ��޳�����������ǰ������ͷ����ʨ�ӣ���ȴ��������������쳣���������ݷ�����������������������ӣ����ų����Ĳ��ӣ�������Χ����һȦ����ɫ��ë����ͨ���ɫ��һ˫���������һ�㣬�������������׳���Ҳ͸¶�ŵ����ĺ�ɫ����ֻ������ӥһ�㣬����׳�öࡣ�������ǵ�λ�ú�����ͬ����һ�㳯���ǳ�����һ��ս���ڷɴ���չ����";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	
	//ս�� 
	
	background = "�ҿ��ͷ��ŵ�ս����û���ƻ��ɴ����ɴ�������������ʵ���ҡ����������ʵ�����У�һ�ж��������������ʵ���ҵ�ǽ�ں��컨����һ��δ֪��͸�����Ϲ��ɣ�����ɢ���ŵ��������⣬�·�������ҹ�յ���Ӱ�������ǰ�����˿Ƽ���Ƭ�ľ����Ȼ��ͬ������������Ȼ������ɫֲ�����";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "ֲ�����������˾��ܵĻ�е�ֱۣ��ӹ��Ų�֪��ʲô��Ʒ��ǽ������Ƕ�������ķ��ź�ͼ������Щ������������������ֺͷ��ţ��ڹ��ߵ���������˸������Ĺ�â��";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "ʵ���ҵ�������һ���޴�Ļ���ƽ̨��ƽ̨�������Ÿ���δ֪��ʵ���豸�����������ڿ��У�û���κ�֧�š�ƽ̨���м䣬һ��ȫϢͶӰ������չʾ̫��ϵ����ϵģ�ͣ���ϵ�е�ÿһ�����Ƕ��Բ�ͬ����ɫ��������˸�ţ�������������ԡ�������ʾ��һ���㿴���������֣����±�����һ�ۣ���æ����˵�������ã�����ʮ���ӻ���װ�þ�Ҫ�����ˣ����ǵøϽ��ر����װ�ã���";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "�����Ǿͱ�׷������ˣ�֪����ΪʲôҪ��������𣿡�һ�����˴�ʵ���ҵײ�������������������ĸߴ������������һ���ƾɵİ״�ӣ������и�ʽ�����ĺۼ����ս��Ķ�������Ƥ���԰ף�����͸������¶�����µ�Ѫ�ܺ��񾭣����ϴ���һ�����εĽ������۾�����Ƭ����۾���ʱ����ɺ졣"
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "��û���������ǵķ�Ӧ����������������ӵ����γ�֮�����Ҿ�ע�⵽������������ˡ������Ҳû���⣬��û�뵽������Ϊ��������ֽ��������֮�졣�������Ҹ���ʱ�����������ˣ������ǻ���̫�޴��ˣ��Ҹ���������ô����ʱ��Ҳû�дﵽ����������ǻۣ�������������������ʧ�ˡ����������࣬û�뵽������գ�۵���ô��ʱ��ͽ������������������ҽ����˼�����ս�����˺���֮��Ĳ¼ɣ�û�뵽���ǻ��Ƿ�չ�����֮�á�û�취�������Ѿ��п�ѧ�ҷ�������������ĺۼ�����ֻ�����������ˡ�����"
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	background = "����װ��Ӧ�������ͣ�����������ָú�ȥ�δӣ������Ƿ�ᱻ������֪������Σ����ڴ�����֮�������ǡ�����";
	for (int i = 0;i < background.length();i++) {
		Sleep(10);
		cout << background[i];
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	}

void Stroy::Run(){
	int id = m_player->currentRoom();
	room m_room = m_player->currentRoom();
	Fight fight(m_player);

	if (m_room->Task()) {
		if (id == 6) {
			//�ൺ����վ
			showStroy(6);//����+�Թ�
			m_room->Task() = false;
			m_player->addNPC();

			//ľ��
			showStory(10);//ľ�ݾ���
			fight.ProceedFight();

			m_Player->currentRoom() = 7;

			map_points = 2;
		}
		else {
			showStroy(id);
			m_room->Task() = false;
		}
	}
}
