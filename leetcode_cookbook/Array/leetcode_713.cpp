#include <vector>
#include <iostream>
using namespace std;
//滑动窗口
class Solution {
 public:
  static int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size(), ret = 0;
    int prod = 1, i = 0;
    for (int j = 0; j < n; j++) {
      prod *= nums[j];
      while (i <= j && prod >= k) {
        prod /= nums[i];
        i++;
      }
      ret += j - i + 1;
    }
    return ret;
  }
};

int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;
    cout << Solution::numSubarrayProductLessThanK(nums,k) << endl;
    return 0;
}