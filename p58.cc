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
  int lengthOfLastWord(string s) {
    if (s.size() == 0) return 0;
    int i = s.size() - 1;
    int count = 0;
    while (i >= 0 && s[i] == ' ') i--;
    if (i >= 0) {
      while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
      }
    }
    return count;
  }
};
