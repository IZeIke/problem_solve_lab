#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check(int num,int k)
{
	int check = 0;
	int r;
	for(int i=k;i>0;i--)
	{
		if(i==k)
		{
			r = num/pow(10,i-1);	
			num = num-r*pow(10,i-1);	
		}else{
			if(r <= num/pow(10,i-1))
			{
				check++;	
			}else{
				num = num-r*pow(10,i-1);	
			}
		}
	}
	if(check > 0)
	{
		return false;
	}else{
		return true;
	}
			
}

int main()
{
	string str;
	int k;
	int c=0;
	cin >> str;
	cin >> k;
	int length = str.length();
	int cut[1000];
	for(int i=pow(10,k-1);i<length*pow(10,k-1);i++)
	{
		if(check(i,k))
		{
			cut[c]=i;
			c++;	
		}
	}
	for(int i=0;i<=c;i++)
	{
		cout << cut[i] <<endl;
	}
}

