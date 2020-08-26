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
    bool search(vector<int>& nums, int target) {
      if (nums.size() == 0) return false;
      if (nums.size() == 1) return nums[0] == target? true:false;
      if (target > nums.back() && target < nums.front()) return false;

      int l = 0, r = nums.size() - 1;
      int mid = (l + r)/2;
      if (nums[mid] == nums.front()){
        for (int a:nums) {
          if (a == target) return true;
        }
        return false;
      }
      if (nums.back() <= nums.front()) {
        while (r > l + 1) {
          mid = (l + r) / 2;
          if (nums[mid] >= nums.front()) l = mid;
          else if (nums[mid] < nums.back()) r = mid;
        }

        int pivot = nums[l] > nums[r] ? r : l;

        if (target <= nums.back()) {
          l = pivot;
          r = nums.size() - 1;
        }
        else if (target >= nums.front()) {
          l = 0;
          r = pivot - 1 >= 0 ? pivot - 1: 0;
        }
      }

      if (nums[l] == target || nums[r] == target) return true;

      while (r > l + 1) {
        mid = (l + r) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid;
      }

      if (nums[l] == target || nums[r] == target) return true;

      return false;

  }
};
