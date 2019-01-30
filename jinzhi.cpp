#include<iostream>
#include<string>
using namespace std;
int arr[10000001];
int main()
{
	int n,i,j,flag,len;
	string a,b;
	cin>>n;
    while(n--)
	{
		cin>>a;
		len=a.length();
		b="";
        for(j=0;j<len;j++)
		{
			switch(a[j])
			{
				case '0':b=b+"0000";break;
				case '1':b=b+"0001";break;
				case '2':b=b+"0010";break;
				case '3':b=b+"0011";break;
				case '4':b=b+"0100";break;
				case '5':b=b+"0101";break;
				case '6':b=b+"0110";break;
				case '7':b=b+"0111";break;
				case '8':b=b+"1000";break;
				case '9':b=b+"1001";break;
				case 'A':b=b+"1010";break;
				case 'B':b=b+"1011";break;
				case 'C':b=b+"1100";break;
				case 'D':b=b+"1101";break;
				case 'E':b=b+"1110";break;
				case 'F':b=b+"1111";break;
		        default:break;	
		     }
    	}
		if (len*4%3==1)
			b="00"+b;
		if(len*4%3==2)
			b="0"+b;
	      flag=0;len=b.length();
		for(j=0;j<len-2;j=j+3)
			{
                arr[flag]=(b[j]-'0')*4+(b[j+1]-'0')*2+(b[j+2]-'0');
				flag++;
			}
		for(j=0;j<flag;j++)
		{
			if(j==0&&arr[j]==0) continue;
		cout<<arr[j];
    	}
	cout<<endl;
	}
	return 0;
}

