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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;
    vector<int> allnum;
    for(ListNode* l: lists){
      ListNode* temp = l;
      while(temp){
        allnum.push_back(temp->val);
        temp = temp->next;
      }
    }
    if(allnum.size() == 0) return nullptr;
    sort(allnum.begin(),allnum.end());
    ListNode* end = new ListNode(allnum.back(),nullptr);
    for(int i = allnum.size()-2; i >= 0; i--){
      ListNode* current = new ListNode(allnum[i],end);
      end = current;
    }
    return end;
  }
};

int main () {
  vector<


  return 0;
}
