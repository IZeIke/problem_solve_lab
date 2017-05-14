#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
using namespace std;

string beiju(char* str)
{
    string s = "";
    //char* head = str;
    while(*str != '\0')
    {
        if(*str == '[')
        {
            str++;
            while(*str != ']' && *str != '[')
            {
                str++;
            }
            char* save = str;
            str--;
            while(*str != '[')
            {
                s = *str + s;
                str--;
            }
            str = save;
            str--;
        }else{
            if(*str != '[' && *str != ']')
            {
                s = s + *str;
            }
        }
        str++;
    }

    return s;
}

int main(){
    char str[100001];
    cin.getline(str,100001);

    string ans = beiju(str);

    cout << ans << endl;

}