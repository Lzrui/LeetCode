#include <vector>
#include <iostream>
using namespace std;
//快速排序变形一
//class Solution {
// public:
//  static vector<int> sortArrayByParity(vector<int>& nums) {
//    int low = 0, high = nums.size()-1;
//    int pivot = nums[low];
//    while(low < high){
//      while(low < high && (nums[high] & 1) == 1){
//        --high;
//      }
//      nums[low] = nums[high];
//      while(low < high && (nums[low] & 1) == 0){
//        ++low;
//      }
//      nums[high] = nums[low];
//    }
//    nums[low] = pivot;
//    return nums;
//  }
//};
//快速排序变形二
class Solution {
 public:
  static vector<int> sortArrayByParity(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      while (left < right and nums[left] % 2 == 0) {
        left++;
      }
      while (left < right and nums[right] % 2 == 1) {
        right--;
      }
      if (left < right) {
        swap(nums[left++], nums[right--]);
      }
    }
    return nums;
  }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    nums = Solution::sortArrayByParity(nums);
    return 0;
}