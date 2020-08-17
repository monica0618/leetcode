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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    int count = 1;
    ListNode* start;
    ListNode* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
      count++;
    }
    int n = count - k % count;
    if (n == 0) return head;
    else {
      temp->next = head;
      while (n > 0) {
        temp = temp->next;
        n--;
      }
      start= temp->next;
      temp->next = nullptr;
    }
    return start;
  }
};
