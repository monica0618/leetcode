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
  int jump(vector<int>& nums) {
    int count = 0;
    int start = 0;
    int end = 1;
    while (end < nums.size())
      {
        int maxp = 0;
        for (int i = start; i < end; i++)
            maxp = max(maxp, i + nums[i]);
        start = end;
        end = maxp + 1;
        count++;
      }
    return count;
  }
};

int main () {
  vector<int> arr = {2,3,1,1,4};
  cout << Solution().jump(arr);
  return 0;
}
