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
private:
  string thisLine(vector<string> words, int maxWidth, int start, int end, bool lastLine) {
    string ans;
    string regular = " ";
    int remain = 0;
    if (end - start == 0) {
      ans += words[start];
      while (ans.size() < maxWidth) ans.push_back(' ');
      return ans;
    }
    int spaces = maxWidth + 1;
    for (int i = start; i <= end; i++){
      spaces -= words[i].length() + 1;
    }
    if (lastLine){
      regular = " ";
      remain = 0;
    }
    else{
      string str(spaces / (end - start) + 1, ' ');
      regular = str;
      remain = spaces % (end - start);
    }
    ans += words[start];
    for (int i = start + 1; i <= end; i++) {
      ans += regular;
      if(remain > 0){
        ans.push_back(' ');
        remain--;
      }
      ans += words[i];
    }
    if(lastLine) while (ans.size() < maxWidth) ans.push_back(' ');
    return ans;
  }
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int cnt = 0;
    int start = 0;
    for (int i = 0; i < words.size(); i++) {
      cnt += words[i].length() + 1;
      if (i == words.size() - 1 || cnt + words[i + 1].size() > maxWidth) {
        ans.push_back(thisLine(words, maxWidth, start, i, i + 1 == words.size()));
        cnt = 0;
        start = i + 1;
      }
    }
    return ans;
  }
};
