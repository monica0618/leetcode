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
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int temp = nums[0];
    while (cnt < 3 && i < nums.size()) {
      if (nums[i] == temp) cnt++;
      else {
        temp = nums[i];
        cnt = 1;
      }
      i++;
    }
    if (i == nums.size()) return cnt == 3? nums.size()-1:nums.size();
    i--;
    j = i;
    while ( j < nums.size() && nums[j] == temp) j++;
    if (j == nums.size()) return i;
    cnt = 0;
    temp = nums[j];
    while (j < nums.size()) {
      if (nums[j] == temp) cnt++;
      else {
        temp = nums[j];
        cnt = 1;
      }
      if (cnt < 3) {
        swap(nums[i], nums[j]);
        i++;
      }
      j++;
    }
    return i;
  }
};
