#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
//遍历
class Solution {
 public:
  static int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = INT_MIN;
    for (auto &account : accounts) {
      maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
    }
    return maxWealth;
  }
};

int main(){
    vector<vector<int>> accounts = {{1,2,3},{4,5,6}};
    cout << Solution::maximumWealth(accounts) << endl;
    return 0;
}