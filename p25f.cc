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
private:
  ListNode* rotate(ListNode* s, int k, ListNode** pl) {
    ListNode* l = s;
    ListNode* r = s->next;
    ListNode* temp = l;
    for (int i = 0; i < k-1; i++) {
      l -> next = r -> next;
      r -> next = temp;
      temp = r;
      r = l->next;
    }
    if (*pl) (*pl) -> next = temp;
    *pl = l;
    return temp;
  }

public:
  bool longEnough(ListNode* a, int n){
    ListNode* temp = a;
    for(int i = 0; i < n; i++){
      if(!temp) return false;
      temp = temp->next;
    }
    return true;
  }


  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) return nullptr;
    if(k == 1) return head;
    ListNode* s = head;
    ListNode* new_head = nullptr;
    ListNode* pl = nullptr;
    int c = 1;
    bool rotate_once = false;
    while(longEnough(s,k)){
      if(!rotate_once) new_head = rotate(s,k,&pl); else rotate(s, k, &pl);
      rotate_once = true;
      s = pl->next;
    }
    return rotate_once? new_head : head;
  }

};

int main () {
  ListNode* a = new ListNode(2);
  ListNode* b = new ListNode(1,a);
  ListNode* c = new ListNode(1,b);
  ListNode* a1 = new ListNode(4,c);
  ListNode* b1 = new ListNode(3,a1);
  ListNode* c1 = new ListNode(6,b1);
  ListNode* d1 = new ListNode(5,c1);
  ListNode* ans = Solution().reverseKGroup(b,2);
  while(ans) {
    cout << ans->val <<" ";
    ans = ans->next;
  }
  return 0;
}
