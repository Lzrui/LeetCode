#include<bits/stdc++.h>

using namespace std;
//双指针
//class Solution {
// public:
//  static bool judgeSquareSum(int c) {
//    long left = 0;
//    long right = (int)sqrt(c);
//    while (left <= right) {
//      long sum = left * left + right * right;
//      if (sum == c) {
//        return true;
//      } else if (sum > c) {
//        right--;
//      } else {
//        left++;
//      }
//    }
//    return false;
//  }
//};
//数学
class Solution {
 public:
  static bool judgeSquareSum(int c) {
    for (int base = 2; base * base <= c; base++) {
      // 如果不是因子，枚举下一个
      if (c % base != 0) {
        continue;
      }

      // 计算 base 的幂
      int exp = 0;
      while (c % base == 0) {
        c /= base;
        exp++;
      }

      // 根据 Sum of two squares theorem 验证
      if (base % 4 == 3 && exp % 2 != 0) {
        return false;
      }
    }

    // 例如 11 这样的用例，由于上面的 for 循环里 base * base <= c ，base == 11 的时候不会进入循环体
    // 因此在退出循环以后需要再做一次判断
    return c % 4 != 3;
  }
};
//使用sqrt函数
//class Solution {
// public boolean judgeSquareSum(int c) {
//    for (long a = 0; a * a <= c; a++) {
//      double b = Math.sqrt(c - a * a);
//      if (b == (int) b) {
//        return true;
//      }
//    }
//    return false;
//  }
//}
int main(){
  int c = 100000;
  cout << Solution::judgeSquareSum(c) << endl;
  return 0;
}