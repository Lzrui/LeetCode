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
    if (prices.empty()) {
      return 0;
    }

    int n = prices.size();
    // f[i][0]: 手上持有股票的最大收益
    // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
    // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
    vector<vector<int>> f(n, vector<int>(3));
    f[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
      f[i][1] = f[i - 1][0] + prices[i];
      f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    return max(f[n - 1][1], f[n - 1][2]);
  }
};

int main(){
  vector<int> prices = {1,2,3,0,2};
  cout << Solution::maxProfit(prices) << endl;
  return 0;
}