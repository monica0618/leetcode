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
  bool isDigit(char c) {
    if ((int)c >= 48 && (int)c <= 57) return true;
    return false;
  }

  void deleteSpace(string& s) {
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    while (!s.empty() && s.back() == ' ') s.pop_back();
  }

  int num(char c) {
    switch(c) {
    case '+': return 0;
    case '-': return 0;
    case '.': return 2;
    case 'e': return 3;
    }
    if (isDigit(c)) return 1;
    else return 4;
  }

  bool isNumber(string s) {
    deleteSpace(s);
    if(s.empty()) return false;
    int n = s.size();

    int state = 0;
    vector<bool> finals{0,0,0,1,0,1,1,0};
    vector<vector<int> > transfer{{
        {1,  6,  2,  -1, -1},
        {-1, 6,  2,  -1, -1},
        {-1, 3,  -1, -1, -1},
        {-1, 3,  -1, 4,  -1},
        {7,  5,  -1, -1, -1},
        {-1, 5,  -1, -1, -1},
        {-1, 6,  3,  4,  -1},
        {-1, 5,  -1, -1, -1},
        {-1, -1, -1, -1, -1},
      }};

    for (int i = 0; i < n; ++i) {
      state = transfer[state][num(s[i])];
        if(state < 0) return false;
    }
    return finals[state];
  }
};
