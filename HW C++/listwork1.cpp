#include <iostream>

using namespace std;

typedef int valueType;

int count = 0;
int state =0;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void print_list(ListNode* node)
{
  while(node->next != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

ListNode* process(char str,int n,ListNode* header)
{
  if(str == 'I')
  {
    ListNode* newheader = new ListNode(n);
    newheader -> next = header;
    header = newheader;
    count++;
  }
  else
  {
    ListNode* pos = header;
    for(int i=1;i<=n;i++)
    {
      if(header == 0)
      {
        break;
      }
      if(n == 1 && count > 0)
      {
        ListNode* newptr = header;
        header = header-> next;
        delete(newptr);
        count--;
        state++;
        break;
      }
      if(i == n-1 && count > 0 && header -> next -> next !=0)
      {
        ListNode* newptr = header -> next;
        header -> next = header -> next -> next;
        delete(newptr);
        count--;
        break;
      }
      header = header -> next;
    }
    if(state == 0){
      header = pos;  
    } else{
      state = 0;
    } 
  }
  return header;
}

int main()
{
    ListNode* header = new ListNode(0);
    int n,number;
    char str;
    cin >> n; 
    for(int i=0;i<n;i++)
    {
        cin >> str >> number;
        header = process(str,number,header);
    }
    print_list(header);
}