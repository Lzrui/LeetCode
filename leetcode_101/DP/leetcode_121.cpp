#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int maxProfit(vector<int>& prices) {
    int inf = 1e9;
    int minprice = inf, maxprofit = 0;
    for (int price: prices) {
      maxprofit = max(maxprofit, price - minprice);
      minprice = min(price, minprice);
    }
    return maxprofit;
  }
};


int main(){
  vector<int> prices = {7,1,5,3,6,4};
  cout << Solution::maxProfit(prices) << endl;
  return 0; 
}