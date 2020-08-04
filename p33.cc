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
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1 && nums[0] != target) return -1;
    else if (nums.size() == 1 && nums[0] == target) return 0;
    int l = 0;
    int r = nums.size() - 1;
    int m = 0;
    if (nums[l] > nums[r]) {
      if (nums[l] > target && nums[r] < target) return -1;
      bool passm = false;
      while (l < r - 1) {
        m = (l + r) / 2;
        if(nums[m] > nums[r]) l = m;
        else if (nums[m] < nums[r]) r = m;
      }
      if (target <= nums[nums.size() - 1]) {
        l = r;
        r = nums.size() - 1;
      }
      else if (target >= nums[0]) {
        r--;
        l = 0;
      }
      if (nums[l] == target) return l;
      else if (nums[r] == target) return r;
    }
    while (l < r - 1) {
      m = (l + r) / 2;
      if(target > nums[m]) l = m;
      else if (target < nums[m]) r = m;
      else if (target == nums[m]) return m;
    }
    if (nums[l] == target) return l;
    else if (nums[r] == target) return r;
    return -1;
  }
};

int main () {
  vector<int> arr{1,3};
  int ans =  Solution().search(arr,1);
  cout << ans;
  return 0;
}
