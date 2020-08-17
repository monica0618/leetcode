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
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) grid[i][j] = grid[i][j];
        else if (i == 0) grid[i][j] = grid[i][j-1] + grid[i][j];
        else if (j == 0) grid[i][j] = grid[i-1][j] + grid[i][j];
        else  grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
      }
    }
    return grid[n-1][m-1];
  }
};

