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
  string simplifyPath(string path) {
    string ans;
    vector<string> names;
    string thisName;
    for (int i = 0; i <= path.size(); i++) {
      if (i == path.size() || path[i] == '/') {
        if (thisName == ".") thisName.clear();
        else if (thisName == "..") {
          if(!names.empty()) names.pop_back();
        }
        else if(!thisName.empty()) names.push_back(thisName);
        thisName.clear();
      }
      else thisName.push_back(path[i]);
    }
    ans.push_back('/');
    while (!names.empty()) {
      ans += names.front();
      ans.push_back('/');
      names.erase(names.begin());
    }
    if (ans.size() > 1) ans.pop_back();
    return ans;
  }
};
