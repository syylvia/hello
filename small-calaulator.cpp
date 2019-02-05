#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int jz;
//将n进制转化成十进制
long long int zs(string n)
{
	long long int s=0,p=1;
	int i;
	for(i=n.length()-1;i>=0;i--)
	{
		if(n[i]>='A' && n[i]<='Z')
			s=s+(n[i]-'A'+10)*p;
		else
			s=s+(n[i]-'0')*p;
		p=p*jz;
	}
	return s;
}
//将十进制转化成n进制
string sz(long long int n)
{
	string r;
	int i;
	int j=0;
	if(n==0)
		r="0"; 
	while(n)
	{
		char c;
		i=n%jz;
		if(i<10)
			c=i+'0';
		else
			c=(i-10)+'A';
		r=c+r;
        n=n/jz;
	}
	return r;
}
int main()
{
	int n,j,zh;
	long long int i,m,p;
	string a;
	int b;
	cin>>n;
	b=0;jz=10;
	for(j=0;j<n;j++)
	{
    cin>>a;
	if (a=="CLEAR")
	{
    b=0;i=0;
	}
	else if(a=="NUM")
	{
		string k;
		cin>>k;
		if(b==0)//没有输入运算符，将k转换成十进制赋给i
		{
		i=zs(k);
		}
		else if( b!=0)//说明输入了运算符
		{
			p=zs(k);//p是运算符之后的数转换成十进制的结果，i是运算符之前的数字的十进制
			if(b==1)//判断是哪个运算符
				i=i+p;
			else if(b==2)
				i=i-p;
			else if(b==3)
				i=i*p;
			else if(b==4)
				i=i/p;
			else if(b==5)
				i=i%p;
		}
	}
	else if(a=="ADD")
	b=1;
	else if(a=="SUB")
	b=2;
	else if(a=="MUL")
	b=3;
	else if(a=="DIV")
	b=4;
	else if(a=="MOD")
    b=5;
    else if(a=="CHANGE")
	cin>>jz;	
	else if(a=="EQUAL")
	{
		if(jz!=10)
			cout<<sz(i)<<endl;
		else
			cout<<i<<endl;
	}
	}
	return 0;
}
