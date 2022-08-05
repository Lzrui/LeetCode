#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for (const int & num : nums) {
      int pos = abs(num) - 1;
      if (nums[pos] > 0)
        nums[pos] = -nums[pos];
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0)
        res.emplace_back(i + 1);
    }
    return res;
  }
};

int main(){
  vector<int> nums = {4,3,2,7,8,2,3,1};
  vector<int> res = Solution::findDisappearedNumbers(nums);
  return 0;
}