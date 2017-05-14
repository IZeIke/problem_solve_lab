#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  valueType level;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val,valueType level = 0, TreeNode* left=0, TreeNode* right=0)
    : val(val),level(level), left(left), right(right) {}
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
        r->right->level = r->level + 1;
    }else
    if(x < r->val)
    {
        insert(r->left,x);
        r->left->level = r->level + 1;
    }else{}
}

void bigorder(TreeNode* r)
{
    if(!r){
        return;
    }
    bigorder(r -> right);
    for(int i=0;i<r->level;i++){
        cout << "...";
    }
    cout << "* ";
    cout << r->val << endl;
    bigorder(r->left);
}


int main()
{
    int n,x;
    TreeNode* r = 0;    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        insert(r,x);
    }
    bigorder(r);
} 