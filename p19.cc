#include "bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int cnt = 0;
    ListNode *i = head;
    while(i){
      cnt++;
      i = i->next;
    }
    cnt -= n+1;
    i = head;
    if(cnt < 0)
      return head->next;
    while(i->next && cnt > 0){
      cnt--;
      i = i->next;
    }
    i->next = i->next->next;
    return head;
  }
};
 
void print_list (ListNode *head) {
  while (head) {
    cout << head -> val << " ";
    head = head -> next;
  }
  cout << endl;
}


int main () {
  
  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  ListNode *a =  (ListNode *)malloc(sizeof(ListNode));
  ListNode *b =  (ListNode *)malloc(sizeof(ListNode));
  ListNode *c =  (ListNode *)malloc(sizeof(ListNode));
  ListNode *d = (ListNode *) malloc(sizeof(ListNode));

  head->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = nullptr;
  head->val = 1;
  a->val= 2;
  b->val = 3;
  c->val = 4;
  d->val = 5;
  ListNode *ans = Solution().removeNthFromEnd(head, 2);
  print_list(head);
 

  free(head);
  free(a);
  free(b);
  free(c);
  free(d);

  //Homework *h_ptr = (Homework *)malloc(sizeof(Homework));
  //Homework *h_ptr = new Homework(4);
  //h_ptr -> number_of_homework = 1;
  //h_ptr -> homeworks.push_back("English");
  return 0;
}
