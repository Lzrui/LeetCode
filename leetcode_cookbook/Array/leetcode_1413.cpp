#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int minStartValue(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    int n = nums.size(), res = 1;
    for (int i = 0; i < n; ++i) {
      res = max(res, 1 - nums[i]);
    }
    return res;
  }
};

int main(){
  vector<int> nums = {-3,2,-3,4,2};
  cout << Solution::minStartValue(nums) << endl;
  return 0;
}