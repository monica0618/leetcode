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
  string getPermutation(int n, int k) {
    string ans;
    vector<int> arr;
    int fac = 1;
    int i = 1;
    while (i < n) {
      arr.push_back(i);
      fac *= i;
      i++;
    }
    arr.push_back(i);
    i--;
    while(i > 0) {
      int n = (k - 1) / fac;
      int a = arr[n];
      arr.erase(arr.begin() + n);
      ans.push_back((char)(a + '0'));
      k = k - fac * n;
      fac /= i;
      i--;
    }
    ans.push_back((char)(arr[0] + '0'));
    return ans;
  }
};
