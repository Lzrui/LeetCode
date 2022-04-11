//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
using namespace std;
//排列组合
class Solution {
 public:
  static int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return 10;
    }
    int ans = 10, cur = 9;
    for (int i = 0; i < n - 1; ++i) {
      cur *= 9 - i;
      ans += cur;
    }
    return ans;
  }
};

int main(){
  cout << Solution::countNumbersWithUniqueDigits(2) << endl;
  return 0;
}



