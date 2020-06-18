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
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> table(1, vector<string>(1, ""));
    table.reserve(n + 1);
    for(int i = 1; i <=  n; i++) {
      vector<string> temp;
      for(int j = 0; j < i; j++) {
        int k = i - 1 - j;
        for(string& s1 : table[j])
          for(string& s2 : table[k]) temp.push_back("(" + s1 + ")" +s2);
      }
      table.push_back(temp);
    }
    return table.back();
  }

};


int main () {
  vector<string> ans = Solution().generateParenthesis(2);
  for(string s:ans) cout << s <<" ";

  return 0;
}
