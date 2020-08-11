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
  void rotate(vector<vector<int>>& matrix) {
    int msize = matrix[0].size();
    for (int m = 0; m <= msize / 2 - 1; m++) {
      int n = msize - m - 1;
      for (int k = m; k < n; k++) {
        int temp = matrix[k][n];
        matrix[k][n] = matrix[m][k];
        matrix[m][k] = matrix[n-k+m][m];
        matrix[n-k+m][m] = matrix[n][n-k+m];
        matrix [n][n-k+m] = temp;
      }
    }
  }
};

int main () {
  vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
  Solution().rotate(input);

  return 0;
}
