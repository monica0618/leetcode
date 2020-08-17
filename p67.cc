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
  string addBinary(string a, string b) {
    string ans;
    int c = 0;
    int s = 0;
    int aa = 0;
    int bb = 0;
    while (!a.empty() || !b.empty()) {
      if (!a.empty()) aa = a.back() == '0' ? 0:1;
      else aa = 0;
      if (!b.empty()) bb = b.back() == '0' ? 0:1;
      else bb = 0;
      switch (aa + bb + c) {
      case 0: {
        s = 0;
        c = 0;
        break;
      }
      case 1: {
        s = 1;
        c = 0;
        break;
      }
      case 2: {
        s = 0;
        c = 1;
        break;
      }
      case 3: {
        s = 1;
        c = 1;
        break;
      }
      }
      if (!a.empty()) a.pop_back();
      if (!b.empty()) b.pop_back();
      if (s == 1) ans.insert(ans.begin(), '1');
      else ans.insert(ans.begin(), '0');
    }
    if (c > 0) ans.insert(ans.begin(), '1');
    return ans;
  }
};
