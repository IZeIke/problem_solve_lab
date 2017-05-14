#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;
  int pos;

  ListNode(valueType val,ListNode* next=0)
    : val(val), next(next) {}
};

void print_list(ListNode* node)
{
  
  while(node != 0) {
    //cout << node->val << endl;
    printf("%d\n",node->val);
    node = node->next;
  }
}

ListNode* insert(int n , ListNode* header)
{
  if(header == 0)
  {
    ListNode* new_header = new ListNode(n);
    header = new_header;
  }else{
    ListNode* pos = header;
    ListNode* new_node = new ListNode(n);
    while(header -> next != 0)
    {
      header = header -> next;
    }
    header -> next = new_node;
    header = pos;
  }
  return header;
}

ListNode* move(ListNode* header,ListNode* des)
{
  if(header == 0 && des == 0){}else{
    if(des == 0)
    {
      ListNode* new_node = new ListNode(header -> val);
      des = new_node;
      header = header -> next;
    }
    if(header != 0){
    ListNode* pos = des;
    ListNode* copy_head = new ListNode(header -> val);
    ListNode* pos_copy = copy_head;
    while(des -> next != 0)
    {
      des = des -> next;
    }
    header = header -> next;
    while(header != 0)
    {
      ListNode* cp = new ListNode(header -> val);
      copy_head -> next = cp;
      copy_head = cp;
      header = header -> next;
    }
    copy_head = pos_copy;
    des -> next = copy_head;
    des = pos;
    }else{}
  }
    return des;
}

ListNode* deleteNode(ListNode* header)
{
  while(header != 0)
  {
    ListNode* new_node = header;
    header = header-> next;
    delete(new_node);
  }
  return header;
}

int main()
{
    ListNode** arrayOfPointers = new ListNode*[100001];
    char str;
    int m,s,n;  
    //cin >> m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
      cin >> str >> n >> s;
      //scanf("%s %d %d",&str,&n,&s);
      if(str == 'N'){
        arrayOfPointers[s] = insert(n,arrayOfPointers[s]);
      }else{
        arrayOfPointers[s] = move(arrayOfPointers[n],arrayOfPointers[s]);
        arrayOfPointers[n] = deleteNode(arrayOfPointers[n]);
      }
    } 
    for(int i=0;i<100001;i++){
      print_list(arrayOfPointers[i]);
    }
}