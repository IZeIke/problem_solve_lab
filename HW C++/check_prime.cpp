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
  		return false;
	}else
	{
  		return true;
	}

}

int main()
{
	int p;
  	cin >> p;

  	if (check_prime(p)) {
    		cout << "yes" << endl;
  	} else {
    		cout << "no" << endl;
  	}
}
