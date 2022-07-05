#include<bits/stdc++.h>

using namespace std;
//动态规划
//class Solution {
// public:
//  int climbStairs(int n) {
//    int p = 0, q = 0, r = 1;
//    for (int i = 1; i <= n; ++i) {
//      p = q;
//      q = r;
//      r = p + q;
//    }
//    return r;
//  }
//};
//矩阵快速幂
class Solution {
 public:
  vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
      }
    }
    return c;
  }

  vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
    vector<vector<long long>> ret = {{1, 0}, {0, 1}};
    while (n > 0) {
      if ((n & 1) == 1) {
        ret = multiply(ret, a);
      }
      n >>= 1;
      a = multiply(a, a);
    }
    return ret;
  }

  int climbStairs(int n) {
    vector<vector<long long>> ret = {{1, 1}, {1, 0}};
    vector<vector<long long>> res = matrixPow(ret, n-1);
    return res[0][0]+res[0][1];
  }
};

int main(){
  int n=33;
  Solution test;
  cout << test.climbStairs(n) << endl;
  return 0;
}