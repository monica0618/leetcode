#include "bits/stdc++.h"
#pragma optimize "Ofast"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head -> next == nullptr) return head;
    ListNode* l = head;
    ListNode* r = head;

    while (l -> next && r -> next) {
      r = l -> next;
      if (r -> val == l -> val) {
        l -> next = r -> next;
      }
      else {
        l = l -> next;
      }
    }
    return head;
  }
};
