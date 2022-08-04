#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      //dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
      dp[i] = dp[i & (i-1)] + 1;
    }
    return dp;
  }
};

int main(){
  int n = 5;
  vector<int> res = Solution::countBits(n);
  return 0;
}