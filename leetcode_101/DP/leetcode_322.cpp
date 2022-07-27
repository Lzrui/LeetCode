#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (auto val: coins) {
      for (int i = val; i <= amount; ++i) {
        dp[i] = min(dp[i], dp[i-val] + 1);
      }
    }
    return dp[amount] == amount + 1? -1: dp[amount];
  }
};

int main(){
  vector<int> coins = {1,2,5};
  int amount = 11;
  cout << Solution::coinChange(coins, amount) << endl;
  return 0;
}