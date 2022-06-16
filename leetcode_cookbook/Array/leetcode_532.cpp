#include<bits/stdc++.h>

using namespace std;
//排序+双指针
class Solution {
 public:
  static int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), y = 0, res = 0;
    for (int x = 0; x < n; x++) {
      if (x == 0 || nums[x] != nums[x - 1]) {
        while (y < n && (nums[y] < nums[x] + k || y <= x)) {
          y++;
        }
        if (y < n && nums[y] == nums[x] + k) {
          res++;
        }
      }
    }
    return res;
  }
};

int main(){
  vector<int> nums = {1,3,1,5,4};
  int k = 2;
  cout << Solution::findPairs(nums,k) << endl;
  return 0;
}