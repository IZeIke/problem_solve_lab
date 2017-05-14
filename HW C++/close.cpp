 #include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int n,l,sum;
	int count = 0;
	cin >> n >> l;
	int x[1000];
	for(int i=0;i<n;i++)
	{
		cin >> x[i]; 	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(j==i){}
			else{
				sum = abs(x[i]-x[j]);
				if(sum <= l)
				{
					count++;
				}	
			}
			
		}	
	}
	cout << count << endl;
}
