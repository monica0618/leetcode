#include "bits/stdc++.h"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio();
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.size() == 0) return s.size() == 0;

    bool first_match = (s.size() != 0 && (s[0] == p[0] || p[0] == '.'));

    if(p.size() >= 2 && p[1] == '*') return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    else return first_match && isMatch(s.substr(1), p.substr(1));
 
  }
};

int main () {
  string s = "ab";
  string p = ".*c";
  cout << Solution().isMatch(s,p);
  return 0;
}
