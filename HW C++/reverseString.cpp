#include <iostream>

using namespace std;

void process(char* str)
{
    char* pos = str;
    for(int i=0;i<1001;i++)
    {
        if(*str == '\0')
        {
            str--;
            break;
        }
        str++;
    }
    for(int i=0;i<1001;i++)
    {
        if(str == pos)
        {
            cout << *str << endl;
            break;
        }
        cout << *str;
        str--;
    }
}

int main()
{
    char str[1001];
    cin.getline(str,1001);
    process(str);
}