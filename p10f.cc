#include "bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> memo(s.size()+1, vector<bool> (p.size()+1,1));
    return dp(0,0,s,p,memo);
  }

  bool dp(int i, int j, string s, string p, vector<vector<bool>> m) {
    bool ans;
    if(j == p.size()) {
      ans = i == s.size();
    }
    else{
      bool first_match = (i < s.length() && (p[j] ==s[i] || p[j] == '.'));

      if(j + 1 < p.size() && p[j+1] == '*') ans = (dp(i, j+2, s, p,m)) || (first_match && dp(i+1, j, s, p, m));
      else ans = first_match && dp(i+1, j+1, s, p,m);
    }
    if (m[i][j] == ans) ans = true;
    else ans = false;
    return ans;
  }
};


int main () {
  string s = "aaaaaaaaaaaaab";
  string p =  "a*a*a*a*a*a*a*a*a*a*c";
  cout << Solution().isMatch(s,p);
  return 0;
}
