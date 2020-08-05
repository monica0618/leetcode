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
  bool pass(vector<vector<char>>& board, int val, int i, int j) {
    int w = j / 3 + 3 * (i / 3);
    char ch = (char)('0' + val);
    for (int k = 0; k < 9; k++) {
      if (board[i][k] == ch) return false;
      if (board[k][j] == ch) return false;
      if (board[(w /3) * 3 + k / 3 ][(w % 3) * 3 + k % 3] == ch) return false;
    }
    return true;
  }

  bool backtrack(vector<vector<char>>& board, int i, int j) {
    if (j == 9) return backtrack(board, i + 1, 0);
    if (i == 9) return true;
    if (board[i][j] != '.') return backtrack(board, i, j + 1);
    for (int k = 1; k <= 9; k++) {
      if(pass(board, k, i, j)) {
        board[i][j] = (char)('0' + k);
        if (backtrack(board, i, j + 1)) return true;
      }
    }
    board[i][j] = '.';
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
  }
};
