#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    int x = (n + 1) / 2;
    for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
      nums[i] = arr[j];
      if (i + 1 < n) {
        nums[i + 1] = arr[k];
      }
    }
  }
};

int main(){
  vector<int> nums = {1,1,1,2,4};
  Solution::wiggleSort(nums);
  return 0;
}