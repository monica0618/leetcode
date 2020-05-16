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
  string longestCommonPrefix(vector<string>& strs) {
    int i,j;
    string pref;
    pref.clear();
    bool end = false;
    if(strs.size() == 0) return pref;
    for(i = 0; i < strs[0].size() && !end; i++){
      char key = strs[0][i];
      for(j = 0; j < strs.size() && !end; j++){
        if(strs[j][i] != key || i == strs[j].size() ) end = true;
      }
      if(!end) pref.push_back(key);
    }
    return pref;
  }
};

int main () {
  vector<string> strs{};
  cout << Solution().longestCommonPrefix(strs);
  return 0;
}
