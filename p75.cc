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
  void sortColors(vector<int>& nums) {
    int z = 0;
    int t = nums.size() - 1;
    int c = 0;

    while(c <= t) {
      if (nums[c] == 0) {
        swap(nums[c], nums[z]);
        c++;
        z++;
      }
      else if (nums[c] == 2) {
        swap(nums[c], nums[t]);
        t--;
      }
      else c++;
    }
  }
};

