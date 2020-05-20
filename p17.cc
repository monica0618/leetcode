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
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size() == 0) return ans;
    unordered_map<int,string> button{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8, "tuv"},{9,"wxyz"}};
    int d = digits[0] - '0';
    for(int i = 0; i < button.at(d).size(); i++){
      char c = button.at(d)[i];
      string sc(1,c);
      ans.push_back(sc);
    }
    for(int i = 1; i < digits.size(); i++) {
      d = digits[i] - '0';
      int s = ans.size();
      for(int j = 0; j < button.at(d).size(); j++){
        for(int k = 0; k < s; k++){
          ans.push_back(ans[k]+button.at(d)[j]);
        }
      }
      ans.erase(ans.begin(),ans.begin()+s);
    }
    return ans;
  }
};


int main () {
  string d = "279";
  vector<string> ans = Solution().letterCombinations(d);
  for(string s:ans) cout << s <<" ";
  return 0;
}
