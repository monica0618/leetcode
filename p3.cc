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
    int max_count = 0;
    int last_single = 0;
    for (int i = 0; i < s.length(); i++) {
      if(dict.find(s[i]) == dict.end()) {
        dict.insert({s[i], i});
        count ++;
        // cout << s[i] << " " << count << " ";
      }
      else if (dict.find(s[i]) != dict.end()) {
        // unordered_map<char,int>::iterator it = dict.begin();
        if(count > max_count) max_count = count;
        if(dict.at(s[i]) > last_single) last_single = dict.at(s[i]);
        count = i - last_single;
        dict.erase(dict.find(s[i]));
        dict.insert({s[i],i});
        // cout << s[i]<< " " << i  << " " << count << " " << max_count <<"| ";
        // for (it=dict.begin(); it!=dict.end(); ++it)
        //   cout << it->first << " => " << it->second << '\n';
      }
    }
    if (count > max_count) max_count = count;
    return max_count;
  }
};

int main () {
  string s = "abba";

  cout << Solution().lengthOfLongestSubstring(s);

  return 0;
}

