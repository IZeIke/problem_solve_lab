#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  valueType childL;
  valueType childR;
  valueType level;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, valueType childL=0, valueType childR=0 ,valueType level = 0,TreeNode* left=0, TreeNode* right=0)
    : val(val),childL(childL),childR(childR),level(level), left(left), right(right) {}
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
        r->right->level = r->level + 1;
    }else
    if(x < r->val)
    {
        (r -> childL)++;
        insert(r->left,x);
        r->left->level = r->level + 1;
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

TreeNode* find_min(TreeNode* r)
{
  while (r->left != NULL)
  {
    r = r->left;
  }
  return r;
}

TreeNode* deletekey(TreeNode* r,valueType x)
{
     if(!r)
    {
        return '\0';
    }else
    if(x > r->val)
    {
        r->right = deletekey(r->right,x);
    }else
    if(x< r->val)
    {
        r ->left = deletekey(r->left,x);
    }else
    {
        if(r->left == NULL && r->right == NULL)
        {
            delete r;
            r=NULL;
        }else
        if(r->left == NULL)
        {
            r = r->right;
        }else
        if(r->right == NULL)
        {
            r = r->left;
        }else
        {
            TreeNode* temp = find_min(r->right);
            r -> val = temp -> val;
            r -> right = deletekey(r->right,temp->val);
        }
    }
    return r;
}

void printTree(TreeNode* r)
{
    if(!r){
        return;
    }
    printTree(r -> right);
    for(int i=0;i<r->level;i++){
        cout << "...";
    }
    cout << "* ";
    cout << r->val << endl;
    printTree(r->left);
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
        if(k == 2)
        {
            if(find(r,x))
            {
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        else{
            r = deletekey(r,x);
        }
    }
    //printTree(r);
} 