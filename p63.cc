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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid[0].size();
    int n = obstacleGrid.size();
    vector<vector<int>> a(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (obstacleGrid[i][j] == 1) a[i][j] = 0;
        else if (i == 0 && j == 0) a[i][j] = 1;
        else if (i == 0) a[i][j] = a[i][j-1];
        else if (j == 0) a[i][j] = a[i-1][j];
        else  a[i][j] = a[i-1][j] + a[i][j-1];
      }
    }
    return a[n-1][m-1];
  }
};

int main () {
  vector<vector<int>> grid = {{1,0,0}};
  int a = Solution().uniquePathsWithObstacles(grid);
  cout << a;
  return 0;
}
