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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.size() == 0) return ans;
    int left, up = 0;
    int right = matrix[0].size() - 1;
    int down = matrix.size() - 1;
    while (left <= right && up <= down) {
      for (int c = left; c <= right; c++) {
        ans.push_back(matrix[up][c]);
      }
      up++;
      for (int r = up; r <= down; r++) {
        ans.push_back(matrix[r][right]);
      }
      right--;
      if (left > right || up > down) break;
      for (int c = right; c >= left; c--) {
        ans.push_back(matrix[down][c]);
      }
      down--;
      for (int r = down; r >= up; r--) {
        ans.push_back(matrix[r][left]);
      }
      left++;
    }
    return ans;
  }
};
