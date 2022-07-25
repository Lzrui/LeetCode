#include<bits/stdc++.h>

using namespace std;
//暴力枚举

class Solution {
 public:
  static int numSquares(int n) {
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;++i){
      for(int j=1;j*j<=i;++j){
        dp[i] = min(dp[i-j*j]+1,dp[i]);
      }
    }
    return dp[n];
  }
};

int main(){
  int n = 12;
  cout << Solution::numSquares(n) << endl;
  return 0;
}