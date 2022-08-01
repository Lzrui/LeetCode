#include<bits/stdc++.h>

using namespace std;

//埃氏筛法
//class Solution {
// public:
//  static int countPrimes(int n) {
//    if (n <= 2) return 0;
//    vector<bool> prime(n, true);
//    int cnt = n - 2;
//    for (int i = 2; i <= sqrt(n); ++i) {
//      if (prime[i]) {
//        for (int j = 2 * i; j < n; j += i) {
//          if (prime[j]) {
//            prime[j] = false;
//            --cnt;
//          }
//        }
//      }
//    }
//    return cnt;
//  }
//};

//优化后的埃氏筛法
class Solution {
 public:
  static int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    int i = 3, sqrtn = sqrt(n), count = n / 2; // 偶数一定不是质数
    while (i <= sqrtn) { // 最小质因子一定小于等于开方数
      for (int j = i * i; j < n; j += 2 * i) { // 避免偶数和重复遍历
        if (prime[j]) {
          --count;
          prime[j] = false; }
      }
      do {
        i += 2;
      } while (i <= sqrtn && !prime[i]);
    }// 避免偶数和重复遍历 }
    return count;
  }
};

int main(){
  int n = 10;
  cout << Solution::countPrimes(n) << endl;
  return 0;
}