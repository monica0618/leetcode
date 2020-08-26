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
  bool backtrack(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& used, string word, int k) {
    bool ans = false;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
    if (board[i][j] != word[k]) return false;
    else if (used[i][j]) return false;
    else if (k == word.size() - 1 && board[i][j] == word[k]) return true;
    else {
      used[i][j] = true;
      ans = backtrack(i-1, j, board, used, word, k+1) || backtrack(i, j-1, board, used, word, k+1) || backtrack(i+1, j, board, used, word, k+1) || backtrack(i, j+1, board, used, word, k+1);
      used[i][j] = false;
    }
    return ans;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> used(m, vector<bool>(n, 0));
    bool ans = false;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] != word[0]) continue;
        ans = backtrack(i,j,board,used, word,0);
        if (ans) return true;
      }
    }

    return false;

  }
};
