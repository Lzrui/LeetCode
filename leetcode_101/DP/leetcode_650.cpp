#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int minSteps(int n) {
    vector<int> dp(n + 1);
    int h = sqrt(n);
    for (int i = 2; i <= n; ++i) {
      dp[i] = i;
      for (int j = 2; j <= h; ++j) {
        if (i % j == 0) {
          dp[i] = dp[j] + dp[i/j];
          break;
        }
      }
    }
    return dp[n];
  }
};

int main(){
  int n = 12;
  cout << Solution::minSteps(n) << endl;
  return 0;
}