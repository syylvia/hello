#include<iostream>
#include<cstdlib>
using namespace std; 
int main()
{
	int a[2]={365,366};
	int i,j,s=320,today=5;
	for(i=2001;i<2018;i++)
	{
		if(i%400==0||(i%4==0 && i%100!=0))
			j=1;
		else 
				j=0;
		s=s+a[j];
	}
	s=s%7;
	cout<<s;
	cout<<endl;
	s=abs(s-today);
	cout<<s;
	return 0;
}
