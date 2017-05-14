#include <iostream>

using namespace std;

void printStr(char* startPtr,char* str){
    for(int i=0;i<100;i++)
    {
        if(str == startPtr)
        {
            cout << *str;
            break;
        }
        cout << *str;
        str-- ;
    }

}

void printStrFinal(char* startPtr,char* str){
    for(int i=0;i<100;i++)
    {
        if(str == startPtr)
        {
            cout << *str << endl;
            break;
        }
        cout << *str;
        str-- ;
    }

}

void process(char* str){
    char* startPtr = str;
    for(int i=0;i<1001;i++)
    {
        if(*str == '_')
        {
            str--;
            printStr(startPtr,str);
            str = str+2;
            startPtr = str;
            cout << '_';
            continue;
        }
        if(*str == '\0')
        {
            str--;
            printStrFinal(startPtr,str);
            break;
        }
        str++;
    }
}

int main()
{
    char str[1001];
    cin.getline(str,1001);
    process(str);
}