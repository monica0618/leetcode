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
  int mySqrt(int x) {
    if (x == 0) return 0;
    if (x < 4) return 1;
    int l = 2;
    int r = x/2;
    long long mid = -1;
    while(l < r - 1) {
      mid = (l + r) / 2;
      if (mid * mid > x) r = mid;
      else if (mid * mid <= x) l = mid;
    }
    return l;
  }
};
