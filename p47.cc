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

  vector<vector<int>> permuteUnique1(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() == 1) return {{nums[0]}};
    int current = nums[nums.size() - 1];
    nums.pop_back();
    bool repeat = current == nums[nums.size() - 1];
    vector<vector<int>> lans = permuteUnique1(nums);
    for (int i = 0; i < lans.size(); i++) {
      int key = 0;
      if (repeat) {
        for (int k = 0; k < lans[i].size(); k++) {
          if (lans[i][k] == current) key = k + 1;
        }
      }
      for (int j = key; j <= lans[i].size(); j++){
        vector<int> temp = lans[i];
        temp.insert(temp.begin() + j,current);
        ans.push_back(temp);
      }
    }
    return ans;
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return permuteUnique1(nums);
  }
};

int main () {
  vector<int> arr = {2,2,1,1};
  vector<vector<int>> ans = Solution().permuteUnique(arr);
  for(auto aa: ans) {
    for(int a: aa) cout << a<<" ";
    cout <<endl;
  }

  return 0;
}
