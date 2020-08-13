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
  bool canJump(vector<int>& nums) {
    if (nums.size() <= 1) return true;
    int steps = nums[0];
    for(int i = 0; i < nums.size(); i++) {
      steps--;
      if (steps < 0) return false;
      steps = max(steps, nums[i]);
      if(steps == 0 && i != nums.size() - 1) return false;
    }
    return steps >= 0;
  }
};
