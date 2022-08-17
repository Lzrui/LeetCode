#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for (const int & val : nums) {
      hash.emplace(val);
    }
    int res = 0;
    while (!hash.empty()) {
      int val = *(hash.cbegin());
      hash.erase(val);
      int prev = val - 1, next = val + 1;
      while (hash.count(prev)) {
        hash.erase(prev--);
      }
      while (hash.count(next)) {
        hash.erase(next++);
      }
      res = max(res, next - prev - 1);
    }
    return res;
   }
};

int main() {
  vector<int> nums = {1, 2, 0, 1};
  printf("%d\n", Solution::longestConsecutive(nums));
  return 0;
}

