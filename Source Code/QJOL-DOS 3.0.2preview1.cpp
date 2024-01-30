//大纲 
#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;
int loginchoice=-1; //登陆选择 
bool agreeeula=-1;
bool eulastadus=-1;
int checkeula=-114514; //检查是否同意eula 
int qjoldosusingstudus=-1; //检查是否使用过QJOL-DOS 
string cmd="1";	 //内部命令行 
string passcode;//密码、密钥  
bool Administrator=-1;//管理员状态 
bool password=-1;//密码状态 
char homo=-1;//访客登录状态 
bool notlogin=0;//登录状态  
clock_t start,end1;
void help()
{
	cout<<"请在使用前仔细阅读该帮助文档，帮助文档已经生成在QJOL-DOS的安装目录下。"<<endl;
	freopen("help.txt","w",stdout);
	cout<<"QJOL-DOS的所有代码均在github开源，请放心使用。"<<endl;
	cout<<"开源地址："<<endl;
	cout<<"https://github.com/SurnameQ114514/QJOL-DOS"<<endl;
	cout<<"指令解释："<<endl;
	cout<<"1.exit:退出程序"<<endl;
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
	freopen("eula.txt","r",stdin);
	cin>>checkeula;
	if(checkeula!=1)
		return 0;
	else
		return 1;
}
bool eulacheck()
{
	cout<<"请问您之前使用过QJOL-DOS吗？有请输入1，没有请输入2."<<endl;
	cin>>qjoldosusingstudus;
	if(qjoldosusingstudus==1)
	{
		cout<<"我们不再重新输出help文档，若输入错误，可以重新运行QJOL-DOS主程序.";
		system("cls");
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
				return 1;
			}
			else
			{
				cout<<"我们检测到您没有同意eula。请在QJOL-DOS根目录找到help.txt。仔细阅读完毕后，请打开eula.txt,将值改为1并重新运行本程序。"<<endl;
				return 0;
			}
				
		}
		else
		{
			help();
			cout<<"阅读完文档后请在根目录打开eula.txt,修改0为1。"<<endl; 
			freopen("eula.txt","w",stdout);
			cout<<0;
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
	if(eulacheck()!=1)
		return 0;
	system("cls"); 
	cout<<"加载命令行程序..."<<endl;
	Sleep(1145);
	cout<<"加载软件..."<<endl;
	Sleep(1145);
	cout<<"完成。" ;
	Sleep(1145);
	system("cls");
	cout<<"欢迎使用QJOL-DOS 3.0.2。help文档在主程序根目录。"<<endl;
	cout<<"Copyright QJOJ 2021-2023,All right reserved."<<endl;
	//错误始 循环问题 
	while(true)
	{
		cout<<"MainDisk:";
		cin>>cmd; //具体 输入问题 
		if(cmd=="exit")
			break;
	}
	//错误终 
	return 0;
}
