#include "bits/stdc++.h"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    long long ans = 0;
    int xt = x;
    while(xt >= 1){
      int d = xt % 10;
      ans = (ans + d) * 10;
      xt /= 10;
    }
    ans /= 10;
    if(ans == x) return true;
    return false;
  }
};

int main () {
  cout << Solution().isPalindrome(0);
  return 0;
}
