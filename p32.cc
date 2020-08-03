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
  int longestValidParentheses(string s) {
    int ans = 0;
    if (s.length() == 0) return ans;
    string invs;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '(') invs.push_back(')');
      else invs.push_back('(');
    }
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == '(') {
        int j = i + 1;
        int sum = 1;
        while (j < s.length() && sum >= 0) {
          if(s[j] == '(') sum++;
          else sum--;
          j++;
          if (sum == 0) ans = max(ans, j - i);
        }
        if (sum <= 0) ans = max(ans, j - i - 1);
      }
    }
    return ans;
  }
};

int main () {
  cout << Solution().longestValidParentheses(")()())");
  return 0;
}
