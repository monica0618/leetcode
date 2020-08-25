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
  string minWindow(string s, string t) {
    unordered_map<char, int> need, have;
    for(char c : t) need[c]++;

    int l = 0, r = 0;
    int cnt = 0;
    int len = s.size() + 1;
    int start = 0;
    while (r < s.size()) {
      char c = s[r];
      if (need.count(c)) {
        have[c]++;
        if (have[c] == need[c])
          cnt++;
      }
      r++;
      while (cnt == need.size()) {
        if (r - l < len) {
          start = l;
          len = r - l;
        }
        char ch = s[l];
        l++;
        if (need.count(ch)) {
          if (have[ch] == need[ch]) cnt--;
          have[ch]--;
        }
      }
    }
    return len == s.size() + 1 ? "" : s.substr(start,len);
  }
};
