#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void insert_front(ListNode* header, valueType x)
{
    ListNode* newNode = new ListNode(x);
    newNode -> next = header -> next;
    header -> next = newNode;
}

void free_list(ListNode*& header)
{
  while(header -> next != NULL){
    ListNode* newNode = new ListNode(header -> next -> val);
    newNode -> next = header -> next -> next;
    header -> next -> next = NULL;
    header -> next = NULL;
    header = newNode;
  }
  cout << header -> val << endl;
}

main()
{
  ListNode* first_header = 0;
  for(int i=0; i<5; i++) {
    ListNode* header = new ListNode(0);
    if(!first_header) {
      first_header = header;
    }
    for(int j=0; j<100000; j++) {
      insert_front(header, j);
    }
    free_list(header);
  }
  ListNode* new_header = new ListNode(0);
  new_header = new ListNode(0);
  new_header = new ListNode(0);
  int dist = abs(new_header - first_header);
  cout << dist << endl;
  if(dist < 100) {
    cout << "ok" << endl;
  } else {
    cout << "not ok" << endl;
  }
}