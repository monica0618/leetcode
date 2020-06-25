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
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int i = 1;
    while(i < nums.size()){
      while(i < nums.size() && nums[i] == nums[i-1]) {
        nums.erase (nums.begin()+i);
      }
      i++;
    }
    return nums.size();
  }
};

int main () {
  vector<int> arr{1,1};
  cout << Solution().removeDuplicates(arr)<< endl;
  for(int a : arr) cout << a;


  return 0;
}
