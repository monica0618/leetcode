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
  ListNode* swapPairs(ListNode* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return head;
    ListNode* i = head;
    ListNode* j = head->next;
    head = head->next;
    while(j->next && i->next){
      i->next = j->next;
      j->next = i;
      i = i->next;
      j = j->next;
      if(i->next){
        j->next = i->next;
        j = j->next;
      }
    }
    j->next = i;
    i->next = nullptr;
    return head;
  }
};

int main () {
  ListNode* a = new ListNode(4);
  ListNode* b = new ListNode(2,a);
  ListNode* c = new ListNode(1,b);
  ListNode* a1 = new ListNode(4,c);
  ListNode* b1 = new ListNode(3,a1);
  ListNode* c1 = new ListNode(1,b1);
  ListNode* d1 = new ListNode(5,c1);
  ListNode* ans = Solution().swapPairs(d1);
  while(ans) {
    cout << ans->val <<" ";
    ans = ans->next;
  }
  return 0;
}

