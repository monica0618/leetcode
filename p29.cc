#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  int divide(int dividend, int divisor) {
    long long ans = 0;
    long long a = dividend >= 0 ? dividend : 0 - (long long) dividend;
    long long b = divisor >= 0 ? divisor : 0 - (long long) divisor;
    if (b > a) return 0;
    if (b == 1) ans = a;
    else {
      while (a >= b) {
        a = a - b;
        ans++;
      }
    }
    if (divisor < 0 || dividend < 0) ans = 0 - ans;
    if (divisor < 0 && dividend < 0) ans = 0 - ans;
    if (ans > 2147483647) return 2147483647;
    else return ans;
  }
};

int main () {
  cout << Solution().divide(-17, -3);

  return 0;
}
