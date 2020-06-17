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
  bool isValid(string s) {
    stack<char> mystack;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '(' || s[i] == '[' || s[i]=='{') mystack.push(s[i]);
      else if(s[i] == ')' || s[i] == ']' || s[i]=='}'){
        if(!mystack.empty()){
          if((s[i] == ')' && mystack.top() == '(') || (s[i] == ']' && mystack.top() == '[') || (s[i] == '}' && mystack.top() == '{')) mystack.pop();
          else return false;
        }
        else return false;
      }
    }
    return mystack.empty()? true:false;
  }
};

int main () {
  string s = "]";
  cout << Solution().isValid(s);
  return 0;
}
