#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }
      dq.emplace_back(i);
      if (i >= k - 1)
        res.emplace_back(nums[dq.front()]);
    }
    return res;
  }
};

int main() {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  vector<int> res = Solution::maxSlidingWindow(nums, k);
  return 0;
};

