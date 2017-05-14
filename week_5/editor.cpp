#include <list>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    list<string> x;
    int n;
    char k;
    string str;
    cin >> n;
    list<string>:: iterator p = x.begin();
    for(int i=0;i<n;i++)
    {
        cin >> k;  
        if(k == 'l') //left
        {
            if(p != x.begin()){
               --p;
            }
        }
        else
        if(k == 'r') //right
        {
            if(p != x.end()){
               p++;
            }
        }
        else
        if(k == 'i')  //insert
        {
            cin >> str;
            x.insert(p,str);
        }
        else
        if(k == 'b') //backspace
        {
            if(p != x.begin()){
                p--;
                p = x.erase(p);
            }
        }
        else
        if(k == 'd') //delete
        {
            if(p != x.end()){
                p = x.erase(p);
            }
        }
    }

    for(list<string>::iterator i=x.begin();i != x.end();i++){
        cout << *i << endl;
    }
    
}