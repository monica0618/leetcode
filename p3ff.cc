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
    vector<int> arr(256, -1);
    int count = 0;
    int last_single = 0;
    for (int i = 0; i < s.length(); i++) {
      if(arr[s[i]] != -1) {
        last_single = max(arr[s[i]],last_single);
        arr[s[i]] = -1;
      }
      count = max(count, i - last_single + 1);
      arr[s[i]] = i + 1;
    }
    return count;
  }
};

int main () {
  string s = " ";

  cout << Solution().lengthOfLongestSubstring(s);

  return 0;
}
