//
// Created by lzr on 2022/4/5.
#include <vector>
#include <iostream>
using namespace std;

//位运算
class Solution {
 public:
  static int binaryGap(int n) {
    int last = -1, ans = 0;
    for (int i = 0; n; ++i) {
      if (n & 1) {
        if (last != -1) {
          ans = max(ans, i - last);
        }
        last = i;
      }
      n >>= 1;
    }
    return ans;
  }
};
int main(){
    int n = 5;
    cout << Solution::binaryGap(n) << endl;
    return 0;
}
