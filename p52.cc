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
  bool danger(int row, int col, int n, vector<string>& board){
    int dia1 = row - col;
    int dia2 = row + col;
    for(int i = 0; i < n; i++) {
      if (board[i][col] == 'Q') return true;
    }
    int r = row;
    int c = col;
    while(r > 0 && c > 0){
      if (board[r-1][c-1] == 'Q') return true;
      r--;c--;
    }
    r = row;
    c = col;
    while(r > 0 && c < n - 1){
      if (board[r-1][c+1] == 'Q') return true;
      r--;c++;
    }
    return false;
  }

  void backtrack(int row, int n, vector<string>& board, int& ans) {
    if (row >= n) ans++;
    for (int i = 0 ; i < n; i++) {
      if (!danger(row, i, n, board)) {
        board[row][i] = 'Q';
        backtrack(row + 1, n, board, ans);
        board[row][i] = '.';
      }
    }
  }

  int totalNQueens(int n) {
    string line;
    for (int i = 0 ; i < n; i++) line.push_back('.');
    vector<string> board(n, line);
    int ans = 0;
    backtrack(0, n, board, ans);
    return ans;
  }
};
