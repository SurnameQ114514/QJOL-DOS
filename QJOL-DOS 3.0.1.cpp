//��� 
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int t;
string cmd; //�ڲ������� 
string passcode;//���롢��Կ  
bool Administrator;//����Ա״̬ 
bool password;//����״̬ 
char homo;//�ÿ͵�¼״̬ 
bool notlogin=0;//��¼״̬  
clock_t start,end1;
void startonpage()
{
	
 } 
void starton()
{
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"��ӭʹ��QJOL-DOS 3.0.0","QJOL-DOS",MB_OK);
	MessageBox(NULL,"��������װQJOL-DOS��Ŀ¼�鿴ʹ��ʱ�䡣","QJOL-DOS",MB_OK);
	MessageBox(NULL,"Ϊ���������飬���������ڴ�С������120x30���ù���Աģʽ���С�","QJOL-DOS",MB_OK);
	cout<<"��������QJOL-DOS 3.0.0"<<endl;
	cout<<"\n|";
	for(int i=1;i<=59;i++)
	{
		cout<<"��";
		Sleep(10);
	}
	cout<<"|";
	system("chkdsk C:");//�ҾͲ���Windows����û��C �� 
	MessageBox(NULL,"�����ϡ���û�����һ�����C�̣�","QJOL-DOS",MB_OK);
	system("cls");
	cout<<"���¼��"<<endl;
	cout<<"�˻��б�"<<endl;
	cout<<"1.����Ա"<<endl;
	cout<<"2.�ÿ�"<<endl;
	cout<<"��ѡ��:";
	cin>>t; 
	getline(cin,passcode);
	if(t==1)
	{
		cout<<"����������������Ʒ��Կ��"<<endl;
		cout<<"��Կ��ʽ��XXXXX-XXXXX-XXXXX-XXXXX-XXXXX,��ȫ����д��"<<endl;
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
		cout<<"��¼�˺Żᱻ���ƣ��㻹Ҫ������(Y/N)(��д)";
		cin>>homo;
		if(homo=='Y')
		{
			password=1;
			notlogin=0;
			return;
		}
		else
		{
			cout<<"�����˳�..."<<endl;
			end1=clock();
			double endtime=double(end1-start)/CLOCKS_PER_SEC;
			freopen("QJOL-DOSʹ��ʱ��.txt","w",stdout);
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
		cout<<"������������˳���"<<endl;
		end1=clock();
		double endtime=double(end1-start)/CLOCKS_PER_SEC;
		freopen("QJOL-DOSʹ��ʱ��.txt","w",stdout);
		cout<<"Usetime: "<<endtime<<"s"<<endl;
		return 0;
	}
	if(notlogin==1)
		return 0;
	system("cls"); 
	cout<<"���������г���..."<<endl;
	Sleep(1145);
	cout<<"�������..."<<endl;
	Sleep(1145);
	cout<<"��ɡ�" ;
	Sleep(1145);
	system("cls");
	cout<<"��ӭʹ��QJOL-DOS 3.0.0 ,�����help����ȡ������"<<endl;
	cout<<"Copyright QJOJ 2021-2022,All right reserved"<<endl;
	while(cmd!="exit")
	{
		cout<<"MainDisk:";
		cin>>cmd;
	}
	return 0;
}
