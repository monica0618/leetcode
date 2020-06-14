#include "bits/stdc++.h"
using namespace std;

int main () {
  vector<int> n{4,10,1,4,5,8,8,4,4,5};
  vector<int> p{5,1,9,3,1,4,2,3,1,7,8,6,2,8};
  sort(p.begin(), p.end());
  sort(n.begin(),n.end());
  int i = 0; int j = 0; int k = 1;
  int temp1 = 0; int temp2 = 0;
  if(n.size() > 1) {
    while(i < p.size() && j < n.size() && k < n.size()) {
      if(p[i] < n[j] + n[k]){
        if(k+1 < n.size() && n[k+1] + n[0] <= p[i]){
          k++;
          j = 0;
          cout <<"a";
        }
        else {
          i++;
          cout <<"b";
        }
      }
      else if(p[i] == n[j] + n[k]) {
        if(p[i] != temp1 || n[k] != temp2) {
          cout << -1*n[k]<<" "<< -1*n[j]<<" "<< p[i] << endl;
      }
        temp1 = p[i];
        temp2 = n[k];
        if(k+1 < n.size() && n[k+1] + n[0] <= p[i]){
          k++;
          cout <<"c";
        }
        else {
          if(i+1 < p.size() && p[i+1] != p[i]) {
            k = 1;
            cout <<"k";
          }
          i++;
          cout <<"d";
        }
        j = 0;
      }
      else if(j < k - 1) {
        cout <<"e";
        j++;
      }
      else if(j == k - 1) {
        cout <<"f";
        k++;
        j = 0;
      }
    }
  }

  return 0;
}
