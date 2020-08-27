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
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    vector<int> s;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
      while (!s.empty() && heights[s.back()] > heights[i]) {
        int a = s.back();
        s.pop_back();
        int l = s.back() + 1;
        int r = i - 1;
        ans = max(ans, (r - l + 1) * heights[a]);
      }
      s.push_back(i);
    }
    return ans;
  }
};
