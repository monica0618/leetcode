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
  string countAndSay(int n) {
    string str;
    if (n == 1) return "1";
    if (n == 2) return "11";
    string last = countAndSay(n - 1);
    char temp = last[0];
    int count = 1;
    for(int i = 1; i < last.size(); i++) {
      if (i == last.size() - 1){
        if (last[i] == temp){
          str.push_back((char)('0' + count + 1));
          str.push_back(temp);
        }
        else {
          str.push_back((char)('0' + count));
          str.push_back(temp);
          str.push_back((char)('0' + 1));
          str.push_back(last[i]);
        }
      }
      else if (last[i] != temp) {
        str.push_back((char)('0' + count));
        count = 1;
        str.push_back(temp);
        temp = last[i];
      }
      else count++;
    }
    return str;
  }
};

int main () {
  cout << Solution().countAndSay(4);
  return 0;
}
