#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b;
	if(a<=b)
	{
		for(int i=a;i>0;i--)
		{
			if(a%i==0 && b%i==0)
			{
				c = i;
				i=0;		
			}
		}
		cout << a/c << "/" << b/c << endl;
	}else 
	if(b<a)
	{
		for(int i=b;i>0;i--)
		{
			if(a%i==0 && b%i==0)
			{
				c = i;
				i=0;		
			}
		}
		cout << a/c << "/" << b/c << endl;
	} 

}
