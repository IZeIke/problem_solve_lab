#include <iostream>

using namespace std;

int main()
{
	int n,x,sum;
	int count = 0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		sum += x;
		if(sum>1000)
		{
			sum = x;
			count++;
		}else
		if(sum == 1000 && i != n-1)
		{
			sum = 0;
			count++;
		}
		if(i == n-1 && sum <=1000)
		{
			count++;
		}
	}
	cout << count << endl;
}	
