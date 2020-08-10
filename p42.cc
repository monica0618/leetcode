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
  int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    vector<bool> skip(height.size(), false);
    int count = 0;
    for (int i = 1; i < height.size() - 1; i++) {
      if (skip[i]) continue;
      int base = height[i];
      int l = i;
      int r = i;
      while ( l > 0 && height[l-1] <= base) l--;
      while ( r < height.size() - 1 && height[r+1] <= base) {
          if (height[r+1] == base) skip[r+1] = true;
          r++;
      }

      if (l == 0 || r == height.size()-1) continue;
      l--;
      r++;
      count += (min(height[l], height[r]) - base) * (r - l - 1);
    }
    return count;
  }
};

int main () {
  vector<int> hs{3,0,4};
  cout << Solution().trap(hs);

  return 0;
}
