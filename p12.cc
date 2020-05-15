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
  string intToRoman(int num) {
    string symbol = "IVXLCDM";
    string ans;
    ans.clear();
    int i = 0; //point to the first symbol;
    while(num >= 1) {
      int a = num % 10;
      if(a >= 0 && a <= 3){
        for(int j = 0; j < a; j++) ans.push_back(symbol[i]);
      }
      else if (a == 4) {
        ans.push_back(symbol[i+1]);
        ans.push_back(symbol[i]);
      }
      else if(a >= 5 && a <= 8){
        for(int j = 5; j < a; j++) ans.push_back(symbol[i]);
        ans.push_back(symbol[i+1]);
      }
      else if(a == 9) {
        ans.push_back(symbol[i+2]);
        ans.push_back(symbol[i]);
      }
      i += 2;
      num /= 10;
    }
    string ans_reverse;
    ans_reverse.clear();
    for(int i = ans.size()-1; i >= 0; i--) ans_reverse.push_back(ans[i]);
    return ans_reverse;
  }
};

int main () {
  cout << Solution().intToRoman(1994);
  return 0;
}
