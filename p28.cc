#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) return -1;
    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
      int j = i;
      int k = 0;
      bool same = true;
      while (k < needle.size() && same) {
        if (needle[k] == haystack[j]) {
          k++;
          j++;
        }
        else same = false;
      }
      if (k == needle.size()) return i;
    }
    return -1;
  }
};

int main () {
  string h = "aaaaa";
  string n = "bba";
  cout <<  Solution().strStr(h,n);

  return 0;
}
