//��� 
#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;
int loginchoice=-1; //��½ѡ�� 
bool agreeeula=-1;
bool eulastadus=-1;
int checkeula=-114514; //����Ƿ�ͬ��eula 
int qjoldosusingstudus=-1; //����Ƿ�ʹ�ù�QJOL-DOS 
string cmd="1";	 //�ڲ������� 
string passcode;//���롢��Կ  
bool Administrator=-1;//����Ա״̬ 
bool password=-1;//����״̬ 
char homo=-1;//�ÿ͵�¼״̬ 
bool notlogin=0;//��¼״̬  
clock_t start,end1;
void help()
{
	cout<<"����ʹ��ǰ��ϸ�Ķ��ð����ĵ��������ĵ��Ѿ�������QJOL-DOS�İ�װĿ¼�¡�"<<endl;
	freopen("help.txt","w",stdout);
	cout<<"QJOL-DOS�����д������github��Դ�������ʹ�á�"<<endl;
	cout<<"��Դ��ַ��"<<endl;
	cout<<"https://github.com/SurnameQ114514/QJOL-DOS"<<endl;
	cout<<"ָ����ͣ�"<<endl;
	cout<<"1.exit:�˳�����"<<endl;
	return;
}
void starton()
{
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"��ӭʹ��QJOL-DOS 3.0.2","QJOL-DOS",MB_OK);
	MessageBox(NULL,"��������װQJOL-DOS��Ŀ¼�鿴ʹ��ʱ�䡣","QJOL-DOS",MB_OK);
	MessageBox(NULL,"Ϊ���������飬���������ڴ�С������120x30���ù���Աģʽ���С�","QJOL-DOS",MB_OK);
	cout<<"��������QJOL-DOS 3.0.2"<<endl;
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
	cin>>loginchoice; 
	getline(cin,passcode);
	if(loginchoice==1)
	{
		cout<<"����������������Ʒ��Կ��"<<endl;
		cout<<"��Կ��ʽ��XXXXX-XXXXX-XXXXX-XXXXX-XXXXX,��ȫ����д��"<<endl;
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
	cout<<"������֮ǰʹ�ù�QJOL-DOS����������1��û��������2."<<endl;
	cin>>qjoldosusingstudus;
	if(qjoldosusingstudus==1)
	{
		cout<<"���ǲ����������help�ĵ�����������󣬿�����������QJOL-DOS������.";
		system("cls");
		return 1;
	}
	else
	{
		cout<<"��������eula.txt��help.txt����1�ǣ�0��"<<endl;
		cin>>agreeeula;
		if(agreeeula)
		{
			if(check())
			{
				cout<<"��֤�ɹ������ڽ���ϵͳ��"<<endl;
				return 1;
			}
			else
			{
				cout<<"���Ǽ�⵽��û��ͬ��eula������QJOL-DOS��Ŀ¼�ҵ�help.txt����ϸ�Ķ���Ϻ����eula.txt,��ֵ��Ϊ1���������б�����"<<endl;
				return 0;
			}
				
		}
		else
		{
			help();
			cout<<"�Ķ����ĵ������ڸ�Ŀ¼��eula.txt,�޸�0Ϊ1��"<<endl; 
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
		cout<<"������������˳���"<<endl;
		Sleep(1000);
		end1=clock();
		double endtime=double(end1-start)/CLOCKS_PER_SEC;
		freopen("QJOL-DOSʹ��ʱ��.txt","w",stdout);
		cout<<"Usetime: "<<endtime<<"s"<<endl;
		return 0;
	}
	if(notlogin==1)
		return 0;
	if(eulacheck()!=1)
		return 0;
	system("cls"); 
	cout<<"���������г���..."<<endl;
	Sleep(1145);
	cout<<"�������..."<<endl;
	Sleep(1145);
	cout<<"��ɡ�" ;
	Sleep(1145);
	system("cls");
	cout<<"��ӭʹ��QJOL-DOS 3.0.2��help�ĵ����������Ŀ¼��"<<endl;
	cout<<"Copyright QJOJ 2021-2023,All right reserved."<<endl;
	//����ʼ ѭ������ 
	while(true)
	{
		cout<<"MainDisk:";
		cin>>cmd; //���� �������� 
		if(cmd=="exit")
			break;
	}
	//������ 
	return 0;
}
