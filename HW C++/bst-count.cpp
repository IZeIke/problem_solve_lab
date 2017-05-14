#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  valueType childL;
  valueType childR;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, valueType childL=0, valueType childR=0 ,TreeNode* left=0, TreeNode* right=0)
    : val(val),childL(childL),childR(childR), left(left), right(right) {}
};

void insert(TreeNode*& r,valueType x)
{
    if(!r)
    {
        r = new TreeNode(x);
    }else
    if(x > r->val)
    {
        (r -> childR)++;
        insert(r->right,x);
    }else
    if(x < r->val)
    {
        (r -> childL)++;
        insert(r->left,x);
    }else{}
}

int c = 0;
void count(TreeNode* r, valueType x)
{
    if(!r)
    {
        return;
    }
    if(x <= r->val)
    {
        if(x == r->val)
        {
            c+= (r -> childR);   
        }else{
            c+= (r -> childR)+1;
        }   
        count(r->left,x);
    }
    if(x > r->val)
    {
        count(r->right,x);
    }
    
}



int main()
{
    int n;
    TreeNode* r = 0;    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k,x;
        scanf("%d %d",&k,&x);
        if(k == 1)
        {
            insert(r,x);
        }else
        {
            count(r,x);
            printf("%d\n",c);
            c=0;
        }
    }
} 