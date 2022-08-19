#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mapped;
    mapped[nums[0]] = 0;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      auto pos = mapped.find(target - nums[i]);
      if (pos == mapped.end())
        mapped[nums[i]] = i;
      else
        return {pos->second, i};
    }
    return {};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = Solution::twoSum(nums, target);
  return 0;
}

