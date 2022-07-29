#include<bits/stdc++.h>

using namespace std;

//class Solution {
// public:
//  static int maxProfit(vector<int>& prices) {
//      int n = prices.size();
//      if (n == 0) {
//        return 0;
//      }
//      vector<int> buy(n), sell(n), s1(n), s2(n);
//      s1[0] = buy[0] = -prices[0];
//      sell[0] = s2[0] = 0;
//      for (int i = 1; i < n; i++) {
//        buy[i] = s2[i-1] - prices[i];
//        s1[i] = max(buy[i-1], s1[i-1]);
//        sell[i] = max(buy[i-1], s1[i-1]) + prices[i];
//        s2[i] = max(s2[i-1], sell[i-1]);
//      }
//      return max(sell[n-1], s2[n-1]);
//    }
//};

class Solution {
 public:
  static int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp (2, vector<int>(n));
    dp[1][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i]);
      dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
    }
    return dp[0][n-1];
  }
};

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  cout << Solution::maxProfit(prices) << endl;
  return 0;
}