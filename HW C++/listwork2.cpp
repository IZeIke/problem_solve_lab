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
    node = node -> next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

ListNode* process(char str,int n,ListNode* header)
{
    if(str == 'I')
    {
        ListNode* insert_node = new ListNode(n);
        insert_node -> next = header -> next;
        header -> next = insert_node;
    }else
    if(str == 'D')
    {
        ListNode* delete_node = header;
        for(int i=0;i<n;i++)
        {
            if(header -> next == 0)
            {
                break;
            }
            if(i == n-1)
            {
                ListNode* newptr = header -> next;
                header -> next = header -> next -> next;
                delete(newptr);
                break;
            }
            header = header -> next;
        }
        header = delete_node;
    }else{
        ListNode* head_node = header;
        while(header -> next != 0)
        {
            header = header -> next;
        }
        ListNode* insert_node = new ListNode(n);
        header -> next = insert_node;
        header = head_node;
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