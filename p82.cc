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
    ListNode* start = new ListNode(-1);
    start -> next = head;
    ListNode* l = start;
    ListNode* r = head;
    int temp = r -> val;
    bool dup = false;

    while (l -> next && r -> next) {
      r = r -> next;
      if (r -> val != temp && !dup) {
        l = l -> next;
        temp = r -> val;
      }
      else if (r -> val != temp && dup) {
        l -> next = r;
        temp = r -> val;
        dup = false;
      }
      else if (r -> val == temp && r -> next == nullptr) {
        l -> next = nullptr;
      }
      else {
        dup = true;
      }
    }

    return start -> next;
  }
};
