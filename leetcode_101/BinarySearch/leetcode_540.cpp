#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == nums[mid ^ 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

int main(){
  vector<int> nums = {1,1,2,3,3,4,4,8,8};
  cout << Solution::singleNonDuplicate(nums) << endl;
  return 0;
}