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
  void dfs(int start, int n, int k, vector<int>& arr, vector<vector<int>>& ans) {
    int last = n - (k - arr.size()) + 1;
    for (int i = start; i <= last; i++) {
      arr.push_back(i);
      if (arr.size() == k) ans.push_back(arr);
      else dfs(i + 1, n, k, arr, ans);
      arr.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> arr;
    dfs(1, n, k, arr, ans);
    return ans;
  }
};
