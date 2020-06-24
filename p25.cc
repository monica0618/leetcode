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


bool longEnough(ListNode* a, int n){
  ListNode* temp = a;
  for(int i = 0; i < n-1; i++){
    if(temp->next == nullptr) return false;
    temp = temp->next;
  }
  return true;
}

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) return nullptr;
    ListNode* s = head;
    ListNode* l = s;
    ListNode* r = s->next;
    ListNode* pl = nullptr;
    if(longEnough(head, k)) for(int i = 0; i < k-1; i++) head = head -> next;
    while(longEnough(s,k)){
      l = s;
      r = s -> next;
      ListNode* temp = l;
      for (int i = 0; i < k-1; i++) {
        l -> next = r -> next;
        r -> next = temp;
        temp = r;
        r = l->next;
      }
      if (pl) pl -> next = temp;
      pl = l;
      s = l -> next;
    }
    return head;
  }

};

int main () {
  ListNode* a = new ListNode(4);
  ListNode* b = new ListNode(2,a);
  ListNode* c = new ListNode(1,b);
  ListNode* a1 = new ListNode(4,c);
  ListNode* b1 = new ListNode(3,a1);
  ListNode* c1 = new ListNode(6,b1);
  ListNode* d1 = new ListNode(5,c1);
  cout << longEnough(c,4) << endl;
  ListNode* ans = Solution().reverseKGroup(d1,3);
  while(ans) {
    cout << ans->val <<" ";
    ans = ans->next;
  }

  return 0;
}
