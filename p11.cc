#include "bits/stdc++.h"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

int get_area(int a,int b,int l) {
  return min(a,b)*l;
}

/*because the area is decided by the shorter side, only move the the shorter side can possibly increase the area*/

class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int area = get_area(height[i], height[j], j-i);
    int k;
    while(i < j) {
      if(height[i] <= height [j]) {
        i++;
        area =max(area, get_area(height[i], height[j], j-i));
      }
      else {
        j--;
        area = max(area, get_area(height[i], height[j], j-i));
      }
    }
    return area;
  }
};

int main () {
  vector<int> a{1,8,6,2,5,4,8,3,7};
  cout << Solution().maxArea(a);
  return 0;
}
