#include<iostream>
using namespace std;
int min(int i,int j)
{
	return i<=j?i:j;
}
int main()
{
	int n,i,j;
	int t[50],s[50];
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>t[i];
	s[1]=t[1];
	s[2]=t[2];
	for(i=3;i<=n;i++)
	{
		/*第i个人有两种情况，一种是只剩下第i个人，前i-1个人全都已经过河，则这种情况下的最优时间为前i-1个人过河的最优时间加上第一个人过河把手电送过来的时间加上第i个人和第一个人一起过河的时间。另一种情况是剩下两个人，即当前i-2个人过河后第一个人将手电送过来，第i-1个人和第i个人过河，第二个人将手电送过来后和第一个人一起过河*/
	s[i]=min(s[i-1]+t[1]+t[i],s[i-2]+2*t[2]+t[i]+t[1]);
	}
	cout<<s[n]<<endl;
	return 0;
}
