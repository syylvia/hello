/*）设计一个堆栈的类模板Stack，在模板中用类型参数T表示栈中存放的数据，用非类型参数MAXSIZE代表栈的大小。实现栈元素的入栈和出栈。在main函数中定义Stack<int,5>和Stack<char,5>,测试该类模板*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Stack
{
	public:
	Stack()
	{
	  head=new node;
	}
	~Stack()
	{
		delete[]head;
	}
	int push(int b)
	{
		node *ps;int c;
		node  *pr=head;
		for(int i=1;i<b;i++)
		{
			ps=new node;
			cin>>c;
			ps->data=c;
			ps->next=NULL;
			head->next=ps;
			head=ps;
		}
	head=pr;	
			return 0;
	}
	void sc()
	{
		if(head->next==NULL)
			cout<<"qingxianshuru";
		else
			for(node *p=head->next;p;p=p->next)
			{
				cout<<p->data<<" ";
			}
	}
		private:
	node *head;
};
int main()
{
	Stack a;
	a.push(4);
	a.sc();
	return 0;
}


