#include <iostream>
#include <string>

using namespace std;

int xposition(char str,int x){
	if(str == 'E')
	{
		x++;
	}else
	if(str == 'W')
	{
		x--;
	}else
	{
		x=0;
	}
	return x;	
}

int yposition(char str,int y)
{
	if(str == 'N')
	{
		y++;
	}else
	if(str == 'S')
	{
		y--;
	}else
	{
		y=0;
	}
	return y;
}

int main(){
	string str;
	int pos[2];
	pos[0] = 0;
	pos[1] = 0;
	cin >> str;
	int length = str.length();
	for(int i=0;i<length;i++)
	{
		if(str[i]=='E' || str[i]=='W')
		{
			pos[0] = xposition(str[i],pos[0]);	
		}else
		if(str[i]=='S' || str[i]=='N')
		{
			pos[1] = yposition(str[i],pos[1]);
		}else
		{
			pos[0]=0;
			pos[1]=0;
		}	
	}
	cout << pos[0] << " " << pos[1] << endl;
}
