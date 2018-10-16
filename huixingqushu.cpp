#include<stdio.h>
int main()
{
	int m,n,s,i,j;
	int a[20][20]={0};
	scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     scanf("%d",&a[i][j]);
     s=m*n;
     i=0;j=0;
     while(s)
     {
     	while(a[i][j]!=-1 && i<m)//向下走
		 {
 			printf("%d ",a[i][j]);
 			s--;
 			a[i][j]=-1;
 			i++;
 		} 
 		i--;
 		j++;
 		while(a[i][j]!=-1 && j<n)//向右走
		 {
 			printf("%d ",a[i][j]);
 			s--;
 			a[i][j]=-1;
 			j++;
 		} 
 		j--;
 		i--;
		 while(a[i][j]!=-1 && i>=0)//向上走
		 {
 			printf("%d ",a[i][j]);
 			s--;
 			a[i][j]=-1;
 			i--;
 		} 
		 i++; 
		 j--;
 		while(a[i][j]!=-1 && j>=0)//向左走
		 {
 			printf("%d ",a[i][j]);
 			s--;
 			a[i][j]=-1;
 			j--;
 		} 
 		j++;
 		i++;
     }
     return 0;
}
