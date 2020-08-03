#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int key = 0;
    int i = nums.size() - 1;
    while (i > 0 && nums[i-1] >= nums[i]) {
      i--;
    }
    int j = i+1;
    bool swaped = false;
    while (j != 1 && j <= nums.size() && !swaped){
      if ( j == nums.size() || nums[j] <= nums[i-1]) {
        swap(nums[i-1], nums[j-1]);
        key = i;
        swaped = true;
      }
      else j++;
    }
    int l = key;
    int r = nums.size() - 1;
    while (l < r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
  }
};

int main () {
  vector<int> ans{1,5,1};
  Solution().nextPermutation(ans);
  for(int a: ans) cout << a << " ";

  return 0;
}




