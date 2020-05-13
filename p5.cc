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
  string longestPalindrome(string s) {
    int m = s.size();
    int maxl = 1;
    int maxp = 0;

    for(int i = 0; i < m; i++) {
      int j = 0;
      while(j <= i && s[i+j] == s[i-j]){
        j++;
      }
      if(2*j-1 > maxl) {
        maxl = 2*j-1;
        maxp = i-j+1;
      }
    }

    for(int i = 0; i < m; i++) {
      int j = 0;
      while(j <= i && s[i+1+j] == s[i-j]){
        j++;
      }
      if(2*j > maxl) {
        maxl = 2*j;
        maxp = i-j+1;
      }
    }

    return s.substr(maxp,maxl);

  }
};

int main() {
  string str = "";
  cout << Solution().longestPalindrome(str);

  return 0;
}
