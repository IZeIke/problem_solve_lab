#include <iostream>

using namespace std;

bool check_prime(int p)
{
	if (p <= 1) {
		return false;
	}
  
	int x = 0;
	for(int i = 2;i < p;i++){
  		if(p % i == 0){
    			x = 1;
		}
	}

	if(x == 0)
	{
  		return true;
	}else
	{
  		return false;
	}

}


int main()
{
	int x;
	cin >> x;
	for(int i=1;i<100;i++)
	{
		x += 1;
		if(check_prime(x))
		{
			i = 100;
		}
	}
	cout << x << endl; 
}
