#include "bits/stdc++.h"
#pragma optimize "Ofasr"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1,-1};
    int l = 0;
    int r = nums.size() - 1;
    int m = 0;
    int start = -1;
    int end = -1;
    while (l < r - 1) {
      m = (l + r) / 2;
      if ( nums[m] < target) l = m;
      else r = m;
    }
    if (nums[l] == target) start = l;
    else {
      if (nums[r] != target) return {-1, -1};
      start = r;
    }
    l = start;
    r = nums.size() -1;
    while (l < r - 1) {
      m = (l + r) / 2;
      if (nums[m] == target) l = m;
      else r = m;
    }
    if (nums[r] == target) end = r;
    else end = l;
    return {start, end};
  }
};

int main () {
  vector<int> nums{7,7};
  vector<int> ans = Solution().searchRange(nums,7);
  for (int a: ans) cout << a;

  return 0;
}
