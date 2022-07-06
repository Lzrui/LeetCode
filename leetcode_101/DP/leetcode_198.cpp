#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int size = nums.size();
    if (size == 1) {
      return nums[0];
    }
    int first = nums[0], second = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
      int temp = second;
      second = max(first + nums[i], second);
      first = temp;
    }
    return second;
  }
};

int main(){
  vector<int> nums = {2,7,9,3,1};
  cout << Solution::rob(nums) << endl;
  return 0;
}