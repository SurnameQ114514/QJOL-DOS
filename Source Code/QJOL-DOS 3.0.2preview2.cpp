//大纲 
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <ctime>
using namespace std;
string ap,bp;
int a1p[505],b1p[505],cp[514];
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
clock_t start,end1;//计时器 
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
				break;
			case 2:
				jian();
				break;
//			case 3:
//				cheng();
//				break;
//			case 4:
//				chu();
//				break;
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
	cout<<"QJOL-DOS的所有代码均在github开源，请放心使用。"<<endl;
	cout<<"开源地址："<<endl;
	cout<<"https://github.com/SurnameQ114514/QJOL-DOS"<<endl;
	cout<<"若系统在登录过程中无响应，请按下1并回车。"<<endl;
	cout<<"指令解释："<<endl;
	cout<<"1.exit:退出程序"<<endl;
	cout<<"2.cacu:高精度计算器，遥遥领先"<<endl;
	return;
}
void starton()
{
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"欢迎使用QJOL-DOS 3.0.2","QJOL-DOS",MB_OK);
	MessageBox(NULL,"请在您安装QJOL-DOS的目录查看使用时间。","QJOL-DOS",MB_OK);
	MessageBox(NULL,"为获得最佳体验，请您将窗口大小调整至120x30并用管理员模式运行。","QJOL-DOS",MB_OK);
	cout<<"正在启动QJOL-DOS 3.0.2"<<endl;
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
			return 0;
		}
	}
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
//	system("cls"); 
//	cout<<"加载命令行程序..."<<endl;
//	Sleep(1145);
//	cout<<"加载软件..."<<endl;
//	Sleep(1145);
//	cout<<"完成。" ;
//	Sleep(1145);
//	system("cls");
	cout<<"欢迎使用QJOL-DOS 3.0.2。help文档在主程序根目录。"<<endl;
	cout<<"Copyright QJOJ 2021-2023,All right reserved."<<endl; 
	while(cmd!="exit")
	{
		cout<<"MainDisk:";
		cin>>cmd;
		if(cmd=="cacu")
			cacu();
	}
	return 0;
}
