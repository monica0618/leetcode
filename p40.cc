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
  void findcomb(vector<vector<int>>& ans, vector<int>& candinum, vector<int>& candi, vector<int>& multi, int target, int k){
    if (k == candi.size()) return;
    int remain = target;
    for (int i = 0; i < k; i++) remain = remain - candi[i] * multi[i];
    if (remain < 0) return;
    if (remain != 0 && remain % candi[k] == 0) {
      if(remain /candi[k] <= candinum[k]){
        multi[k] = remain / candi[k];
        ans.push_back(multi);
      }
      multi[k] = 0;
    }
    for (int i = 0; i <= candinum[k]; i++) {
      multi[k] = i;
      findcomb(ans,candinum, candi, multi, target, k + 1);
    }
    multi[k] = 0;
    return;
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    int key = candidates.size();
    for (int i = 0; i < candidates.size(); i++) {
      if(candidates[i] > target) key = i;
    }
    if (key == 0) return {};
    else if (key == 1 && candidates[0] == target) return {{target}};
    else if (key == 1) return {};
    vector<int> revcandi;
    vector<int> candinum;
    int temp = candidates[key - 1];
    int count = 1;
    for (int i = key - 2; i >= 0; i--) {
      if (i == 0){
        if (candidates[0] == temp){
          revcandi.push_back(temp);
          candinum.push_back(count + 1);
        }
        else {
          candinum.push_back(count);
          revcandi.push_back(temp);
          candinum.push_back(1);
          revcandi.push_back(candidates[0]);
        }
      }
      else if (candidates[i] != temp) {
        candinum.push_back(count);
        count = 1;
        revcandi.push_back(temp);
        temp = candidates[i];
      }
      else count++;
    }

    vector<int> multi(revcandi.size(), 0);
    findcomb(ans, candinum, revcandi, multi, target, 0);
    for (int i = 0; i < ans.size(); i++){
      vector<int> com;
      for (int j = 0; j < revcandi.size(); j++) {
        for (int k = 1; k <= ans[i][j]; k++) com.push_back(revcandi[j]);
      }
      result.push_back(com);
    }
    return result;
  }
};

int main () {
  vector<int> candi{14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};

  vector<vector<int>> ans = Solution().combinationSum2(candi, 27);
  for(auto aa:ans){
    for(auto a:aa) cout <<a<<' ';
    cout<< endl;
  }

  return 0;
}
