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
  vector<vector<int>> ans;
  void dfs(vector<int>& source, vector<int>& subset, int start) {
    if (source.empty()) return;
    for (int i = start; i < source.size(); i++) {
      subset.push_back(source[i]);
      ans.push_back(subset);
      dfs(source, subset, i + 1);
      subset.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    ans.push_back({});
    if (nums.size() == 0) return ans;
    vector<int> subset;
    dfs(nums, subset, 0);
    return ans;
  }
};
