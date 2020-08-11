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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,int> dict;
    int groupnum = 0;
    for(string str:strs) {
      string temp = str;
      sort(temp.begin(),temp.end());
      if (dict.find(temp) == dict.end()) {
        dict.insert({temp,groupnum});
        vector<string> thisgroup(1, str);
        ans.push_back(thisgroup);
        groupnum++;
      }
      else {
        ans[dict.at(temp)].push_back(str);
      }
    }
    return ans;
  }
};
