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
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i <= n; i++) {
      if (nums[i-1] <= 0) nums[i-1] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
      int num = abs(nums[i-1]);
      if (num < n + 1) nums[num-1] = -abs(nums[num-1]);
    }
    for (int i = 1;  i <= n; i++) {
      if (nums[i-1] > 0) return i;
    }
    return n + 1;
  }
};

int main () {

  return 0;
}
