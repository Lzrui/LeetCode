#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto num: nums) {
      res ^= num;
    }
    return res;
  }
};

int main(){
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << Solution::singleNumber(nums) << endl;
  return 0;
}