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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int half = (m + n) / 2;
    bool is_odd = (m + n) % 2;
    double result = -1;

    if(n > m) {
      vector<int> temp;
      for(int i = 0; i < m; i++){
        temp.push_back(nums1[i]);
      }
      nums1.clear();
      for(int i = 0; i < n; i++){
        nums1.push_back(nums2[i]);
      }
      nums2.clear();
      for(int i = 0; i < m; i++){
        nums2.push_back(temp[i]);
      }
      int t = m;
      m = n;
      n = t;
    }

    if(n == 0) {
      if(is_odd) result = nums1[half];
      else result = (nums1[half-1] + nums1[half]) / 2.0;
      return result;
    }

    int i = half - n;
    //cout << "half=" << half << m << n<<i << endl;
    while(i <= m) {
      int j = half - i;
      int lmax, rmin;
      if(j == n && i == 0) {
        lmax = nums2[j-1];
        rmin = nums1[i];
      }
      if(j == n && i != 0){
        lmax = max(nums1[i-1],nums2[j-1]);
        rmin = nums1[i];
      }
      else if(j == 0 && i == m){
        lmax = nums1[i-1];
        rmin = nums2[j];
      }
      if(j == 0 && i != m){
        lmax = nums1[i-1];
        rmin = min(nums2[j], nums1[i]);
      }
      else if(i != m && j != n){
        lmax = max(nums1[i-1], nums2[j-1]);
        rmin = min(nums1[i], nums2[j]);
      }
      // cout << lmax <<" " << rmin <<endl;
      if(rmin >= lmax){
        if(is_odd) result = rmin;
        else result = (lmax + rmin) / 2.0;
        return result;
      }
      else {
        i++;
      }
    }
    return -1;
  }
};

int main () {
  vector<int> a{1};
  vector<int> b{2,3,4};

  cout << Solution().findMedianSortedArrays(a,b);

  return 0;
}
