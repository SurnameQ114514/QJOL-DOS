//��� 
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <ctime>
using namespace std;
string ap,bp;
int a1p[505],b1p[505],cp[514];
int loginchoice; //��½ѡ�� 
bool agreeeula;//�Ƿ���eula.txt��help.txt 
int checkeula; //����Ƿ�ͬ��eula 
int qjoldosusingstudus; //����Ƿ�ʹ�ù�QJOL-DOS 
string cmd;	 //�ڲ������� 
string passcode;//���롢��Կ  
bool Administrator;//����Ա״̬ 
bool password;//����״̬ 
char homo;//�ÿ͵�¼״̬ 
bool notlogin;//��¼״̬  
bool eulacheckreturnstadus;//eulacheck��������ֵ 
int fuhao;//���������� 
char str1m[11451];
char str2m[11451]={};
int num1m[11451]={};
int num2m[11451]={};
int resm[11451]={};//��������
clock_t start,end1;//��ʱ�� 
void jia()
{
	cout<<"����������������";
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
	cout<<"�����뱻�����ͼ�����";
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
		cout<<"��������ţ�"<<endl;
		cout<<"1.��"<<endl;
		cout<<"2.��"<<endl;
		cout<<"3.��"<<endl;
		cout<<"4.��"<<endl;
		cout<<"5.�˳�"<<endl; 
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
	cout<<"����ʹ��ǰ��ϸ�Ķ��ð����ĵ��������ĵ��Ѿ�������QJOL-DOS�İ�װĿ¼�¡�"<<endl;
	freopen("help.txt","w",stdout);
	cout<<"QJOL-DOS�����д������github��Դ�������ʹ�á�"<<endl;
	cout<<"��Դ��ַ��"<<endl;
	cout<<"https://github.com/SurnameQ114514/QJOL-DOS"<<endl;
	cout<<"��ϵͳ�ڵ�¼����������Ӧ���밴��1���س���"<<endl;
	cout<<"ָ����ͣ�"<<endl;
	cout<<"1.exit:�˳�����"<<endl;
	cout<<"2.cacu:�߾��ȼ�������ңң����"<<endl;
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
	ifstream srcFile("eula.txt",ios::in);//���ļ� 
	srcFile>>checkeula;//��ֵcheckeula 
	srcFile.close();//�ر��ļ�������� 
	if(checkeula!=1)
		return 0;
	else
		return 1;
}
int eulacheck()
{
	cout<<"������֮ǰʹ�ù�QJOL-DOS����������1��û��������2."<<endl;
	cin>>qjoldosusingstudus;
	if(qjoldosusingstudus==1)
	{
		cout<<"���ǲ����������help�ĵ�����������󣬿�����������QJOL-DOS������.";
		system("cls");
		eulacheckreturnstadus=1;
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
				eulacheckreturnstadus=1;
				Sleep(1145);
				system("cls");
				return 1;
			}
			else
			{
				cout<<"���Ǽ�⵽��û��ͬ��eula������QJOL-DOS��Ŀ¼�ҵ�help.txt����ϸ�Ķ���Ϻ����eula.txt,��ֵ��Ϊ1���������б�����"<<endl;
				eulacheckreturnstadus=0;
				return 0;
			}
				
		}
		else
		{
			help();
			cout<<"�Ķ����ĵ������ڸ�Ŀ¼��eula.txt,�޸�0Ϊ1��"<<endl; 
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
	eulacheck();
	if(eulacheckreturnstadus==0)	return 0;
//	system("cls"); 
//	cout<<"���������г���..."<<endl;
//	Sleep(1145);
//	cout<<"�������..."<<endl;
//	Sleep(1145);
//	cout<<"��ɡ�" ;
//	Sleep(1145);
//	system("cls");
	cout<<"��ӭʹ��QJOL-DOS 3.0.2��help�ĵ����������Ŀ¼��"<<endl;
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
