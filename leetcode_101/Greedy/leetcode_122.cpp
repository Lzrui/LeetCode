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

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  cout << Solution::maxProfit(prices) << endl;
  return 0;
}