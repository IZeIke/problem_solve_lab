#include <iostream>

using namespace std;

char cyclingChar(char cha)
{
	int x = (int) cha - 96;
	x = x + 4;
	x = x % 26;
	x = x + 96;
	return (char) x;	
}

void process(char* str,char* dest)
{
	for(int i=0;i<100;i++)
	{
		if(*str == '\0')
		{
			*dest = '\0';
			break;
		}else{
			*dest = cyclingChar(*str);
		}
		str++;
		dest++;
	}

}

int main()
{
	char str[100];
	char out[100];

	cin.getline(str,100);
	
	process(str,out);	

	cout << out << endl;
}
