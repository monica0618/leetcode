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
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    if (m * n == 0) return max(m, n);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m + 1; i++){
      for (int j = 0; j < n + 1; j++) {
        if(i == 0) dp[i][j] = j;
        else if (j == 0) dp[i][j] = i;
        else {
          if (word1[i-1] != word2[j-1]) dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
          else dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1]));
        }
      }
    }

    return dp[m][n];
  }
};
