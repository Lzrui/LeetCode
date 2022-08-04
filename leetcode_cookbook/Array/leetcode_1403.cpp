#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(),nums.end(), greater<>());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size(), curr = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (sum < curr) break;
      res.emplace_back(nums[i]);
      curr += nums[i];
      sum -= nums[i];
    }
    return res;
  }
};

int main(){
  vector<int> nums = {4,3,10,9,8};
  vector<int> res = Solution::minSubsequence(nums);
  return 0;
}