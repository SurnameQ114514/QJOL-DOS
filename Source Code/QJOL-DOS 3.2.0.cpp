//��� 
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
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
#define mi1 1318 //����һ�����143  1318+142=1460
#define fa1 1400// ���162 
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
//qǰ׺Ϊ������1��׺Ϊ������sǰ׺Ϊ������
using namespace std;
string ap,bp;
int a1p[505],b1p[505],cp[514];
int loginchoice; //��½ѡ�� 
bool agreeeula;//�Ƿ���eula.txt��help.txt 
int checkeula; //����Ƿ�ͬ��eula 
char useragreement[114514]="This is useragreement";//�û�Э�� 
char disclaimer[114514]="This is disclaimer";//�������� 
char eula[2]="0"; //Ĭ��eulaֵ 
string cmd;	 //�ڲ������� 
string passcode;//���롢��Կ  
bool Administrator;//����Ա״̬ 
bool password;//����״̬ 
char homo;//�ÿ͵�¼״̬ 
bool notlogin;//��¼״̬  
int fuhao;//���������� 
char str1m[11451];
char str2m[11451]={};
int num1m[11451]={};
int num2m[11451]={};
int resm[11451]={};//��������
char str1c[11451];
char str2c[11451];
int num1c[114514]={};
int num2c[114514]={};
int resc[114514]={};//�˷�����
int numch[114514]; 
string ach;//�������� 
clock_t start,end1;//��ʱ�� 
void startonpage()
{
	FILE* fp = fopen("QJOL.bmp", "rb");//������ļ�
	if (!fp) {
		cout << "�ļ�δ�򿪣�\n";
		exit(0);
	}
	long width, height;
	BITMAPFILEHEADER fileHead;//λͼ�ļ�ͷ
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);//��fp�ж�ȡBITMAPFILEHEADER��Ϣ��fileHead��,ͬʱfp��ָ���ƶ�
	BITMAPINFOHEADER infoHead;//λͼ��Ϣͷ
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);//��fp�ж�ȡBITMAPINFOHEADER��Ϣ��infoHead��,ͬʱfp��ָ���ƶ�
	width = infoHead.biWidth;
	height = infoHead.biHeight;
	char* bmpBuf = new char[width * height * 3];
	fseek(fp, long(sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), 0);//��λ����ʼλ��
	fread(bmpBuf, sizeof(char), width * height * 3, fp);
	fclose(fp);
	//д���ļ���Ϣ
	FILE* outFile = fopen("QJOLshow.bmp", "wb");//����ļ�
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&infoHead, sizeof(BITMAPINFOHEADER), 1, outFile);
	char* tmp = bmpBuf;
	for (int j = 0;j < height;j++)
		for (int i = 0;i < width * 3;i++)
			fwrite(tmp++, 1, 1, outFile);
	fclose(outFile);
	//��ʾͼ��
	HWND hwnd = GetForegroundWindow();//���ھ��
	HDC hdc = GetDC(hwnd);//��ͼ���
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
	int p=400;//һ�� 
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
void cheng()
{
	cout<<"����������������";
	int posc=0;
	int jwc=0;
	cin>>str1c>>str2c;
	int len1=strlen(str1c);
	int len2=strlen(str2c);
	for(int i=len1-1,j=0;i>=0;i--,j++)
		num1c[i]=str1c[j]-'0';
	for(int i=len2-1,j=0;i>=0;i--,j++)
		num2c[i]=str2c[j]-'0';
	for(int i=0;i<=len1;i++)//i��������1��j��������2 
	{
		for(int j=0;j<=len2;j++)
		{
			resc[i+j]+=num1c[i]*num2c[j];
			if(resc[i+j]>=10)
			{//��result����10��ʱ����Ҫ��λ������λ����result[i]��ʮλ���ټ�ȥ��λ���� 
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
void chu()
{
	cout<<"�����뱻�����ͳ�����";
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
			case 3:
				cheng();
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
void music()
{
	int n;
	while(n!=3)
	{
		cout<<"������ѡ����"<<endl;
		cout<<"1.���֮��"<<endl;
		cout<<"2.��֮��"<<endl;
		cout<<"3.�˳�"<<endl;
		cin>>n;
		if(n==1)
			skymusic();
		else if(n==2)
			winterflower();
	}

	return ;
}
void help()
{
	char help[114514]="QJOL-DOS�����д������github��Դ�������ʹ�á�\n��Դ��ַ��\nhttps://github.com/SurnameQ114514/QJOL-DOS\nָ����ͣ�\n1.exit:�˳�����\n2.cacu:�߾��ȼ�������ңң����\n3.vape:���mc���˶�֪�����Ǹ��ö���\n4.music:���֣����и��������ĸ���������github����issue��";
	cout<<"����ʹ��ǰ��ϸ�Ķ��ð����ĵ��������ĵ��Ѿ�������QJOL-DOS�İ�װĿ¼�¡�"<<endl;
	FILE *fp1;
	fp1=fopen("help.txt","w");
	fprintf(fp1,"%s",help);
	fclose(fp1);
	return;
}
void starton()
{
	start=clock();
	system("mode con cols=120 lines=30");
	MessageBox(NULL,"��ӭʹ��QJOL-DOS 3.2.0","QJOL-DOS",MB_OK);
	MessageBox(NULL,"��������װQJOL-DOS��Ŀ¼�鿴ʹ��ʱ�䡣","QJOL-DOS",MB_OK);
	MessageBox(NULL,"Ϊ���������飬���������ڴ�С������120x30��","QJOL-DOS",MB_OK);
	cout<<"��������QJOL-DOS 3.2.0"<<endl;
	cout<<"\n|";
	for(int i=1;i<=59;i++)
	{
		cout<<"��";
		Sleep(10);
	}
	cout<<"|";
	Sleep(1145);
	system("cls");
	cout<<"���¼��"<<endl;
	cout<<"�˻��б�"<<endl;
	cout<<"1.����Ա"<<endl;
	cout<<"2.�ÿ�"<<endl;
	cout<<"��ѡ��:";
	loginchoice=getch(); 
//	getline(cin,passcode);
	if(loginchoice=='1')
	{
		cout<<"������������Ʒ��Կ��"<<endl;
		cout<<"��Կ��ʽ��XXXXX-XXXXX-XXXXX-XXXXX-XXXXX,��ȫ����д��"<<endl;
		getline(cin,passcode);
		if(passcode=="HOMO1-14514-19198-10XPF-D3FL1" || passcode=="ADW4F-14264-DAHT3-4FGA8-BD5KD" || passcode=="1145141919810" || passcode=="woshihutaodegou" || passcode=="homo114514")
		{
			Administrator=1; 
			notlogin=0;
			return; 
		}
		else
		{
			Administrator=0;
			notlogin=1;
			return;
		}
	}
	if(loginchoice='2')
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
	srcFile>>checkeula;//��ȡcheckeula 
	srcFile.close();//�ر��ļ�������� 
	if(checkeula!=1)
		return 0;
	if(checkeula==1)
		return 1;
}
void vape()
{
	cout<<"|";
	for(int i=1;i<=59;i++)
	{
		cout<<"��";
		Sleep(50);
	}
	cout<<"|";
	FILE* fp = fopen("vape.bmp", "rb");//������ļ�
	if (!fp) {
		cout << "�ļ�δ�򿪣�\n";
		exit(0);
	}
	long width, height;
	BITMAPFILEHEADER fileHead;//λͼ�ļ�ͷ
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);//��fp�ж�ȡBITMAPFILEHEADER��Ϣ��fileHead��,ͬʱfp��ָ���ƶ�
	BITMAPINFOHEADER infoHead;//λͼ��Ϣͷ
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);//��fp�ж�ȡBITMAPINFOHEADER��Ϣ��infoHead��,ͬʱfp��ָ���ƶ�
	width = infoHead.biWidth;
	height = infoHead.biHeight;
	char* bmpBuf = new char[width * height * 3];
	fseek(fp, long(sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), 0);//��λ����ʼλ��
	fread(bmpBuf, sizeof(char), width * height * 3, fp);
	fclose(fp);
	//д���ļ���Ϣ
	FILE* outFile = fopen("vapeshow.bmp", "wb");//����ļ�
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&infoHead, sizeof(BITMAPINFOHEADER), 1, outFile);
	char* tmp = bmpBuf;
	for (int j = 0;j < height;j++)
		for (int i = 0;i < width * 3;i++)
			fwrite(tmp++, 1, 1, outFile);
	fclose(outFile);
	//��ʾͼ��
	HWND hwnd = GetForegroundWindow();//���ھ��
	HDC hdc = GetDC(hwnd);//��ͼ���
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
	system("cls");
	return;
}
int main()
{
	startonpage();
	starton();
	//����û�Э��
	if(check()==0)
	{
		cout<<"��û��ͬ�����ǵ��û�Э�������������������ϸ�Ķ�UserAgreement.txt��Disclaimer.txt��eula.txtֵ�޸�Ϊ1���ɽ���ϵͳ��";
		FILE *fp;
		fp=fopen("UserAgreement.txt","w");
		fprintf(fp,"%s",useragreement);
		fclose(fp);
		fp=fopen("Disclaimer.txt","w");
		fprintf(fp,"%s",disclaimer);
		fclose(fp);
		fp=fopen("eula.txt","w");
		fprintf(fp,"%s",eula);
		fclose(fp);
		return 0;
	 } 
	if(check())
	{
		if(notlogin==1)
		{
			cout<<"������������˳���"<<endl;
			Sleep(1000);
			end1=clock();
			double endtime=double(end1-start)/CLOCKS_PER_SEC;
			freopen("QJOL-DOSʹ��ʱ��.txt","w",stdout);
			cout<<"Usetime: "<<endtime<<"s"<<endl;
			return 0;
		}
		system("cls"); 
		cout<<"���������г���..."<<endl;
		Sleep(1145);
		cout<<"�������..."<<endl;
		Sleep(1145);
		cout<<"��ɡ�" ;
		Sleep(1145);
		system("cls");
		cout<<"��ӭʹ��QJOL-DOS 3.2.0������ʹ�������help��ð�����"<<endl;
		cout<<"Copyright QJOL Studios 2021-2025,All right reserved."<<endl; 
		while(cmd!="exit")
		{
			cout<<"MainDisk:";
			cin>>cmd;
			if(cmd=="cacu")
				cacu();
			else if(cmd=="help")
				help();
			else if(cmd=="vape")
				vape();
			else if(cmd=="music")
				music();
			else if(cmd!="exit")
				cout<<"Bad command or file name"<<endl;
		}
	}
	return 0;
}
