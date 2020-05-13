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
  string convert(string s, int numRows) {
    string ans;
    ans.reserve(numRows);
    if(numRows == 1) return s;
    vector<vector<int>> bucket(numRows, vector<int> (0));
    for(int i = 0; i < numRows;i++) bucket[i].clear();
    for(int i = 0; i < s.size(); i++){
      int t = 0;
      if( i % (2 * numRows - 2) < numRows) t = i % (2 * numRows - 2) ;
      else t = 2 * numRows - 2 - i % (2 * numRows - 2);
      //cout << t <<" ";
      bucket[t].push_back(s[i]);
    }
    for(int i = 0; i < numRows; i++){
      for(char c:bucket[i]) ans.push_back(c);
    }
    return ans;
  }
};

int main (){
  string str = "ABc";
  cout << Solution().convert(str,2);
  return 0;
}
