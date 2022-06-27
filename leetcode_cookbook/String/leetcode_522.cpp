#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
   static int findLUSlength(vector<string>& strs) {
    auto is_substr = [](const string &a,const string &b){
      int i=0,j=0;
      while(i<a.size() && j<b.size()) {
        if (a[i] == b[j])
          ++i;
        ++j;
      }
      return i == a.size();
    };

    int n = strs.size();
    int ans = -1;
    for(int i=0;i<n;++i){
      bool check = true;
      for(int j=0;j<n;++j){
        if(i!= j && is_substr(strs[i],strs[j])){
         check = false;
         break;
        }
      }
      if(check){
        ans = max(ans,(int)strs[i].size());
      }
    }
    return ans;
  }
};

int main(){
  vector<string> strs = {"aba","cdc","eae"};
  cout << Solution::findLUSlength(strs) << endl;
  return 0;
}