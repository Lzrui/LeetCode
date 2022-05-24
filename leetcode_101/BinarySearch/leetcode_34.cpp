#include<bits/stdc++.h>

using namespace std;
//class Solution {
// public:
//  static vector<int> searchRange(vector<int>& nums, int target) {
//    if(nums.empty()) return {-1,-1};
//    int lower = lower_bound(nums,target);
//    int upper = upper_bound(nums,target)-1;
//    if(lower == nums.size() || nums[lower] != target)
//      return {-1,-1};
//    return {lower,upper};
//  }
//
//  static int lower_bound(vector<int> &nums, int target){
//    int l = 0,r = nums.size();
//    while(l < r){
//      int mid = l + (r-l)/2;
//      if(nums[mid] < target)
//        l = mid+1;
//      else r = mid;
//    }
//    return l;
//  }
//
//  static int upper_bound(vector<int> &nums, int target){
//    int l = 0,r = nums.size();
//    while(l < r){
//      int mid = l + (r-l)/2;
//      if(nums[mid] <= target)
//        l = mid+1;
//      else r = mid;
//    }
//    return l;
//  }
//
//};
class Solution {
 public:
  static int binarySearch(vector<int>& nums, int target, bool lower) {
    int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target || (lower && nums[mid] >= target)) {
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

   static vector<int> searchRange(vector<int>& nums, int target) {
    int leftIdx = binarySearch(nums, target, true);
    int rightIdx = binarySearch(nums, target, false) - 1;
    if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
      return vector<int>{leftIdx, rightIdx};
    }
    return vector<int>{-1, -1};
  }
};

int main(){
  int target = 8;
  vector<int> nums = {5,7,7,8,8,10};
  vector<int> res = Solution::searchRange(nums,target);
  return 0;
}