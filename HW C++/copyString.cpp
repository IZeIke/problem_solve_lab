#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
	for(int i=0;i < 1000;i++)
	{ 
		if(*src == '\0')
		{
			*dest = '\0';
		}else{
			*(dest) = *(src);
		}
		dest++;
		src++;
	}
}

int main()
{
  	char st1[1000];
  	char st2[1000];

  	cin.getline(st1,1000);
 	copy_string(st1,st2);
	
 	cout << st2 << endl;
}
