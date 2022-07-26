#include<bits/stdc++.h>

using namespace std;

//动态规划1
//class Solution {
// public:
//  static int lengthOfLIS(vector<int>& nums) {
//    int max_len = 0, n = nums.size();
//    vector<int> dp(n,1);
//    for (int i = 0; i < n; ++i) {
//      for (int j = 0; j < i; ++j) {
//        if (nums[i] > nums[j]) {
//          dp[i] = max(dp[i], dp[j] + 1);
//        }
//      }
//      max_len = max(max_len, dp[i]);
//    }
//    return max_len;
//  }
//};

//动态规划2
class Solution {
 public:
  static int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
      if (dp.back() < nums[i]) {
        dp.push_back(nums[i]);
      } else {
        auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
        *itr = nums[i];
      }
    }
    return dp.size();
  }
};

int main(){
  vector<int> nums = {10,9,2,5,3,7,101,18};
  cout << Solution::lengthOfLIS(nums) << endl;
  return 0;
}