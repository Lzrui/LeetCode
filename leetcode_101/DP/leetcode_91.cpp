#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    if(s[0] != '0') dp[1] = 1;
    for(int i = 2;i <= n;++i){
      if(s[i-1] == '0'){
        if(s[i-2] != '1' && s[i-2] != '2')
          return 0;
      }
      else dp[i] += dp[i-1];
      if(s[i-2] == '1')
        dp[i] += dp[i-2];
      else if(s[i-2] == '2'){
        if(s[i-1] - '0' <= 6)
          dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }
};

int main(){
  string s("2020");
  cout << Solution::numDecodings(s) << endl;
  return 0;
}