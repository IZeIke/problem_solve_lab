#include <iostream>

using namespace std;

char Upper(char cha)
{
	int ascii = (int)cha;
	if(ascii >= 97 && ascii <= 122)
	{
		ascii = ascii - 32;
	}
	
	return (char)ascii;
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
			*dest = Upper(*str);
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
