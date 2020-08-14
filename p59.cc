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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int left = 0;
    int up = 0;
    int right = n - 1;
    int down = n - 1;
    int val = 1;
    while (left <= right && up <= down) {
      for (int c = left; c <= right; c++) {
        ans[up][c] = val;
        val++;
      }
      up++;
      for (int r = up; r <= down; r++) {
        ans[r][right] = val;
        val++;
      }
      right--;
      if (left > right || up > down) break;
      for (int c = right; c >= lef
               t; c--) {
        ans[down][c] = val;
        val++;
      }
      down--;
      for (int r = down; r >= up; r--) {
        ans[r][left] = val;
        val++;
      }
      left++;
    }
    return ans;
  }
};
