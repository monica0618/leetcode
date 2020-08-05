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
  int findcomb(vector<vector<int>>& ans, vector<int>& candi, vector<int>& multi, int target, int k){
    if (k == candi.size()) return 0;
    int remain = target;
    for (int i = 0; i < k; i++) remain = remain - candi[i] * multi[i];
    if (remain != 0 && remain % candi[k] == 0) {
      multi[k] = remain / candi[k];
      ans.push_back(multi);
      multi[k] = 0;
    }
    for (int i = 0; i <= remain / candi[k]; i++) {
      multi[k] = i;
      findcomb(ans,candi,multi,target,k + 1);
    }
    multi[k] = 0;
    return 0;
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    vector<int> revcandi;
    for (int i = candidates.size() - 1; i >= 0; i--) revcandi.push_back(candidates[i]);
    vector<int> multi(candidates.size(), 0);
    int a = findcomb(ans, revcandi, multi, target, 0);
    for (int i = 0; i < ans.size(); i++){
      vector<int> com;
      for (int j = 0; j < candidates.size(); j++) {
        for (int k = 1; k <= ans[i][j]; k++) com.push_back(revcandi[j]);
      }
      result.push_back(com);
    }
    return result;
  }
};
