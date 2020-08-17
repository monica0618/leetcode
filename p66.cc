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
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    digits[i]++;
    if (digits[i] < 10) return digits;
    while (digits[i] > 9 && i > 0) {
      digits[i] = 0;
      digits[i-1]++;
      i--;
    }
    if (i == 0 && digits[i] > 9) {
      digits[i] = 0;
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};

