#include "bits/stdc++.h"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();


 // * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // int s = 0;
    // int c = 0;
    // int a,b;
    ListNode* it1 = l1;
    ListNode* it2 = l2;
    ListNode* head = new ListNode(-1);
    ListNode* it3 = head;
    bool c = false;
    while(it1 || it2){
      it3 -> next = new ListNode((it1? it1 -> val : 0)+(it2? it2 -> val : 0) + (c? 1:0));
      it3 = it3 -> next;
      if(it2) it2 = it2 -> next;
      if(it1) it1 = it1 -> next;
      c = false;

      if(it3 -> val >= 10) {
        it3 -> val -= 10;
        c = true;
      }



      // if(it1) a = it1 -> val;
    //   else a = 0;
    //   if(it2) b = it2 -> val;
    //   else b = 0;
    //   if(a + b + c < 10) {
    //     s = a + b + c;
    //     it3 -> next = new ListNode(s);
    //     it3 = it3 -> next;
    //     c = 0;
    //   }
    //   else {
    //     s = a + b + c - 10;
    //     it3 -> next = new ListNode(s);
    //     it3 = it3 -> next;
    //     c = 1;
    //   }
    //   s = 0;
    //   if(it1 -> next) it1 = it1 -> next;
    //   if(it2 -> next) it2 = it2 -> next;
    }
    if(c) {
      it3 -> next = new ListNode(1);
      it3 = it3 -> next;
      }
    return head -> next;
  }
};

int main () {
  ListNode* a1 = new ListNode(2);
  ListNode* a2 = new ListNode(4);
  ListNode* a3 = new ListNode(3);
  a1 -> next = a2;
  a2 -> next = a3;
  ListNode* b1 = new ListNode(5);
  ListNode* b2 = new ListNode(6);
  ListNode* b3 = new ListNode(4);
  b1 -> next = b2;
  b2 -> next = b3;

  ListNode* ans = Solution().addTwoNumbers(a1,a2);
  ListNode* it = ans;
  while(it) {
    cout << it -> val;
    it = it -> next;
  }
  return 0;
}
