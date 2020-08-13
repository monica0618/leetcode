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
  double calcPow(double x, long long n) {
    if (n == 0) return 1.0;
    double ans = calcPow(x, n/2);
    return  n % 2 == 1? ans * ans * x : ans * ans;
  }
  double myPow(double x, int n) {
    long long N = n;
    return n > 0? calcPow(x, N) : 1.0 / calcPow(x, -N);
  }
};

int main () {
  cout << Solution().myPow(2.000,-2);
  return 0;
}
