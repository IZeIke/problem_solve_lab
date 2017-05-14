#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void insert(TreeNode*& r,valueType x)
{
    if(!r)
    {
        r = new TreeNode(x);
    }else
    if(x > r->val)
    {
        insert(r->right,x);
    }else
    if(x < r->val)
    {
        insert(r->left,x);
    }else{}
}

TreeNode* find(TreeNode* r, valueType x)
{
    if(!r)
    {
        return '\0';
    }else
    if(x > r->val)
    {
        return find(r->right,x);
    }else
    if(x < r->val)
    {
        return find(r->left,x);
    }else{
        return r;
    }
}



int main()
{
    int n;
    TreeNode* r = 0;    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int k,x;
        cin >> k >> x;
        if(k == 1)
        {
            insert(r,x);
        }else
        {
            if(find(r,x))
            {
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
    }
} 