#include<iostream>
#include<cstring>
using namespace std;
template<class T1,class T2>
class ArrayList
{
	public:
		ArrayList()
		{
		}
		~ArrayList()
		{
			delete[]element;
		}
		ArrayList(T1 intialcapacity)
		{
			if(intialcapacity<1)
			{
			 cout<<"intialcapacity="<<intialcapacity<<"must be >0";
			}
			arraylength=intialcapacity;
			element=new T2[arraylength];
			listsize=0;
		}
		void insert(T1 theindex,const T2 &thelement)
		{
			if(theindex<0||theindex>listsize)
			{
				cout<<"index="<<theindex<<"size="<<listsize;
				cout<<"index  >0 && index<size";
			}
			if (listsize==arraylength)
			{
				changelength(element,arraylength);
				arraylength*=2;
			}
			copy(element+theindex,element+listsize,element+theindex+1);
			element[theindex]=thelement;
			listsize++;
		}
		void earse(T1 theindex)
		{
			if(theindex<0||theindex>listsize)
			{
				cout<<"index="<<theindex<<"size="<<listsize<<endl;
			    cout<<"index>0 && index<size"<<endl;
			}
			copy(element+theindex+1,element+listsize,element+theindex);
			listsize--;
		}
		void changelength(T2 *&ele,T1 arr)
		{
			ele=new T2[arr]; 
		}
		void get(T2*ele)
		{
		strcpy(element,ele);
		T1 num=strlen(ele);
		listsize=listsize+num;
		}
		void amend(T1 theindex,const T2 &a)
		{
          if(theindex<0||theindex>listsize)
		  {
			  cout<<"index="<<theindex<<"size="<<listsize<<endl;
			  cout<<"index>0 && index<size"<<endl;
		  }
		  element[theindex]=a;
		}
		void show()
			{
				for(T1 i=0;i<listsize;i++)
				cout<<*(element+i);
			}
	private:
		T1 arraylength;
	    T2 *element;
        T1  listsize;
};
int main()
{
   int num;
   char*ele=new char[10];
   char a;
   ArrayList<int,char> arraylist(10);
   cout<<"请输入相应的字符";
   cin>>ele;
   arraylist.get(ele);
   arraylist.show();
   cout<<"请输入要插入的位置和字符";
   cin>>num>>a;
   arraylist.insert(num,a);
   arraylist.show();
   cout<<"请输入所要删除的位置";
   cin>>num;
   arraylist.earse(num);
   arraylist.show();
   cout<<"请输入所要改变的位置和修改后的字符";
   cin>>num>>a;
   arraylist.amend(num,a);
   arraylist.show();
   delete[]ele;
   return 0;
}


