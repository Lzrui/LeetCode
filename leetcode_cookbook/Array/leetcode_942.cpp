//
// Created by lzr on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
//贪心
class Solution {
 public:
  static vector<int> diStringMatch(string s) {
    int n = s.length(), lo = 0, hi = n;
    vector<int> perm(n + 1);
    for (int i = 0; i < n; ++i) {
      perm[i] = s[i] == 'I' ? lo++ : hi--;
    }
    perm[n] = lo; // 最后剩下一个数，此时 lo == hi
    return perm;
  }
};

int main(){
    string s("IDID");
    vector<int> res = Solution::diStringMatch(s);
    return 0;
}
