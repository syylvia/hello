#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,i,j,k,max,maxi,t,m,s,p;
	int a[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	//先排序
	for(i=0;i<n-1;i++)
	{
		max=a[i];maxi=i;
		for(j=i+1;j<n;j++)
		{
			if(max<a[j])
			{
				max=a[j];
				maxi=j;
			}
		}
		t=a[i];
		a[i]=max;
		a[maxi]=t;
	}
	//将最小的两个相加并插入数组中并舍弃最后两个数据，将数据依次后移
	m=n-1;s=0;
	for(i=0;i<n-1;i++)
	{
		p=a[m]+a[m-1];
		s=s+p;
		m=m-1;
		for(j=0;j<m;j++)
		{
			if(p>a[0])//当数字大于数组中的最大值时，直接将数据后移，
			{
				for(k=m;k>0;k--)
				{
					a[k]=a[k-1];
				}
				a[0]=p;
				break;
			}
			else if(a[j]>=p && a[j+1]<=p)//寻找适当位置插入数据
			{
			    for(k=m;k>j+1;k--)//依次后移
				{
					a[k]=a[k-1];
				}
				a[j+1]=p;//将值插入
				break;
			}
		}
	}
cout<<s<<endl;
return 0;
}
