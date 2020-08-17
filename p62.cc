#include "bits/stdc++.h"
#pragma optimize "Ofast"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

static int a[101][101] = {0};
class Solution {
public:
  int uniquePaths(int m, int n) {
    if(m <= 0 || n <= 0) return 0;
    else if (m == 1 || n == 1) return 1;
    else if (m == 2 || n == 2) return max(m, n);
    if(a[m][n] > 0) return a[m][n];
    a[m-1][n] =  uniquePaths(m-1,n);
    a[m][n-1] =  uniquePaths(m,n-1);
    a[m][n] = a[m-1][n]+a[m][n-1];
    return a[m][n];
  }
};
