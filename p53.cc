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
  int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if(sum <= 0) sum = nums[i];
      else sum = sum + nums[i];
      maxSum = max(sum,maxSum);
    }
    return maxSum;
  }
};
