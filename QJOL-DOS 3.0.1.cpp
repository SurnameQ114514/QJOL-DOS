//大纲 
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int t;
string cmd; //内部命令行 
string passcode;//密码、密钥  
bool Administrator;//管理员状态 
bool password;//密码状态 
char homo;//访客登录状态 
bool notlogin=0;//登录状态  
clock_t start,end1;
void startonpage()
{
	
 } 
void starton()
{
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"欢迎使用QJOL-DOS 3.0.0","QJOL-DOS",MB_OK);
	MessageBox(NULL,"请在您安装QJOL-DOS的目录查看使用时间。","QJOL-DOS",MB_OK);
	MessageBox(NULL,"为获得最佳体验，请您将窗口大小调整至120x30并用管理员模式运行。","QJOL-DOS",MB_OK);
	cout<<"正在启动QJOL-DOS 3.0.0"<<endl;
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
	cin>>t; 
	getline(cin,passcode);
	if(t==1)
	{
		cout<<"请输入密码或输入产品密钥。"<<endl;
		cout<<"密钥格式：XXXXX-XXXXX-XXXXX-XXXXX-XXXXX,且全部大写。"<<endl;
		getline(cin,passcode);
		if(passcode=="HOMO1-14514-19198-10XPF-D3FL1" || passcode=="ADW4F-14264-DAHT3-4FGA8-BD5KD" || passcode=="1145141919810" || passcode=="woshihutaodegou")
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
int main()
{
	starton();
	if(password==0)
	{
		cout<<"密码错误，正在退出。"<<endl;
		end1=clock();
		double endtime=double(end1-start)/CLOCKS_PER_SEC;
		freopen("QJOL-DOS使用时间.txt","w",stdout);
		cout<<"Usetime: "<<endtime<<"s"<<endl;
		return 0;
	}
	if(notlogin==1)
		return 0;
	system("cls"); 
	cout<<"加载命令行程序..."<<endl;
	Sleep(1145);
	cout<<"加载软件..."<<endl;
	Sleep(1145);
	cout<<"完成。" ;
	Sleep(1145);
	system("cls");
	cout<<"欢迎使用QJOL-DOS 3.0.0 ,请键入help来获取帮助。"<<endl;
	cout<<"Copyright QJOJ 2021-2022,All right reserved"<<endl;
	while(cmd!="exit")
	{
		cout<<"MainDisk:";
		cin>>cmd;
	}
	return 0;
}
