#include<bits/stdc++.h>

using namespace std;
//贪心
class Solution {
 public:
  static bool checkPossibility(vector<int> &nums) {
    int n = nums.size(), cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
      int x = nums[i], y = nums[i + 1];
      if (x > y) {
        cnt++;
        if (cnt > 1) {
          return false;
        }
        if (i > 0 && y < nums[i - 1]) {
          nums[i + 1] = x;
        }
      }
    }
    return true;
  }
};

int main(){
  vector<int> nums = {4,2,3};
  cout << Solution::checkPossibility(nums) << endl;
  return 0;
}