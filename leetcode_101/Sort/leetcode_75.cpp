#include<bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
class Solution {
 public:
   static void sortColors(vector<int>& nums) {
     int i = 0,j = 0,k = nums.size()-1;
     while(i <= k){
       if(nums[i] == 1) ++i;
       else if(nums[i] == 0) swap(nums[j++],nums[i++]);
       else swap(nums[k--],nums[i]);
     }
  }
};

int main(){
  vector<int> nums = {2,0,2,1,1,0};
  Solution::sortColors(nums);
  return 0;
}