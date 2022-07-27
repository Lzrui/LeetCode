#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int n = nums.size();
    int target = sum / 2;
    vector<bool> dp(target+1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = dp[j] || dp[j-nums[i]];
      }
    }
    return dp[target];
  }
};

int main(){
  vector<int> nums = {1,5,11,5};
  cout << Solution::canPartition(nums) << endl;
  return 0;
}