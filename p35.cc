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
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    if (target < nums[0]) return 0;
    else if (target > nums[nums.size() - 1]) return nums.size();
    int l = 0;
    int r = nums.size() - 1;
    int m = -1;
    while (l < r - 1) {
      m = (l + r) / 2;
      if (nums[m] < target) l = m;
      else r = m;
    }
    if (nums[l] == target) return l;
    return r;
  }
};

int main () {
  vector<int> nums{1,2,3,4};
  cout << Solution().searchInsert(nums,7);

  return 0;
}
