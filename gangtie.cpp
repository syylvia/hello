#include<iostream>
using namespace std;
int max(int i,int j)
{
	if(i>=j)
		return i;
	else
		return j;
}
int main()
{
	int p[11]={0,1,5,8,9,10,17,17,20,24,30};
	int r[11]={0};
	int i,j,n;
	cin>>n;
	/*自低向上的动态规划,先算出n=1时的最优解放入r[1],再算出n=2的最优解放入
	  r[2],以此类推,直至算出长度为n时的最优解*/
	for(i=1;i<=n;i++)
	{
		r[i]=p[i];//不切割时的值
		for(j=1;j<=i;j++)//将i分成两部分，使用这两部分的最优解相加，这两部分可能会在之前的最优解计算中被分成了n部分
		{
			r[i]=max(r[i],r[i-j]+r[j]);//将r[i]与切割后的最优解比较，取较大一个值
		}
	}
	cout<<r[n]<<endl;
	return 0;
}
