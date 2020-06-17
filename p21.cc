#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode* start = new ListNode();
    ListNode* a = start;
    while(l1 && l2){
      cout << l1->val << l2->val <<" ";
      if(l1->val <= l2->val) {
        cout <<"l1";
        a->next = l1;
        l1 = l1->next;
      }
      else {
        cout << "l2";
        a->next = l2;
        l2 = l2->next;
      }
      a = a->next;
    }
    a->next = l1? l1:l2;
    return start->next;
  }
};

int main () {
  ListNode* a = new ListNode(4);
  ListNode* b = new ListNode(2,a);
  ListNode* c = new ListNode(1,b);
  ListNode* a1 = new ListNode(4);
  ListNode* b1 = new ListNode(3,a1);
  ListNode* c1 = new ListNode(1,b1);
  ListNode* ans = Solution().mergeTwoLists(c,c1);
  while(ans) {
    cout << ans->val <<" ";
    ans = ans->next;
  }
  return 0;
}
