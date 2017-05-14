#include <iostream>

using namespace std;

void plusInt(char* a,char* b,int* out)
{
    char* startA = a;
    char* startB = b;
    int* startOut = out;
    int sum;
    int add = 0;
    while(*a != '\0')
    {
        a++;
    }
    a--;
    while(*b != '\0')
    {
        b++;
    }
    b--;
    char *conPos;
    char *startPos;
    while(true)
    {
        if(a == startA || b == startB)
        {
            sum = ((*a-'0')+(*b-'0')+add)%10;
            add = ((*a-'0')+(*b-'0')+add)/10;
            *out = sum;
            if(a == startA)
            {
                conPos = b-1;
                startPos = startB;
            }else{
                conPos = a-1;
                startPos = startA;
            }
            out++;
            break;
        }
        sum = ((*a-'0')+(*b-'0')+add)%10;
        add = ((*a-'0')+(*b-'0')+add)/10;
        *out = sum;
        out++;
        a--;
        b--;
    }
    while(conPos != startPos)
    {
        sum = ((*conPos-'0')+add)%10;
        add = ((*conPos-'0')+add)/10;
        *out = sum;
        out++;
        conPos--;
    }
    sum = ((*conPos-'0')+add)%10;
    add = ((*conPos-'0')+add)/10;
    *out = sum;
    if(add>0)
    {
        out++;
        *out = add;

    }else{
        
    }

    while(out != startOut)
    {
        cout << *out;
        out--;
    }
    cout << *out << endl;
    
}


void process(char* a,char* b)
{
    int out[100];
    plusInt(a,b,out);
}

int main(){
    char a[1000];
    char b[1000];
    cin.getline(a,1000);
    cin.getline(b,1000);
    process(a,b);
    
}