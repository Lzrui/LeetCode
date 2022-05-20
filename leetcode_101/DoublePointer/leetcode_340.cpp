#include<bits/stdc++.h>

using namespace std;
//滑动窗口
class Solution {
  public:
  static int findKsubstr(string &s,int k){
    unordered_map<char,int> window;
    int l = 0,r = 0,res = 0,cnt = 0;
    for(;r<s.size();++r){
      if(!window[s[r]]++)
        ++cnt;
      while(cnt > k){
        res = max(r-l,res);
        if(--window[s[l]] == 0){
          --cnt;
        }
          ++l;
        }
      }
    return max(res,r-l);
    }
};

int main(){

  string s("aa");
  int k = 2;
  cout << Solution::findKsubstr(s,2) << endl;
  return 0;
}