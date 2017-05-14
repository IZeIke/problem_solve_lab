#include <iostream>
using namespace std;

bool parentest(char *a)
{
  bool paren = true;
  char stack[100];
  char *node = stack;
  *node = *a;
  a++;

  while(*a != '\0') {
    if (*a == '}' || *a == ']' || *a == ')') {
      if (abs(int(*node) - int(*a)) > 2) {
        paren = false;
        break;
      } else {
        node--;
      }
    } else {
      node++;
      *node = *a;
    }
    a++;    
  }
  
  if (*node == '{' || *node == '[' || *node == '(') return false; 
  return paren;
}

int main()
{
  int n;
  cin >> n;
  cin.ignore();

  int ans[20];

  for(int i=0; i<n; i++) {
    char input[100];
    cin.getline(input,100);
    ans[i] = parentest(input);
  }

  for (int i=0; i<n; i++) {
    if (ans[i] == 1) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}