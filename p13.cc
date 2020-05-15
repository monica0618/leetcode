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
  int romanToInt(string s) {
    unordered_map<char,int> dict = {
      {'I',1},{'V',5},{'X',10},{'L',50},{'C',100}, {'D',500},{'M',1000}
    };
    int ans = 0;
    int i = 0;
    while(i < s.size()) {
      if(i + 1 < s.size() && dict.at(s[i+1]) == 5 * dict.at(s[i])) { //here make sure i+1 is not out of range
        ans += dict.at(s[i+1]) * 4 / 5;
        i += 2;
      }
      else if(i + 1 < s.size() && dict.at(s[i+1]) == 10 * dict.at(s[i])){
        ans += dict.at(s[i+1]) * 9 / 10;
        i += 2;
        }
      else {
        ans += dict.at(s[i]);
        i++;
      }
    }
    return ans;
  }
};

int main () {
  string s = "MCMXCIV";
  cout << Solution().romanToInt(s);
  return 0;
}
