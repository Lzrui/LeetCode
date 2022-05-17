#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> twoSum(vector<int>& numbers, int target) {
    int low = 0, high = numbers.size() - 1;
    while (low < high) {
      int sum = numbers[low] + numbers[high];
      if (sum == target) {
        return {low + 1, high + 1};
      } else if (sum < target) {
        ++low;
      } else {
        --high;
      }
    }
    return {-1, -1};
  }
};

int main(){
  vector<int> numbers = {2,7,11,15};
  int target = 9;
  vector<int> res = Solution::twoSum(numbers,target);
  return 0;
}