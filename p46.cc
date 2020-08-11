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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() == 1) return {{nums[0]}};
    int current = nums[nums.size() - 1];
    nums.pop_back();
    vector<vector<int>> lans = permute(nums);
    for (int i = 0; i < lans.size(); i++) {
      for (int j = 0; j <= lans[i].size(); j++){
        vector<int> temp = lans[i];
        temp.insert(temp.begin() + j,current);
        ans.push_back(temp);
      }
    }
    return ans;
  }
};

int main () {
  vector<int> arr = {1,2,3};
  vector<vector<int>> ans = Solution().permute(arr);

  return 0;
}
