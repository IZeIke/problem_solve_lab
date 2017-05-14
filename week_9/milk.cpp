#include <iostream>
#include <string>
#include <stdio.h>
#include<stack>
#include<vector>
using namespace std;

int n,q,x,y;
char s;
int num[100000];
int root[100000];

void init(){
    for(int i=0;i<n;i++)
    {
        root[i] = i; 
    }
}

int findroot(int a){
    if(root[a] == a)
    {
        return a;
    }

    root[a] = findroot(root[a]);
    return root[a];
}



int main(){
    
    //cin >> n >> q;
    scanf("%d %d",&n,&q);

    init();

    for(int i=0;i<q;i++)
    {
        //cin >> s >> x >> y;
        scanf("%s %d %d",&s,&x,&y);
        x--; y--;

        if(s == 'q')
        {
            if(findroot(x) == findroot(y))
            {
                printf("yes \n");
            }else{
                printf("no \n");
            }

        }else{
            if(findroot(x) != findroot(y))
            {
                root[findroot(x)] = findroot(y);
            }
        }
    }

}