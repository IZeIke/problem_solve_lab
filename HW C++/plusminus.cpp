#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum;
	int num;
	int c = 0;
	int number[1000];
	string sign;
	string str = "";
	cin >> n;
	for(int i=1;i<=n*2-1;i++)
	{
		if(i%2 == 0)
		{
			cin >> sign;
			str += sign; 
		}else{
			cin >> num;
			number[c] = num;
			c++;
		}
	}
	sum = number[0];
	for(int i=0;i<n-1;i++)
	{
		if(str[i] == '+')
		{
			sum += number[i+1];
		}else
		if(str[i] == '-')
		{
			sum -= number[i+1];
		}else{}
	}
	cout << sum << endl;
}
