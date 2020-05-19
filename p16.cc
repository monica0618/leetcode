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
  int threeSumClosest(vector<int>& nums, int target)  {
    sort(nums.begin(), nums.end());
    int ans;
    int dis = 100000;
    for(int i = 0; i < nums.size()-2; i++) {
      if(i == 0 || (i != 0 && nums[i] != nums[i-1])){
        int key =  nums[i];
        int l = i+1; int r = i == nums.size() - 1? nums.size() - 2:nums.size() - 1;
        int sum = 0;
        while(l < r) {
          if(l == i) l++;
          else if(r == i) r--;
          else{
            sum = nums[l]+nums[r]+key;
            if(sum < target){
              l++;
              if(abs(sum-target) < dis){
                ans = sum;
                dis = abs(sum-target);
              }
            }
              else if (sum > target){
                r--;
                if(abs(sum-target) < dis){
                  ans = sum;
                  dis = abs(sum-target);
                }
              }
            else if (sum == target) {
              return target;
            }
          }
        }
      }
    }
    return ans;
  }
};

int main () {
  vector<int> arr{-1,2,1,-4};
  cout << Solution().threeSumClosest(arr,12);
  return 0;
}
