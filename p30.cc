#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans{};
    if(words.size() == 0) return ans;
    if(s.length() == 0) return ans;
    int wordlen = words[0].length();
    int wordnum = words.size();
    int findlen = wordlen * wordnum;
    unordered_map<string, int> dict;
    for(int i = 0; i < wordnum; i++) {
      if(dict.find(words[i]) == dict.end()) dict.insert({words[i], 1});
      else dict.find(words[i])->second++;
    }

    unordered_map<string,int> dictnew;
    for(int i = 0; i < s.length() - findlen  + 1; i++) {
      dictnew.clear();
      int count = 0;
      bool flag = true;
      while (count < wordnum && flag) {
        string candi = s.substr(i + count * wordlen, wordlen);
        if (dict.find(candi) == dict.end()) flag = false;
        else if (dictnew.find(candi) != dictnew.end()) {
          dictnew.find(candi)->second++;
          if(dict.at(candi) < dictnew.at(candi)) flag = false;
        }
        else if (dict.find(candi) != dict.end()) dictnew.insert({candi, 1});
        if (flag) count++;
      }
      if (count == wordnum){
        ans.push_back(i);
      }
    }

    return ans;

  }
};

int main () {
	string str("");
	vector<string> words{"bar","foo"};
	vector<int> ans = Solution().findSubstring(str, words);
	for (int a:ans)
		cout << a << " ";
	cout << endl;
	return 0;
}
