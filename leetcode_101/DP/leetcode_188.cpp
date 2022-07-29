#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    if (days < 2) return 0;
    if (k >= (days / 2)) return maxProfitUnlimited(prices);
    vector<int> buy(k+1,INT_MIN), sell(k+1,0);
    for (int i = 0; i < days; ++i) {
      for (int j = 1; j <= k; ++j) {
        buy[j] = max(buy[j], sell[j-1] - prices[i]);
        sell[j] = max(sell[j], buy[j] + prices[i]);
      }
    }
    return sell[k];
  }

  static int maxProfitUnlimited(vector<int>& prices) {
    int max_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int sub = prices[i] - prices[i-1];
        max_profit += sub > 0 ? sub : 0;
    }
    return max_profit;
  }
};


int main(){
  vector<int> prices = {3,2,6,5,0,3};
  int k = 2;
  cout << Solution::maxProfit(2,prices) << endl;
  return 0;
}