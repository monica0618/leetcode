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
  int reverse(int x) {
    vector<int> input;
    input.reserve(11);
    while(x >= 1 || x <= -1){
      int a = x % 10;
      input.push_back(a);
      x = x/10;
    }
    long long ans = 0;
    for(int p: input){
      ans = (ans + p) * 10;
    }
    ans = ans /10;
    if(ans <= 2147483647 && ans >= -2147483648) return ans;
    else return 0;
  }
};

int main () {
  cout << Solution().reverse(1534236469);
  return 0;
}
