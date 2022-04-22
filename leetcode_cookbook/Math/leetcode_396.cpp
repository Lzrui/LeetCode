//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
//公式迭代
class Solution {
 public:
  static int maxRotateFunction(vector<int>& nums) {
    int f = 0, n = nums.size();
    int numSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < n; i++) {
      f += i * nums[i];
    }
    int res = f;
    for (int i = n - 1; i > 0; i--) {
      f += numSum - n * nums[i];
      res = max(res, f);
    }
    return res;
  }
};

int main(){
  vector<int> nums = {4,3,2,6};
  cout << Solution::maxRotateFunction(nums) << endl;
  return 0;
}



