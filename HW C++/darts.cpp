#include <iostream>
#include <math.h>
using namespace std;

int countscore(double a,double b) {
	double x = sqrt(a*a+b*b);
	if(x > 8 && x <= 10)
	{
		return 1;
	}else
	if(x > 6 && x <= 8)
	{
		return 2;
	}else
	if(x > 4 && x <= 6)
	{
		return 3;
	}else
	if(x > 2 && x <= 4)
	{
		return 4;
	}else
	if(x <=2)
	{
		return 5;
	}else
	{
		return 0;
	}

}

int main() {
	double n,a,b,sum;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		sum += countscore(a,b);
	}
	cout << sum << endl;
}
