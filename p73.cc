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
  void setZeroes(vector<vector<int>>& matrix) {
    bool flz = false;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      if(matrix[i][0] == 0) flz = true;
      for (int j = 1; j < n; j++) {
        if(matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
      }
    }

    if (matrix[0][0] == 0) {
      for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }

    if (flz) {
      for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
  }

};
