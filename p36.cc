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
  bool pass(vector<vector<int>> list) {
    for (int i = 0; i < 9; i++) {
      vector<int> newl = list[i];
      sort(newl.begin(), newl.end());
      vector<int>::iterator newend = unique(newl.begin(), newl.end());
      newl.erase(newend, newl.end());
      if (newl.size() != list[i].size()) return false;
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> col(9,vector<int>(0));
    vector<vector<int>> row(9,vector<int>(0));
    vector<vector<int>> box(9,vector<int>(0));
    for (int i = 0; i <= 8; i++) {
      for (int j = 0; j <= 8; j++) {
        if (int(board[i][j]) != 46){
          int a = int(board[i][j]) - 48;
          col[j].push_back(a);
          row[i].push_back(a);
          int w = j / 3 + 3 * (i / 3);
          box[w].push_back(a);
        }
      }
    }
    if (pass(col) && pass(row) && pass(box)) return true;
    return false;
  }
};

int main () {
  vector<int> a{8,4,5,6,8};
  sort(a.begin(), a.end());
  unique(a.begin(),a.end());
  for(int b:a) cout <<b;
  //cout << Solution().isValidSudoku(b);
  return 0;
}


