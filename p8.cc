#include "bits/stdc++.h"

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

bool is_number(char c){
  if(int(c) >= 48 && int(c) <= 57) return true;
  return false;
}

class Solution {
public:
  int myAtoi(string str) {
    int i = 0;
    while(i < str.size()) {
      if(int(str[i]) == 45 && is_number(str[i+1])){
        int j = i + 1;
        long long ans = 0;
        while(is_number(str[j])){
          int d = int(str[j]) - 48;
          ans = (ans + d) * 10;
          if(ans >= 21474836480) return -2147483648;
          j++;
        }
        ans /= -10;
        return ans;
      }
      else if(int(str[i]) == 43 && is_number(str[i+1])){
        int j = i + 1;
        long long ans = 0;
        while(is_number(str[j])){
          int d = int(str[j]) - 48;
          ans = (ans + d) * 10;
          if(ans >= 21474836470) return 2147483647;
          j++;
        }
        ans /= 10;
        return ans;
      }
      else if(is_number(str[i])) {
        int j = i;
        long long ans = 0;
        while(is_number(str[j])){
          int d = int(str[j]) - 48;
          ans = (ans + d) * 10;
          if(ans >= 21474836470) return 2147483647;
          j++;
        }
        ans /= 10;
        return ans;
      }
      else if(int(str[i]) == 32) i++;
      else return 0;
    }

    return 0;

  }
};

int main () {
  cout << Solution().myAtoi(" -21474836480");
  return 0;
}
