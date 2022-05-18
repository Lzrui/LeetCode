#include<bits/stdc++.h>

using namespace std;
//值二分查找
class Solution {
 public:
  static int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    while (left < right) {
      int x = left + (right - left) / 2;
      int count = x / n * n;
      for (int i = x / n + 1; i <= m; ++i) {
        count += x / i;
      }
      if (count >= k) {
        right = x;
      } else {
        left = x + 1;
      }
    }
    return left;
  }
};

int main(){
  int m = 2, n = 3, k = 4;
  cout << Solution::findKthNumber(m,n,k) << endl;
  return 0;
}