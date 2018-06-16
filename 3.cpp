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
class Student
{
	public:
		static int num;
		Student();
		~Student();
		void cd();
		void sr(Student stu[]);
		int px(Student stu[]);
		int xg(Student stu[]);
		int sc(Student stu[]);
		int cx(Student stu[]);
		void xhcx(Student stu[]);
		void xmcx(Student stu[]);
		void tj(Student stu[]);
		void dr(Student stu[]);
		void bc(Student stu[]);
    Student& operator=(Student &temp);
    friend ostream& operator<<(ostream& os,Student& stu);
	private:
		char *xm;
		char *xb;
        string  xh;
		string  bj;
		string dh;
};
int Student::num=0;
//Student stu[20];
Student::Student()
{
	xm=NULL;
	xb=NULL;
}
Student::~Student()
{
	delete[]xm;
	delete[]xb;
}
Student& Student::operator=(Student &temp)
{
delete[]this->xm;
delete[]this->xb;
this->xm=new char[strlen(temp.xm)+1];
this->xb=new char[strlen(temp.xb)+1];
strcpy(this->xm,temp.xm);
strcpy(this->xb,temp.xb);
this->xh=temp.xh;
this->bj=temp.bj;
this->dh=temp.dh;
return *this;
}
void  Student::cd()
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
void Student::sr(Student stu[])
{
	int i=0,j;
	char *m=new char[10];
	char *b=new char[10];
	cout<<"请输入学生姓名,性别,学号,班级,联系电话"<<endl;
	cin>>m>>b>>xh>>bj>>dh;
	while(i==0)
	{
		for(j=0;j<num;j++)
			if(this->xh==stu[j].xh)
			{
				cout<<"该学号已存在，请重新输入学号";
				cin>>xh;
			}
		if(j==num)
			i=1;
	}
	int len1=strlen(m)+1;
	int len2=strlen(b)+1;
	xm=new char[len1];
	xb=new char[len2];
	strcpy(xm,m);
	strcpy(xb,b);
	num++;
	delete[]m;
	delete[]b;
}
int Student::px(Student stu[])
{
	if(Student::num==0)
	{
		cout<<"请先输入学生信息"<<endl;
	     return 0;
	}
   int i,j;
   Student temp;
   for(i=0;i<Student::num-1;i++)
	   for(j=i+1;j<Student::num;j++)
	   {
		   if(stu[i].xh>stu[j].xh)
		   {
			   temp=stu[i];
			   stu[i]=stu[j];
			   stu[j]=temp;
		   }
	   }
   cout<<"按照学号排序后："<<endl;
   for(i=0;i<Student::num;i++)
	   cout<<stu[i]<<endl;
   return 0;
}
int Student::xg(Student stu[])
{
	if(Student::num==0)
	{
		cout<<"请先输入学生信息"<<endl;
		return 0;
	}
	string  x;int i=0,j;
	while(i==0)
	{
	cout<<"请输入所要修改的学生的学号："<<endl;
	cin>>x;
		for(j=0;j<Student::num;j++)
			if(x==stu[j].xh)
			{
				delete[]stu[j].xm;
                delete[]stu[j].xb;
				cout<<"请输入修改后的学生姓名,性别,班级,电话";
				char *m=new char[10];
	            char *b=new char[10];
	            cin>>m>>b>>stu[i].bj>>stu[i].dh;
	            stu[j].xm=new char[strlen(m)+1];
	            stu[j].xb=new char[strlen(b)+1];
	            strcpy(stu[j].xm,m);
	            strcpy(stu[j].xb,b);
	            delete[]m;
	            delete[]b;
	            i=1;
				cout<<"修改成功！"<<endl;
	        }
	    }
	return 0;
}
int Student::sc(Student stu[])
{
	if(Student::num==0)
	{
      cout<<"请输入学生信息"<<endl;
	  return 0;
	}
	string x;int i=0,j,k;
	while(i==0)
	{
	cout<<"请输入所要删除学生的学号";
	cin>>x;
	for(j=0;j<Student::num;j++)
		if(stu[j].xh==x)
		{
			for(k=j+1;j<Student::num;j++)
			stu[k-1]=stu[k];
			Student::num--;
			i=1;
			delete[]stu[j].xm;
			delete[]stu[j].xb;
		    cout<<"删除成功"<<endl;
		}
	}
	return 0;
}
void Student::xhcx(Student stu[])
{
	string  x;int i,j=0;
	while(j==0)
	{
	cout<<"请输入学号"<<endl;
	cin>>x;
	for(i=0;i<Student::num;i++)
		if(stu[i].xh==x)
		{
			cout<<stu[i]<<endl;
			j=1;
			break;
		}
	if(j==0)
		cout<<"不存在该学号的学生信息"<<endl;
	}
}
void Student::xmcx(Student stu[])
{
	string x,b;int i,j=0;
	while(j==0)
	{
	char *m=new char[10];
	cout<<"请输入要查找的学生的学号,姓名,班级"<<endl;
	cin>>x>>m>>b;
	for(i=0;i<Student::num;i++)
	{
		int n=strcmp(stu[i].xm,m);
		if(stu[i].xh==x && n==0 && stu[i].bj==b)
		{
			cout<<stu[i]<<endl;
			delete[]m;
			j=1;
			break;
		}
	}
		if(j==0)
		{
			cout<<"不存在该学生的信息"<<endl;
		delete[]m;
		}
	}
}
void Student::tj(Student stu[])
{
	int a[20];
	int i,j;
	for(i=0;i<20;i++)
		a[i]=1;
	for(i=0;i<Student::num-1;i++)
	if(a[i]>=1)
		for(j=i+1;j<Student::num;j++)
			if(stu[i].bj==stu[j].bj)
					{
					a[i]++;
                    a[j]=-1;
					}
	for(i=0;i<Student::num;i++)
	if(a[i]>=1)
		cout<<stu[i].bj<<"班一共有"<<a[i]<<"个学生"<<endl;
}
int Student::cx(Student stu[])
{
	int i=0;
	if(Student::num==0)
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
			xhcx(stu);
			break;
		case 2:
            xmcx(stu);
			break;
		case 3:
			tj(stu);
			break;
		default:
			break;
	}
	}
	return 0;
}
ostream& operator<<(ostream& os,Student& stu)
{
	os<<stu.xm<<" "<<stu.xb<<" "<<stu.xh<<" "<<stu.bj<<" "<<stu.dh;
	return os;
}
void Student::dr(Student stu[])
{
	ifstream ifs;int i;
	ifs.open("/Users/yeyuxin/Desktop/实验报告/a.txt",ios::in);
    for(i=0;ifs;i++)
	{
		stu[i].xm=new char[10];
	    stu[i].xb=new char[10];
		ifs>>stu[i].xm>>stu[i].xb>>stu[i].xh>>stu[i].bj>>stu[i].dh;
		Student::num++;
	}
	ifs.close();
}
void Student:: bc(Student stu[])
{
	ofstream ofs;
	ofs.open("/Users/yeyuxin/Desktop/实验报告/a.txt",ios::trunc);
	int i;
	for(i=0;i<Student::num;i++)
		ofs<<stu[i].xm<<" "<<stu[i].xb<<" "<<stu[i].xh<<" "<<stu[i].bj<<" "<<stu[i].dh<<endl;
	ofs.close();
}
int main()
{
	Student stu[20];
	stu[0].dr(stu);
int m;
do
{
	stu[0].cd();
	cin>>m;
	switch(m)
	{
		case 1:
		 cout<<"请输入要输入学生信息的个数";
			int n,i,m;
			cin>>n;
			m=Student::num;
			for(i=m;i<n+m;i++)
			stu[i].sr(stu);
		    cout<<"录入学生信息成功！"<<endl;
            break;
		case 2:
             stu[0].px(stu);
			 break;
		case 3:
			 stu[0].xg(stu);
			 break;
		case 4:
			 stu[0].sc(stu);
			 break;
		case 5:
			 stu[0].cx(stu);
			 break;
		case 6:
			 stu[0].bc(stu);
		default:
			 break;
	}
}while(m!=7);
	return 0;
} 


