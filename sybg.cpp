/*定义学生（student）类，其中至少包括姓名、性别、学号、班级和联系电话。
功能要求：
       1、设计菜单实现功能选择；   
       2、输入功能:输入学生信息，并保存到文件中；
       3、能按照学生的学号排序
       4、能根据学号修改学生信息
       5、能根据学号删除学生信息
       6、查询功能：
            1）能够根据学号查询学生信息；
            2）能够根据姓名、学号、班级等查询学生信息
	        3）按照班级统计学生人数。*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
class Sqlist;
class Student
{
	public:
		 Student& operator=(Student &temp);
         friend ostream& operator<<(ostream& os,Student& stu);
         friend istream& operator>>(istream& is,Student& stu);
		 friend class Sqlist;
	private:
		string xm;
		string xb;
        string  xh;
		string  bj;
		string dh;
};
class Sqlist
{
	public:
		Sqlist();
		~Sqlist();
		void sr();
		int px();
		int xg();
		int sc();
		int cx();
		void xhcx();
		void xmcx();
		void tj();
		void dr();
		void bc();
		bool empty();
	private:
		Student *element;
		int length;
};
Student& Student::operator=(Student &temp)
{
this->xm=temp.xm;
this->xb=temp.xb;
this->xh=temp.xh;
this->bj=temp.bj;
this->dh=temp.dh;
return *this;
}
ostream& operator<<(ostream& os,Student& stu)
{
	os<<stu.xm<<" "<<stu.xb<<" "<<stu.xh<<" "<<stu.bj<<" "<<stu.dh;
	return os;
}
istream& operator>>(istream& is,Student& stu)
{
	is>>stu.xm>>stu.xb>>stu.xh>>stu.bj>>stu.dh;
	return is;
}
Sqlist::Sqlist()
{
	element=new Student[10];
	length=0;
}
Sqlist::~Sqlist()
{
	delete[]element;
}
bool Sqlist::empty()
{
	if(length==0)
		return true;
	else
		return false;
}
void Sqlist::sr()
{
	int j,n,i,m;
	cout<<"请输入要输入学生信息的学生个数";
	cin>>n;
	for(m=0;m<n;m++)
	{
		i=0;
	cout<<"请输入学生姓名,性别,学号,班级,联系电话"<<endl;
	cin>>element[length];
	while(i==0)
	{
		for(j=0;j<length;j++)
			if(element[length].xh==element[j].xh)
			{
				cout<<"该学号已存在，请重新输入学号";
				cin>>element[j].xh;
			}
		if(j==length)
			i=1;
	}
	length++;
	}
}
int Sqlist::px()
{
	if(empty())
	{
		cout<<"请先输入学生信息"<<endl;
	     return 0;
	}
   int i,j;
   Student temp;
   for(i=0;i<length-1;i++)
	   for(j=i+1;j<length;j++)
	   {
		   if( element[i].xh>element[j].xh)
		   {
			   temp=element[i];
			   element[i]=element[j];
			   element[j]=temp;
		   }
	   }
   cout<<"按照学号排序后："<<endl;
   for(i=0;i<length;i++)
	   cout<<element[i]<<endl;
   return 0;
}
int Sqlist::xg()
{
	if(empty())
	{
		cout<<"请先输入学生信息"<<endl;
		return 0;
	}
	string  x;int i=0,j;
	while(i==0)
	{
	cout<<"请输入所要修改的学生的学号："<<endl;
	cin>>x;
		for(j=0;j<length;j++)
			if(x==element[j].xh)
			{
				cout<<"请输入修改后的学生姓名,性别,班级,电话";
	            cin>>element[j].xm>>element[j].xb>>element[j].bj>>element[j].dh;	           
	            i=1;
				cout<<"修改成功！"<<endl;
	        }
	    }
	return 0;
}
int Sqlist::sc()
{
	if(empty())
	{
      cout<<"请输入学生信息"<<endl;
	  return 0;
	}
	string x;int i=0,j,k;
	while(i==0)
	{
	cout<<"请输入所要删除学生的学号";
	cin>>x;
	for(j=0;j<length;j++)
		if(element[j].xh==x)
		{
			for(k=j+1;j<length;j++)
			element[k-1]=element[k];
		    length--;
			i=1;
		    cout<<"删除成功"<<endl;
		}
	}
	return 0;
}
void Sqlist::xhcx()
{
	string  x;int i,j=0;
	while(j==0)
	{
	cout<<"请输入学号"<<endl;
	cin>>x;
	for(i=0;i<length;i++)
		if(element[i].xh==x)
		{
			cout<<element[i]<<endl;
			j=1;
			break;
		}
	if(j==0)
		cout<<"不存在该学号的学生信息"<<endl;
	}
}
void Sqlist::xmcx()
{
	string x,b,m;int i,j=0;
	while(j==0)
	{
	cout<<"请输入要查找的学生的学号,姓名,班级"<<endl;
	cin>>x>>m>>b;
	for(i=0;i<length;i++)
	{
		if(element[i].xh==x && element[i].xm==m && element[i].bj==b)
		{
			cout<<element[i]<<endl;
			j=1;
			break;
		}
	}
		if(j==0)
			cout<<"不存在该学生的信息"<<endl;
	}
}
void Sqlist::tj()
{
	int a[20];
	int i,j;
	for(i=0;i<20;i++)
		a[i]=1;
	for(i=0;i<length-1;i++)
	if(a[i]>=1)
		for(j=i+1;j<length;j++)
			if(element[i].bj==element[j].bj)
					{
					a[i]++;
                    a[j]=-1;
					}
	for(i=0;i<length;i++)
	if(a[i]>=1)
		cout<<element[i].bj<<"班一共有"<<a[i]<<"个学生"<<endl;
}
int Sqlist::cx()
{
	int i=0;
	if(empty())
	{
		cout<<"请输入学生信息";
		return 0;
	}
	cout<<"1.能够根据学号查询学生信息"<<endl;
    cout<<"2.能够根据姓名、学号、班级等查询学生信息"<<endl;
	cout<<"3.按照班级统计学生人数"<<endl;
	cout<<"请输入查询方式"<<endl;
	while(i<1 || i>3)
	{
	cin>>i;
	switch(i)
	{
		case 1:
			xhcx();
			break;
		case 2:
            xmcx();
			break;
		case 3:
			tj();
			break;
		default:
			break;
	}
	}
	return 0;
}
void Sqlist::dr()
{
	ifstream ifs;int i;
	ifs.open("/Users/yeyuxin/Desktop/实验报告/a.txt",ios::in);
    for(i=0;ifs;i++)
	{
		ifs>>element[i];
	length++;
	}
	ifs.close();
}
void Sqlist::bc()
{
	ofstream ofs;
	ofs.open("/Users/yeyuxin/Desktop/实验报告/a.txt",ios::trunc);
	int i;
	for(i=0;i<length;i++)
		ofs<<element[i]<<endl;
	ofs.close();
}
void cd()
{
	cout<<"	\t\t 请选择	\t\t\t"<<endl;
	cout<<"	\t\t学生信息管理系统\t\t\t"<<endl;
	cout<<"	\t\t1.输入学生信息\t\t\t"<<endl;
	cout<<"	\t\t2.按照学生学号排序\t\t\t"<<endl;
	cout<<"	\t\t3.根据学号修改学生信息\t\t\t"<<endl;
	cout<<"	\t\t4.根据学号删除学生信息\t\t\t"<<endl;
    cout<<"	\t\t5.查询功能:\t\t\t"<<endl;
    cout<<"			  1)根据学号查询学生信息"<<endl;
	cout<<"			  2)根据姓名,学号,班级等查询学生信息"<<endl;
	cout<<"			  3)按照班级统计学生人数"<<endl;
	cout<<" \t\t\t6.保存信息到文件\t\t\t"<<endl;
	cout<<"	\t\t7.退出学生信息管理系统"<<endl;
}
int main()
{
	Sqlist  A;
//A.dr();
int m;
do
{
	cd();
	cin>>m;
	switch(m)
	{
		case 1:
			A.sr();
		    cout<<"录入学生信息成功！"<<endl;
            break;
		case 2:
            A.px();
			 break;
		case 3:
			 A.xg();
			 break;
		case 4:
			 A.sc();
			 break;
		case 5:
			 A.cx();
			 break;
		case 6:
			 A.bc();
			 cout<<"success";
		default:
			 break;
	}
}while(m!=7);
	return 0;
} 

