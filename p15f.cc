#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
      if(i == 0 || (i != 0 && nums[i] != nums[i-1])){
        int key =  nums[i];
        int l = i+1; int r = i == nums.size() - 1? nums.size() - 2:nums.size() - 1;
        int temp1;
        int temp2;
        while(l < r) {
          if(l == i) l++;
          else if(r == i) r--;
          else{
            if(nums[l]+ nums[r] + key < 0) l++;
            else if(nums[l] + nums[r] + key > 0) r--;
            else if (nums[l] + nums[r] + key == 0) {
              if(nums[l] != temp2 || key != temp1){
                ans.push_back({key, nums[l], nums[r]});
                temp2 = nums[l];
                temp1 = key;
              }
              l++;
              r--;
            }
          }
        }
      }
    }
    return ans;
  }
};

int main () {
  vector<int> arr{0,0,0};
  vector<vector<int>> ans = Solution().threeSum(arr);
  for(int i = 0; i < ans.size(); i++) {
    for(int a: ans[i]) cout << a <<" ";
    cout << endl;
  }
  return 0;
}
