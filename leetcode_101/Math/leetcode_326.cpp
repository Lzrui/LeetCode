#include<bits/stdc++.h>

using namespace std;

//试除法
class Solution {
 public:
  static bool isPowerOfThree(int n) {
    while (n && n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
};

int main(){
  int n = 59048;
  bool is_3_pow = Solution::isPowerOfThree(n);
  return 0;
}