#include <iostream>

using namespace std;

int main()
{
	int a,b,c,n,t;
	int na = 1;
	int nb = 1;
	int nc = 1;
	int ca = 0;
	int cb = 0;
	int cc = 0;
	int summin = 1000000;
	int s = 0;
	int type[1000];
	cin >> a >> b >> c;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		type[i] = t;		
	}

	for(int i=0;i<n-1;i++)
	{
		
		for(int j=i+1;j<n;j++)
		{
			if(type[i]==type[j])
			{
				if(type[j] == 1)
				{
					na++;
					ca++;
				}else
				if(type[j] == 2)
				{
					nb++;
					cb++;
				}else
				if(type[j] == 3)
				{
					nc++;
					cc++;
				}else{}
				type[j] = 0;
				s=1;
			}else
			{
				if(type[i] == 1)
				{
					ca++;
				}else
				if(type[i] == 2)
				{
					cb++;
				}
				else{
					cc++;
				}
			}	
		}
		if(s == 1)
		{
			type[i] = 0;
			s = 0;
		}
		
	}

	int cn[3] = {ca,cb,cc};
	int sum;
	for(int i=0;i<3;i++)
	{
		if(cn[i]>0)
		{
			if(i+1 == 1)
			{
				sum = na*a;		
			}else
			if(i+1 == 2)
			{
				sum = nb*b;
			}else{
				sum = nc*c;
			}
		}
		if(sum < summin)
		{
			summin = sum;
		}
	}

	cout << summin << endl; 
	
}
