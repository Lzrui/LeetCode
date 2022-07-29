#include<bits/stdc++.h>

using namespace std;
//贪心
class Solution {
 public:
  static int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = (int)prices.size();
    for (int i = 1; i < n; ++i) {
      ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};

//DP
//class Solution {
// public:
//  static int maxProfit(vector<int>& prices) {
//    int n = prices.size();
//    vector<vector<int>> dp (2, vector<int>(n));
//    dp[1][0] = -prices[0];
//    for (int i = 1; i < n; ++i) {
//      dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i]);
//      dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
//    }
//    return dp[0][n-1];
//  }
//};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  cout << Solution::maxProfit(prices) << endl;
  return 0;
}