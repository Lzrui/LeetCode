#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, psum = 0;
    unordered_map<int, int> hashmap;
    hashmap[0] = 1;
    for (int & val : nums) {
      psum += val;
      cnt += hashmap[psum-k];
      ++hashmap[psum];
    }
    return cnt;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  int k = 3;
  int ans = Solution::subarraySum(nums, k);
  return 0;
}

