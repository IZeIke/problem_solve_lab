#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;
  valueType high;

  TreeNode(valueType val,TreeNode* left=0, TreeNode* right=0,valueType high = 0)
    : val(val) ,left(left), right(right), high(high) {}

    void update_high()
    {
        int lh = (left == 0) ? -1 : left->high;
        int rh = (right == 0) ? -1 : right->high;
       // cout << lh << " " << rh << endl;
        high = (lh > rh) ? lh + 1 : rh + 1;
    }
};

void left_rotation(TreeNode*& node)
{
    TreeNode* a = node;
    TreeNode* b = node->right;
    TreeNode* T2 = b->left;

    a->right = T2;
    b->left = a;
    node = b;
  
    a->update_high();
    b->update_high();
}

void right_rotation(TreeNode*& node)
{
    TreeNode* a = node;
    TreeNode* b = node->left;
    TreeNode* T2 = b->right;

    a->left = T2;
    b->right = a;
    node = b;

    a->update_high();
    b->update_high();
}

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

    r -> update_high();

    int lh = (r -> left == 0) ? -1 : r->left->high;
    int rh = (r ->right == 0) ? -1 : r->right->high;

    if(rh > lh+1){
        left_rotation(r);
    }else
    if(lh > rh+1){
        right_rotation(r);
    }
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
    int k,x;
    TreeNode* r = 0;    
    cin >> n;
    for(int i=0;i<n;i++)
    {  
        scanf ("%d %d", &k, &x);
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