#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 1;
	int s = 4;
	int e = 3;
	int w = 2;
	int pos = n;
	string str;
	string str2000 = "";
	cin >> str;
	int length = str.length();
	for(int i=0;i<length;i++)
	{		
		if( (str[i]=='N' && pos == n) || (str[i]=='E' && pos == e) || (str[i]=='W' && pos == w) || (str[i]=='S' && pos == s))
		{
			str2000 += "F";
		}else
		if( (str[i]=='E' && pos == n) || (str[i]=='S' && pos == e) || (str[i]=='N' && pos == w) || (str[i]=='W' && pos == s) )
		{
			str2000 += "RF";
		}else
		if( (str[i]=='W' && pos == n) || (str[i]=='N' && pos == e) || (str[i]=='S' && pos == w) || (str[i]=='E' && pos == s) )
		{
			str2000 += "RRRF";
		}else
		if( (str[i]=='S' && pos == n) || (str[i]=='W' && pos == e) || (str[i]=='E' && pos == w) || (str[i]=='N' && pos == s) )
		{
			str2000 += "RRF";
		}else{
			str2000 += "Z";
		}
		

		if(str[i] == 'N')
		{
			pos = n;
		}else
		if(str[i] == 'S')
		{
			pos = s;
		}else
		if(str[i] == 'E')
		{
			pos = e;
		}else
		if(str[i] == 'W')
		{
			pos = w;
		}else
		{
			pos = n;
		}

	}
	cout << str2000 << endl;
}
