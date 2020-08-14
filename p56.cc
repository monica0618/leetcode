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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return {};
    }
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for (int i = 0 ; i < intervals.size(); i++) {
      int start = intervals[i][0];
      int end = intervals[i][1];
      if (!ans.size() || ans.back()[1] < start) {
        ans.push_back({start,end});
      }
      else {
        ans.back()[1] = max(ans.back()[1], end);
      }
    }
    return ans;
  }
};
