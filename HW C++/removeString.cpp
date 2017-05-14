#include <iostream>
using namespace std;

void remove_quotes(char* src, char* dest)
{
	for(int i=0;i<1000;i++)
	{
  		if(*src == '\0')
  		{
    			*dest = '\0';
 		}else
 		if(*src == '\'' || *src == '\"')
  		{
    			src++;
			continue;
  		}else{
    			*dest = *src;
  		}
  		src++;
  		dest++;
	}	
}

int main()
{
  	char st[1000];
  	char out[1000];

  	cin.getline(st,1000);
 	remove_quotes(st,out);
	
 	cout << out << endl;
}
