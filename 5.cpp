#include<iostream>
using namespace std;
template<class T>
class Array
{
	public:
		Array(int n)
		{
            size=n;
			cf=new T[size+1];
		}
		~Array()
		{
	        delete[]cf;
		}
		T &operator[](int n)
		{
			T c=0;
			if(n<0||n>size)
			{
				cout<<"chaoshufanwei";
					return c;
			}
			else
				return *(cf+n);
		}
        T count(int n)
		{
			T sum=0;
			for(int i=0;i<n;i++)
				sum=sum+*(cf+i);
			return sum;
		}
	private:
		T *cf;
        int size;
};
int main()
{
	int s;
	Array<int> a(20);
	for(int i=0;i<10;i++)
	{
        cin>>s;
		a[i]=s;
	}
	cout<<a.count(10);
	cout<<endl;
	a[3]=100;
	cout<<a[4]<<endl;
	cout<<a.count(10);
	return 0;
}





