#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int minStartValue(vector<int>& nums) {
    int accSum = 0, accSumMin = 0;
    for (int num : nums) {
      accSum += num;
      accSumMin = min(accSumMin, accSum);
    }
    return -accSumMin + 1;
  }
};


int main(){
  vector<int> nums = {-3,2,-3,4,2};
  cout << Solution::minStartValue(nums) << endl;
  return 0;
}