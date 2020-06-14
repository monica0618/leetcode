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
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> dict;
    int count = 0;
    int last_single = 0;
    for (int i = 0; i < s.length(); i++) {
      if(dict.find(s[i]) != dict.end()) {
        last_single = max(dict.at(s[i]),last_single);
        dict.erase(dict.find(s[i]));
      }
      count = max(count, i - last_single + 1);
      dict.insert({s[i], i + 1});
    }
    return count;
  }
};

int main () {
  string s = " ";

  cout << Solution().lengthOfLongestSubstring(s);

  return 0;
}
