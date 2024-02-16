//大纲 
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
#define qdo 262 
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 590
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318 //和上一个相差143  1318+142=1460
#define fa1 1400// 相差162 
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1110
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865
#define do2 2100
//q前缀为低音，1后缀为高音，s前缀为半音阶
using namespace std;
string ap,bp;
int gamecnt;
int a1p[505],b1p[505],cp[514];//加法数组 
int loginchoice; //登陆选择 
bool agreeeula;//是否有eula.txt或help.txt 
int checkeula; //检查是否同意eula 
int qjoldosusingstudus; //检查是否使用过QJOL-DOS 
string cmd;	 //内部命令行 
string passcode;//密码、密钥  
bool Administrator;//管理员状态 
bool password;//密码状态 
char homo;//访客登录状态 
bool notlogin;//登录状态  
bool eulacheckreturnstadus;//eulacheck函数返回值 
int fuhao;//计算器符号 
char str1m[11451];
char str2m[11451]={};
int num1m[11451]={};
int num2m[11451]={};
int resm[11451]={};//减法数组
char str1c[11451];
char str2c[11451];
int num1c[11451];
int num2c[11451];
int resc[40000001];//乘法数组 
int numch[114514];
string ach;//除法数组 
//最大地图 
int RMap[55][55]={};//地雷地图 
int SMap[55][55]={};//展示地图 1显示 0 不显示 
//8个方位 
int posx[9]={-1,-1,-1,0,0,1,1,1};
int posy[9]={-1,0,1,-1,1,-1,0,1};
//设置展示地图
void setSMap(int h,int w)
{
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			SMap[i][j]=1;//覆盖状态 
		}
	}
} 
//初始化地雷地图 
void setRMap(int h,int w)
{
	for(int i=0;i<=h+1;i++)
	{
		for(int j=0;j<=w+1;j++)
		{
			RMap[i][j]=0;//一个雷没有 
		}
	}
} 
//设置地雷地图
void RsetRMap(int h,int w,int cnt)
{
	
	while(cnt)
	{
		int x=rand()%h+1;//第几行 
		int y=rand()%w+1;//第几列
		if(RMap[x][y]!=-1)//-1表示雷 0 表示没有  
		{
			RMap[x][y]=-1;
			cnt--; 
		} 
	}
	//看上下左右左上左下右上右下是否有雷，有的话当前不是雷设置雷的数字 
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(RMap[i][j]!=-1) 
			{
				for(int k=0;k<8;k++)
				{
					if(RMap[i+posx[k]][j+posy[k]]==-1)
					{
						RMap[i][j]++;
					}
				}
			}
		}
	}
}
//结束游戏地图 
void ShowEMap(int h,int w)
{	//打印地图
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{

				if(RMap[i][j]==-1)
					cout<<"★";
				else if(RMap[i][j]==0){
					cout<<"□"; 
				} 
				else
				{
					cout<<RMap[i][j]<<' ';
				}
		}
			
		cout<<endl;
	}
	
}

void ShowMap(int h,int w)
{	//打印地图
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(SMap[i][j]==1) 
			{
				cout<<"■";
			}
			else
			{
				if(RMap[i][j]==-1)
					cout<<"★";
				else if(RMap[i][j]==0){
					cout<<"□"; 
				} 
				else
				{
					cout<<RMap[i][j]<<' ';
				}
			}
			
		}
		cout<<endl;
	}
	
}

void Begin(int h,int w,int cnt)
{	
	setSMap(h,w);
	setRMap(h,w);
	RsetRMap(h,w,cnt);
	
}

//递归爆炸式展开一片
void ExplosionSpread( int row, int col, int x, int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col)  //判断坐标是否为排查范围内
	{
		
		if (RMap[x][y]==0)//周围一个雷都没有 
		{
			SMap[x][y] = 0;   //如果该坐标周围没有雷，就把该坐标置0，并向周围八个坐标展开
			int i = 0;
			int j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (SMap[i][j] == 1)    //没有排查过的点进行排查 
						ExplosionSpread(row, col, i, j);
				}
			}
		}
		else if(RMap[x][y]!=-1)
		{
			SMap[x][y] = 0;
		}
	}
}

//游戏逻辑 
void FindMine(int h, int w,int leicnt)
{
	Begin(h,w,leicnt);
	ShowMap(h,w);
	int x = 0;
	int y = 0;
	int win = 0;  //用来标记是否取得胜利
	char ch = 0;   //用来接受是否需要标记雷
	while (1)
	{
		printf("请输入你想要排查的坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= h && y >= 1 && y <= w)   //判断坐标合法性
		{
			if (RMap[x][y] == -1)
			{
				system("cls");
				printf("很遗憾，你被炸死了!\n");
				ShowEMap(h,w);//看答案
				break;
			}
			else
			{
				if (SMap[x][y] != 1)   //判断是否重复排查
				{
					printf("该坐标已被排查，请重新输入!\n");
					continue;  //直接进入下一次循环
				}
				else
				{
					ExplosionSpread( h, w, x, y);  //爆炸展开一片
					system("cls");  //清空屏幕
//					ShowEMap(h,w);//看答案
//					cout<<endl; 
					ShowMap(h,w); //打印棋盘

				}
			}
			//是否胜利
			int cnt=0;//打开的数目
			for(int i=1;i<=h;i++)
			{
				for(int j=1;j<=w;j++)
				{
					if(SMap[i][j]==0)
					{
						cnt++;
					}
				}
			 } 
			 if(cnt==w*h-leicnt) 
			 {
			 	cout<<"游戏胜利";
			 	break;
			 }
			
		}
		else
		{
			printf("输入错误，请重新输入!\n");
		}
	}
}
void mine()
{
	char jieshufu;
	srand((int)time(0));
	int h=20;
	int w=20;
	int leicnt=30;
    //选关 
    while(true)
    {
    	cout<<"\n按Q结束游戏:";
		cin>>jieshufu;
		if(jieshufu=='q' || jieshufu=='Q')
			return ;
		start:
		cout<<"\n输入地图的高(不超过53):";
		cin>>h;
		if(h>50)
		{
			goto start;
			system("cls");
		}
		cout<<"\n输入地图的宽(不超过53):";
		cin>>w;
		if(w>50)
		{
			goto start;
			system("cls");
		}
		cout<<"\n输入雷的数量(不超过250):";
		cin>>leicnt;
		if(leicnt>250)
		{
			goto start;
			system("cls");
		}
		if(h==1 && w==1 && leicnt==1)
		{
			cout<<"输入错误";
			Sleep(1145);
			system("cls");
			goto start;
		}
		FindMine(h,w,leicnt);     	
	}
	return ;
}
clock_t start,end1;//计时器 
void pvp()
{
	cout<<"你好，陌生人"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"QJOL Studios招生了"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"无论你是跑酷大神（从柱子上摔下）"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"生存大师"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<".";
	cout<<"还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<".."; 
	cout<<"还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"又或是起床大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<".还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"又或是建筑大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"还是pvp大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"又或是建筑大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"又或是红石大佬"<<endl;
	Sleep(1145);
	system("cls");
	cout<<"还是什么都不知道的小白"<<endl;
	Sleep(1145);
	system("cls");
	return ; 
 } 
void skymusic()
{
	int pai=400,ban=200;
	int ting=128;
	 
	Sleep(1000);
	 
	Beep(la,ban);
	Beep(si,ban);
	Sleep(ting);
	 
	Beep(do1,pai+ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(si,3*pai);
	Sleep(ting);
	Beep(mi,ban);
	Beep(mi,ban);
	 
	Beep(la,ban+pai);
	Beep(so,ban);
	Sleep(ting);
	Beep(la,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(so,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(mi,ban);
	Sleep(ting/2);
	Beep(mi,ban);
	Sleep(ting/2);
	 
	Beep(fa,pai+ban);
	Beep(mi,ban);
	Sleep(ting);
	Beep(fa,ban);
	Beep(do1,ban+pai);
	Sleep(ting);
	 
	Beep(mi,2*pai);
	Sleep(ting);
	Sleep(ban);
	Beep(do1,ban);
	Sleep(ting/2);
	Beep(do1,ban);
	Sleep(ting/2);
	Beep(do1,ban);
	Sleep(ting/2);
	 
	Beep(si,ban+pai);
	Beep(sfa,ban);
	Sleep(ting);
	Beep(sfa,pai);
	Beep(si,pai);
	Sleep(ting);
	 
	Beep(si,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(la,ban);
	Beep(si,ban);
	Sleep(ting);
	 
	Beep(do1,pai+ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(si,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(mi,ban);
	Sleep(20);
	Beep(mi,ban);
	Sleep(ting);
	 
	Beep(la,pai+ban);
	Beep(so,ban);
	Sleep(ting);
	Beep(la,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(so,3*pai);
	Sleep(ting+ban);
	Beep(mi,ban);
	Sleep(ting/2);
	 
	Beep(fa,pai);
	Sleep(ting);
	Beep(do1,ban);
	Beep(si,ban);
	Sleep(20);
	Beep(si,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(re1,ban);
	Sleep(20);
	Beep(re1,ban);
	Sleep(20);
	Beep(mi1,ban);
	Sleep(ting/2);
	Beep(do1,pai);
	Sleep(ting+pai);
	 
	Beep(do1,pai);
	Beep(si,ban);
	Sleep(ting);
	Beep(la,ban);
	Sleep(20);
	Beep(la,ban);
	Sleep(ting);
	Beep(si,pai);
	Sleep(ting);
	Beep(sso,pai);
	Sleep(ting);
	 
	Beep(sso,2*pai);
	Sleep(ting+pai);
	Beep(do1,ban);
	Beep(re1,ban);
	Sleep(ting);
	 
	Beep(mi1,pai+ban);
	Beep(re1,ban);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	Beep(fa1,pai);
	Sleep(ting);
	 
	Beep(re1,2*pai);
	Sleep(pai+ting);
	Beep(so,ban);
	Sleep(20);
	Beep(so,ban);
	Sleep(ting);
	 
	Beep(do1,ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(mi1,2*pai);
	Sleep(ting+2*pai);
	 
	Beep(la,ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(si,pai);
	Sleep(ting);
	Beep(re1,ban);
	Sleep(20);
	Beep(re1,ban);
	Sleep(ting);
	 
	Beep(do1,pai+ban);
	Beep(so,ban);
	Sleep(20);
	Beep(so,pai);
	Sleep(pai+ting);
	 
	Beep(fa1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	Beep(re1,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(mi1,4*pai);
	 
	Beep(mi1,pai*2);
	Sleep(pai+ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(la1,2*pai);
	Sleep(ting);
	Beep(so1,pai);
	Sleep(ting);
	Beep(so1,pai);
	Sleep(ting);
	 
	Beep(mi1,ban);
	Sleep(ting/2);
	Beep(re1,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting+ban);
	Beep(do1,ban);
	Sleep(ting);
	 
	Beep(re1,pai);
	Sleep(ting);
	Beep(do1,ban);
	Beep(re1,ban);
	Sleep(20);
	Beep(re1,ban);
	Sleep(ting);
	Beep(so1,pai);
	Sleep(ting);
	 
	Beep(mi1,2*pai);
	Sleep(ting+pai);
	Beep(mi,pai);
	Sleep(ting);
	 
	Beep(la1,2*pai);
	Sleep(ting);
	Beep(so1,2*pai);
	Sleep(ting);
	 
	Beep(mi1,ban);
	Beep(re1,ban);
	Sleep(ting);
	Beep(do1,2*pai);
	Sleep(ting+ban);
	Beep(do1,ban);
	Sleep(ting);
	 
	Beep(re1,pai);
	Sleep(ting);
	Beep(do1,ban);
	Beep(re1,ban);
	Sleep(20);
	Beep(re1,ban);
	Sleep(ting);
	Beep(si,pai);
	Sleep(ting);
	 
	Beep(la,2*pai);
	Sleep(ting);
	Beep(la,ban);
	Beep(si,ban);
	 
	Beep(do1,pai+ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(si,3*pai);
	Sleep(ting);
	Beep(mi,ban);
	Beep(mi,ban);
	 
	Beep(la,ban+pai);
	Beep(so,ban);
	Sleep(ting);
	Beep(la,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(so,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(mi,ban);
	Sleep(ting/2);
	Beep(mi,ban);
	Sleep(ting/2);
	 
	Beep(fa,pai+ban);
	Beep(mi,ban);
	Sleep(ting);
	Beep(fa,ban);
	Beep(do1,ban+pai);
	Sleep(ting);
	 
	Beep(mi,2*pai);
	Sleep(ting);
	Sleep(ban);
	Beep(do1,ban);
	Sleep(ting/2);
	Beep(do1,ban);
	Sleep(ting/2);
	Beep(do1,ban);
	Sleep(ting/2);
	 
	Beep(si,ban+pai);
	Beep(sfa,ban);
	Sleep(ting);
	Beep(sfa,pai);
	Beep(si,pai);
	Sleep(ting);
	 
	Beep(si,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(la,ban);
	Beep(si,ban);
	Sleep(ting);
	 
	Beep(do1,pai+ban);
	Beep(si,ban);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	Beep(mi1,pai);
	Sleep(ting);
	 
	Beep(si,2*pai);
	Sleep(ting);
	Sleep(pai);
	Beep(mi,ban);
	Sleep(20);
	Beep(mi,ban);
	Sleep(ting);
	 
	Beep(la,pai+ban);
	Beep(so,ban);
	Sleep(ting);
	Beep(la,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(so,3*pai);
	Sleep(ting+ban);
	Beep(mi,ban);
	Sleep(ting/2);
	 
	Beep(fa,pai);
	Sleep(ting);
	Beep(do1,ban);
	Beep(si,ban);
	Sleep(20);
	Beep(si,pai);
	Sleep(ting);
	Beep(do1,pai);
	Sleep(ting);
	 
	Beep(re1,ban);
	Sleep(20);
	Beep(re1,ban);
	Sleep(20);
	Beep(mi1,ban);
	Sleep(ting/2);
	Beep(do1,pai);
	Sleep(ting+pai);
	 
	Beep(la,4*pai);
	 
	Sleep(1000);
	return ;
}
void winterflower()
{
	int p=400;//一拍 
	Beep(mi,400);
	Beep(sre,400);
	Beep(mi,400);
	Beep(do1,400);
	Beep(re1,400);
	Beep(si,400);
	Beep(do1,400);
	Beep(so,600);
	Sleep(800);
	Beep(mi,400);
	Beep(so,400);
	Beep(la,400);
	Sleep(800);
	Beep(so,400);
	Beep(fa,400);
	Beep(mi,400);
	Sleep(800);
	Beep(re,400);
	Beep(mi,400);
	Beep(fa,p);
	Beep(mi,p);
	Beep(re,p);
	Beep(fa,p);
	Beep(mi,p);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(si,p);
	Beep(sfa,p);
	Beep(sso,p);
	Beep(la,200);
	Beep(si,400);
	Sleep(800);
	Beep(mi,p);
	Beep(mi,p);
	Beep(do1,p);
	Beep(re1,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(so,p);
	Sleep(800);
	Beep(mi,p);
	Beep(so,p);
	Beep(la,p);
	Sleep(800);
	Beep(so,p);
	Beep(fa,p);
	Beep(mi,p);
	Sleep(800);
	Beep(re,p);
	Beep(mi,p);
	Beep(fa,p);
	Beep(so,p);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(re1,p);
	Beep(mi1,p);
	Beep(fa1,p);
	Beep(mi1,p);
	Beep(re1,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(la,p*4);
	Sleep(4000);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(re1,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(so,p);
	Sleep(800);
	Beep(mi,p);
	Beep(so,p);
	Beep(la,p*2);
	Beep(so,p);
	Beep(fa,p);
	Beep(mi,p);
	Sleep(800);
	Beep(re,p);
	Beep(mi,p);
	Beep(fa,p);
	Beep(mi,p);
	Beep(re,p);
	Beep(fa,p);
	Beep(mi,p);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(si,p);
	Beep(sfa,p);
	Beep(sso,p);
	Beep(la,200);
	Beep(si,p);
	Sleep(800);
	Beep(mi,p);
	Beep(mi,p);
	Beep(do1,p);
	Beep(re1,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(so,p);
	Sleep(800);
	Beep(mi,p);
	Beep(so,p);
	Beep(la,p*2);
	Beep(so,p);
	Beep(fa,p);
	Beep(mi,p);
	Sleep(800);
	Beep(re,p);
	Beep(mi,p);
	Beep(fa,p);
	Beep(so,p);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(re1,p);
	Beep(mi1,p);
	Beep(fa1,p);
	Beep(mi1,p);
	Beep(re1,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(la,p*4);
	Sleep(2400);
	Beep(la,600);
	Beep(re1,800);
	Beep(re1,p);
	Beep(mi1,p);
	Beep(fa1,p);
	Beep(la1,200);
	Beep(so1,600);
	Beep(re1,2*p);
	Beep(mi1,p*2);
	Beep(fa1,p*2);
	Beep(mi1,p*2);
	Beep(mi1,p);
	Beep(fa1,p);
	Beep(so1,p);
	Beep(fa1,p);
	Beep(mi1,p);
	Beep(re1,p);
	Beep(sdo1,600);
	Sleep(800);
	Beep(la,p);
	Beep(so,p);
	Beep(fa,p*2);
	Sleep(800);
	Beep(la,p);
	Beep(la,p);
	Sleep(800);
	Beep(re1,p);
	Beep(si,p);
	Sleep(400);
	Beep(si,p);
	Beep(si,p);
	Beep(si,p);
	Beep(la,p);
	Beep(sfa,p);
	Beep(la,p);
	Beep(sso,p*2);
	Beep(la,p*2);
	Beep(si,p*2);
	Beep(mi1,p*2);
	Beep(mi1,p*2); 
	Sleep(800);
	Beep(do1,p);
	Beep(re1,p);
	Beep(mi1,p);
	Sleep(400);
	Beep(la1,p*2);
	Beep(so1,p*2);
	Beep(mi1,p);
	Beep(so1,p);
	Beep(fa1,p*2);
	Beep(mi1,p);
	Beep(re1,p);
	Beep(mi1,p);
	Beep(do1,p);
	Beep(so,p*1.5);
	Sleep(400);	
	Beep(fa,p);
	Beep(so,p);
	Beep(la,p);
	Beep(fa,p);
	Beep(mi,p);
	Beep(la,p);
	Beep(si,p);
	Beep(do1,p);
	Beep(sre1,p);
	Beep(mi1,p);
	Beep(sfa1,p);
	Beep(la1,p);
	Beep(sso1,p*2);
	Beep(do1,p);
	Beep(re1,p);
	Beep(mi1,p*2);
	Beep(la1,p*2);
	Beep(so1,p*2);
	Beep(la1,p);
	Beep(si1,p);
	Beep(do2,p);
	Beep(si1,p);
	Beep(la1,p);
	Beep(so1,p);
	Beep(mi1,p);
	Beep(so1,p);
	Beep(mi1,p);
	Sleep(400);
	Beep(mi1,200);
	Beep(re1,400);
	Sleep(400);
	Beep(la,p);
	Beep(si,p*2);
	Beep(do1,p);
	Beep(mi1,p*1.5);
	Sleep(400);
	Beep(la1,p);
	Beep(la1,p*2);
	Beep(la1,p);
	Beep(si1,p);
	Beep(do2,p*2.5);
	Sleep(400);
	Beep(si1,p*2.5);
	Sleep(400); 
	Beep(la1,p*3.5);
}
void chu()
{
	cout<<"请输入被除数和除数：";
	long long bch,tch=0;
	cin>>ach>>bch;
	long long lena=ach.size();
	for(int i=0;i<lena;i++)
	{
		tch=tch*10+ach[i]-'0';
		numch[i]=tch/bch;
		tch%=bch;
	}
	cout<<"res=";
	bool flag=false;
	for(int i=0;i<lena;i++)
	{
		if(numch[i]!=0)	flag=true;
		if(flag==true)	cout<<numch[i];
	}
	if(flag==false)
		cout<<0;
	cout<<endl;
	return;
}
void startonpage()
{
	FILE* fp = fopen("QJOL.bmp", "rb");//读入的文件
	if (!fp) {
		cout << "文件未打开！\n";
		exit(0);
	}
	long width, height;
	BITMAPFILEHEADER fileHead;//位图文件头
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);//从fp中读取BITMAPFILEHEADER信息到fileHead中,同时fp的指针移动
	BITMAPINFOHEADER infoHead;//位图信息头
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);//从fp中读取BITMAPINFOHEADER信息到infoHead中,同时fp的指针移动
	width = infoHead.biWidth;
	height = infoHead.biHeight;
	char* bmpBuf = new char[width * height * 3];
	fseek(fp, long(sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), 0);//定位到起始位置
	fread(bmpBuf, sizeof(char), width * height * 3, fp);
	fclose(fp);
	//写入文件信息
	FILE* outFile = fopen("QJOLshow.bmp", "wb");//输出文件
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&infoHead, sizeof(BITMAPINFOHEADER), 1, outFile);
	char* tmp = bmpBuf;
	for (int j = 0;j < height;j++)
		for (int i = 0;i < width * 3;i++)
			fwrite(tmp++, 1, 1, outFile);
	fclose(outFile);
	//显示图像
	HWND hwnd = GetForegroundWindow();//窗口句柄
	HDC hdc = GetDC(hwnd);//绘图句柄
	BYTE b, g, r, rgb;
	tmp = bmpBuf;
	for (int j = 0;j < height;j++) {
		for (int i = 0;i < width;i++) {
			b = *tmp++;
			g = *tmp++;
			r = *tmp++;
			SetPixel(hdc, i, 150 + height - j, RGB(r, g, b));
		}
	}
	Sleep(4514);
	return ;
}
void cheng()
{
	cout<<"请输入两个因数：";
	int posc=0;
	int jwc=0;
	cin>>str1c>>str2c;
	int len1=strlen(str1c);
	int len2=strlen(str2c);
	for(int i=len1-1,j=0;i>=0;i--,j++)
		num1c[i]=str1c[j]-'0';
	for(int i=len2-1,j=0;i>=0;i--,j++)
		num2c[i]=str2c[j]-'0';
	for(int i=0;i<=len1;i++)//i控制因数1，j控制因数2 
	{
		for(int j=0;j<=len2;j++)
		{
			resc[i+j]+=num1c[i]*num2c[j];
			if(resc[i+j]>=10)
			{//当result大于10的时候，需要进位，进的位数是result[i]的十位，再减去进位的数 
				if(resc[i+j]>=10)
				{
					resc[i+j+1]+=resc[i+j]/10;
					resc[i+j]=resc[i+j]%10;
				}
			 } 
		}
	}
	for(int i=200;i>=0;i--)
    {
        if(resc[i]!=0)
        {
            posc=i;
            break;
        }
    }
    cout<<"res=";
    for(int i=posc;i>=0;i--)
        cout<<resc[i];
    cout<<endl;
}
void jia()
{
	cout<<"请输入两个加数：";
	cin>>ap>>bp;
	int lena=ap.size();
	int lenb=bp.size();
	for(int i=lena-1,j=0;i>=0;i--,j++)
		a1p[j]=ap[i]-'0';
	for(int i=lenb-1,j=0;i>=0;i--,j++)
		b1p[j]=bp[i]-'0';
	int temp=max(lena,lenb);
	for(int i=0;i<=temp-1;i++)
	{
		cp[i]+=a1p[i]+b1p[i];
		if(cp[i]>9)
		{
			cp[i+1]++;
			cp[i]=cp[i]%10;
		}
	}
	cout<<"res="; 
	if(cp[temp]>0)	cout<<cp[temp];
	for(int i=temp-1;i>=0;i--)
		cout<<cp[i];
	cout<<endl;
	return ;
}
void jian()
{
	int pos=0;
	cout<<"请输入被减数和减数：";
    cin>>str1m>>str2m;
    int str1len=strlen(str1m);
    int str2len=strlen(str2m);
    for(int i=str1len-1,j=0;i>=0;i--,j++)
        num1m[i]=str1m[j]-'0';
    for(int i=str2len-1,j=0;i>=0;i--,j++)
        num2m[i]=str2m[j]-'0';
    int flag=1;
    if(str1len>str2len)
        flag=1;
    else if(str1len==str2len)
        flag=strcmp(str1m,str2m);
    else    
        flag=-1;
    for(int i=0;i<=10087;i++)
    {
        if(flag>0)
        {
            resm[i]+=num1m[i]-num2m[i];
            if(resm[i]<0)
            {
                resm[i+1]--;
                resm[i]+=10;
         	}
        }
        else
        {
            resm[i]+=num2m[i]-num1m[i];
            if(resm[i]<0)
            {
                resm[i+1]--;
                resm[i]+=10;
            }
        }
    }
    for(int i=10087;i>=0;i--)
    {
        if(resm[i]!=0)
        {
            pos=i;
            break;
        }
    }
    cout<<"res=";
    if(flag==-1)
        cout<<'-';
    for(int i=pos;i>=0;i--)
        cout<<resm[i];
    cout<<endl;
    return ;
 } 
void cacu()
{
	while(fuhao!=5)
	{
		cout<<"请输入符号："<<endl;
		cout<<"1.加"<<endl;
		cout<<"2.减"<<endl;
		cout<<"3.乘"<<endl;
		cout<<"4.除"<<endl;
		cout<<"5.退出"<<endl; 
		cin>>fuhao;
		switch(fuhao)
		{
			case 1:
				jia();
				Sleep(1145);
				system("cls");
				break;
			case 2:
				jian();
				Sleep(1145);
				system("cls");
				break;
			case 3:
				cheng();
				Sleep(1145);
				system("cls");
				break;
			case 4:
				chu();
				break;
			case 5:
				Sleep(1145);
				system("cls");
				return;
		}
	}
}
void help()
{
	cout<<"请在使用前仔细阅读该帮助文档，帮助文档已经生成在QJOL-DOS的安装目录下。"<<endl;
	freopen("help.txt","w",stdout);
	cout<<"请认准QJOL团队成员：150895672群中有职位的都是开发者！"<<endl;
	cout<<"QJOL-DOS的所有代码均在github开源，请放心使用。"<<endl;
	cout<<"开源地址："<<endl;
	cout<<"https://github.com/SurnameQ114514/QJOL-DOS"<<endl;
	cout<<"指令解释："<<endl;
	cout<<"1.exit:退出程序"<<endl;
	cout<<"2.cacu:高精度计算器，遥遥领先"<<endl;
	cout<<"3.music:非常好的音乐使我去了下北泽"<<endl;
	cout<<"特别鸣谢：Summer制作的扫雷游戏;";
	return;
}
void starton()
{
	startonpage();
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"欢迎使用QJOL-DOS 3.2.1","QJOL-DOS",MB_OK);
	MessageBox(NULL,"请在您安装QJOL-DOS的目录查看使用时间。","QJOL-DOS",MB_OK);
	MessageBox(NULL,"为获得最佳体验，请您将窗口大小调整至120x30并用管理员模式运行。","QJOL-DOS",MB_OK);
	cout<<"正在启动QJOL-DOS 3.2.1"<<endl;
	cout<<"\n|";
	for(int i=1;i<=59;i++)
	{
		cout<<"■";
		Sleep(10);
	}
	cout<<"|";
	system("chkdsk C:");//我就不信Windows电脑没有C 盘 
	MessageBox(NULL,"检查完毕。（没错查了一遍你的C盘）","QJOL-DOS",MB_OK);
	system("cls");
	cout<<"请登录。"<<endl;
	cout<<"账户列表"<<endl;
	cout<<"1.管理员"<<endl;
	cout<<"2.访客"<<endl;
	cout<<"请选择:";
	cin>>loginchoice; 
	getline(cin,passcode);
	if(loginchoice==1)
	{
		cout<<"请输入密码或输入产品密钥。"<<endl;
		cout<<"密钥格式：XXXXX-XXXXX-XXXXX-XXXXX-XXXXX,且全部大写。"<<endl;
		getline(cin,passcode);
		if(passcode=="HOMO1-14514-19198-10XPF-D3FL1" || passcode=="ADW4F-14264-DAHT3-4FGA8-BD5KD" || passcode=="1145141919810" || passcode=="woshihutaodegou" || passcode=="homo114514")
		{
			password=1;
			Administrator=1; 
			notlogin=0;
			return; 
		}
		else
		{
			password=0;
			Administrator=0;
			notlogin=1;
			return;
		}
	}
	else
	{
		Administrator=0;
		cout<<"登录账号会被限制，你还要继续吗？(Y/N)(大写)";
		cin>>homo;
		if(homo=='Y')
		{
			password=1;
			notlogin=0;
			return;
		}
		else
		{
			cout<<"正在退出..."<<endl;
			end1=clock();
			double endtime=double(end1-start)/CLOCKS_PER_SEC;
			freopen("QJOL-DOS使用时间.txt","w",stdout);
			cout<<"Usetime: "<<endtime<<"s"<<endl;
			notlogin=1;
			Sleep(1145); 
			return ; 
		}
		return;
	}
	return;
}
bool check()
{
	ifstream srcFile("eula.txt",ios::in);//打开文件 
	srcFile>>checkeula;//赋值checkeula 
	srcFile.close();//关闭文件输入输出 
	if(checkeula!=1)
		return 0;
	else
		return 1;
}
int eulacheck()
{
	cout<<"请问您之前使用过QJOL-DOS吗？有请输入1，没有请输入2."<<endl;
	cin>>qjoldosusingstudus;
	if(qjoldosusingstudus==1)
	{
		cout<<"我们不再重新输出help文档，若输入错误，可以重新运行QJOL-DOS主程序.";
		Sleep(1145);
		system("cls");
		eulacheckreturnstadus=1;
		return 1;
	}
	else
	{
		cout<<"请问您有eula.txt和help.txt了吗？1是，0否"<<endl;
		cin>>agreeeula;
		if(agreeeula)
		{
			if(check())
			{
				cout<<"验证成功，正在进入系统。"<<endl;
				eulacheckreturnstadus=1;
				Sleep(1145);
				system("cls");
				return 1;
			}
			else
			{
				cout<<"我们检测到您没有同意eula。请在QJOL-DOS根目录找到help.txt。仔细阅读完毕后，请打开eula.txt,将值改为1并重新运行本程序。"<<endl;
				eulacheckreturnstadus=0;
				system("pause");
				return 0;
			}
				
		}
		else
		{
			help();
			cout<<"阅读完文档后请在根目录打开eula.txt,修改0为1。"<<endl; 
			freopen("eula.txt","w",stdout);
			cout<<0;
			eulacheckreturnstadus=0;
			Sleep(1145);
			return 0;
		}
	}
}
void music()
{
	int n;
	while(n!=3)
	{
		cout<<"按数字选曲："<<endl;
		cout<<"1.天空之城"<<endl;
		cout<<"2.冬之花（喜"<<endl;
		cout<<"3.退出"<<endl;
		cin>>n;
		if(n==1)
			skymusic();
		else if(n==2)
			winterflower();
	}

	return ;
}
int main()
{
	starton();
	if(password==0)
	{
		cout<<"密码错误，正在退出。"<<endl;
		Sleep(1000);
		end1=clock();
		double endtime=double(end1-start)/CLOCKS_PER_SEC;
		freopen("QJOL-DOS使用时间.txt","w",stdout);
		cout<<"Usetime: "<<endtime<<"s"<<endl;
		return 0;
	}
	if(notlogin==1)
		return 0;
	eulacheck();
	if(eulacheckreturnstadus==0)	return 0;
	system("cls"); 
	cout<<"加载命令行程序..."<<endl;
	Sleep(1145);
	cout<<"加载软件..."<<endl;
	Sleep(1145);
	cout<<"完成。" ;
	Sleep(1145);
	system("cls");
	cout<<"欢迎使用QJOL-DOS 。help文档在主程序根目录。"<<endl;
	cout<<"Copyright QJOJ 2021-2023,All right reserved."<<endl;
	while(cmd!="exit")
	{
		cout<<"MainDisk:";
		cin>>cmd;
		if(cmd=="cacu")
			cacu();
		else if(cmd=="music")
			music();
		else if(cmd=="game")
		{
			cout<<"请输入游戏编号:"<<endl;
			cout<<"1.扫雷"<<endl;
			cout<<"2.PvP大佬的奇妙冒险"<<endl;
			cin>>gamecnt;
			if(gamecnt==1)
				mine();
			else if(gamecnt==2)
				pvp();
		}
		else
			cout<<"淦，一看就是没看help，老老实实看好help再回来！"<<endl;
			return 0;
	}
	return 0;
}
