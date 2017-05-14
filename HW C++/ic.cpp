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

ListNode* process(string str,int n,ListNode* header)
{
    if(str == "li")
    {
        ListNode* insert_node = new ListNode(n);
        insert_node -> next = header -> next;
        header -> next = insert_node;
    }else
    if(str == "ri"){
        ListNode* head_node = header;
        while(header -> next != 0)
        {
            header = header -> next;
        }
        ListNode* insert_node = new ListNode(n);
        header -> next = insert_node;
        header = head_node;
    }
    else
    if(str == "lr")
    {
        if(header -> next != 0){
        ListNode* new_node = new ListNode(header -> next -> val);
        ListNode* delete_node = header -> next;
        ListNode* head_node = header;
        header -> next = header -> next -> next;
        delete(delete_node);
        while(header -> next != 0)
        {
            header = header -> next;
        }
        header -> next = new_node;
        header = head_node;
        }else{}
    }else{
        if(header -> next != 0){
        ListNode* head_node = header;
        while(header -> next -> next != 0)
        {
            header = header -> next;
        }
        ListNode* new_node = new ListNode(header -> next -> val);
        ListNode* delete_node = header -> next;
        header -> next = header -> next -> next;
        delete(delete_node);
        header = head_node;
        new_node -> next = header -> next;
        header -> next = new_node;
        }else{}
    }
    return header;
}

int main()
{
    ListNode* header = new ListNode(0);
    int n,number;
    string str;
    cin >> n; 
    for(int i=0;i<n;i++)
    {
        cin >> str;
        if(str != "lr" && str != "rr")
        {
            cin >> number;
        }else{
            number = 0;
        }
        header = process(str,number,header);
    }
    print_list(header);
}