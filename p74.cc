#include "bits/stdc++.h"
#pragma optimize "Ofast"

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    int l = 0;
    int r = m * n - 1;
    int pi, pe;
    while (l <= r) {
      pi = (l + r) / 2;
      pe = matrix[pi / n][pi % n];
      if (target == pe) return true;
      else {
        if (target < pe) r = pi - 1;
        else l = pi + 1;
      }
    }
    return false;
  }
};
