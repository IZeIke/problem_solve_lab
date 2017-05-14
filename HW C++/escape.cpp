#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st)
{
	for(int i=0;*st != '\0';i++)
	{
		*dest = *st;
		dest++;
		st++;
	}

	return dest;
}

void escape(char* src, char* dest)
{
	for(int i=0;i<1000;i++)
	{
  		if(*src == '\0')
  		{
    			*dest = '\0';
			break;
 		}else
 		if(*src == '<')
  		{
    			dest = write_chars(dest,"&lt;");
			src++;
			continue;
  		}else
		if(*src == '>')
		{
			dest = write_chars(dest,"&gt;");
			src++;	
			continue;	
		}else
		if(*src == '\"')
		{
			dest = write_chars(dest,"&quot;");
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
 	escape(st,out);
	
 	cout << out << endl;
}
