#include <iostream>

using namespace std;

void printStr(char* str,char* finalStr)
{
    while(str != finalStr)
    {
        cout << *str;
        str++;
    }
    cout << *str;
}

void printFinal(char* str,char* finalStr)
{
    while(str != finalStr)
    {
        cout << *str;
        str++;
    }
    cout << *str << endl;
}

void process(char* str)
{
    char* fisrtPtr = str;
    for(; *str != '\0' ; str++){    
    }
    str--;
    char* finalPtr = str;
    while(true)
    {
        if(*str == '_')
        {
            str++;
            printStr(str,finalPtr);
            cout << '_';
            str = str - 2;
            finalPtr = str;
        }
        if(str == fisrtPtr)
        {
            printFinal(str,finalPtr);
            break;
        }
        str--;
    }
}

int main()
{
    char str[1001];
    cin.getline(str,1001);
    process(str);
}