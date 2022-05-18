#include<bits/stdc++.h>

using namespace std;


class Solution {
 public:
  static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0) {
      nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
      nums1[pos--] = nums2[n--];
    }
  }
};

int main(){
  vector<int> nums1 = {4,5,6,0,0,0};
  vector<int> nums2 = {1,2,3};
  int n=3,m=3;
  Solution::merge(nums1,m,nums2,n);
  return 0;
}