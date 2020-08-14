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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0) {
      return {newInterval};
    }
    int L = newInterval[0];
    int R = newInterval[1];
    vector<vector<int>> ans;
    bool found = false;x
    int key = intervals.size();
    for (int i = 0; i < intervals.size() && !found; i++) {
      if (intervals[i][0] > L) {
        intervals.insert(intervals.begin() + i, newInterval);
        key = i;
        found = true;
      }
    }
    if (!found) intervals.push_back(newInterval);
    for (int i = 0 ; i < intervals.size() ; i++) {
      if (i < key) ans.push_back(intervals[i]);
      else {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.size() || ans.back()[1] < start) {
          ans.push_back({start,end});
        }
        else {
          ans.back()[1] = max(ans.back()[1], end);
        }
      }
    }
    return ans;
  }
};
