#include "bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();


class Solution {
public: 

  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int k = 0; k < nums.size(); k++) {
      if(k == 0 || (k != 0 && nums[k] != nums[k-1])){
        int targ = target - nums[k];
        for(int i = k + 1; i < nums.size(); i++) {
          if(i == k+1 || (i != k+1 && nums[i] != nums[i-1])){
            int key =  nums[i];
            int l = i+1; int r = i == nums.size() - 1? nums.size() - 2:nums.size() - 1;
            int temp1;
            int temp2;
            int temp3;
            while(l < r) {
              if(l == i) l++;
              else if(r == i) r--;
              else{
                if(nums[l]+ nums[r] + key < targ) l++;
                else if(nums[l] + nums[r] + key > targ) r--;
                else if (nums[l] + nums[r] + key == targ) {
                  if(key!= temp3 || nums[l] != temp2 || nums[r] != temp1){
                    ans.push_back({target-targ ,key, nums[l], nums[r]});
                    temp3 = key;
                    temp2 = nums[l];
                    temp1 = nums[r];
                  }
                  l++;
                  r--;
                }
              }
            }
          }
        }
      }
    }
    return ans;
  }

};

int main () {
  vector<int> arr{0,0,0,0};
  vector<vector<int>> ans = Solution().fourSum(arr,0);
  for(int i = 0; i < ans.size(); i++) {
    for(int a: ans[i]) cout << a <<" ";
    cout << endl;
  }
  return 0;
}
