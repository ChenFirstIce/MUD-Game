#include <cstdio>
#include <windows.h>
#include <conio.h>
//8*12
char a[50][50]={"############",
				"#O#    #   #",
				"#   ## # # #",
				"#####    # #",
				"#     #### #",
				"# #####  # #",
				"#       ##  ",
				"############"};

void Hide()//�������ؿ���̨��� 
{
	HANDLE				hOut;
	CONSOLE_CURSOR_INFO	curInfo;
	
	hOut=GetStdHandle(STD_OUTPUT_HANDLE); 
	curInfo.dwSize=1;
	curInfo.bVisible=0;
	SetConsoleCursorInfo(hOut,&curInfo);
}

void Welcome()//��ӭ���� 
{
    printf("\n\n           �� �� ��");
    printf("\n\n        �밴�������ʼ");
    getch();
    system("cls");
}

void Set()//���ù�굽��ʼλ�� 
{
	HANDLE hOut;
	COORD pos={0,0};
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos); 
}

int main()
{
	Hide();
	Welcome();
	int x=1,y=1;
	char ch;
	for(int i=0;i<=7;i++)
		puts(a[i]);
	while(1)
	{
		ch=getch();
        if(ch=='s')//��
        {
			if(a[x+1][y]==' ')
            {
				a[x][y]=' ';
                x++;
                a[x][y]='O';
            }
        }
        else if(ch=='w')//��
        {
			if(a[x-1][y]==' ')
            {
				a[x][y]=' ';
                x--;
                a[x][y]='O';
            }
        }
		else if(ch=='a')//��
        {
			if(a[x][y-1]==' ')
            {
				a[x][y]=' ';
                y--;
                a[x][y]='O';
            }
        }
        else if(ch=='d')//��
        {
			if(a[x][y+1]==' ')
            {
				a[x][y]=' ';
                y++;
                a[x][y]='O';
            }
        }
        Set();
		for(int i=0;i<=7;i++)
			puts(a[i]);
        if(x==6 && y==11)
        	break;
	}
	printf("��Ӯ�ˣ�");
	Sleep(10000);
	return 0;
}

