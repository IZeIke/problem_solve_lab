#include<iostream>
#include<string>

using namespace std;

int main(){

	int n;	
	string str;
	string str1;
	cin >> str;
	str1 = str;
	cin >> n;
	int c = 0;
	string order[1000];	
	int length = str.length();
	for(int i=0;i<length-(n-1);i++)
	{
		str[i] = '0';
		for(int j=i+1;j<length-(n-2);j++)
		{
			for(int k=j;k<j+(n-1);k++)
			{
				str[k]='0';	
			}
			for(int l=0;l<length;l++)
			{
				if(str[l] != '0')
				{
					order[c] += str[l];
				}
			}
			cout << order[c] << endl;
			str = str1;
			str[i] = '0';
			c++;
		}
		cout << "end pharse" << endl;
		str = str1;
	}

}
