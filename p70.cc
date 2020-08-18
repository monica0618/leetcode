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
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    vector<int> a(3,0);
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    while (a.size() < n + 1) a.push_back(a[a.size() - 2] + a.back());
    return a.back();
  }
};
