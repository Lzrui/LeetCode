#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int trailingZeroes(int n) {
    return n == 0 ? 0: n / 5 + trailingZeroes(n / 5);
  }
};

int main(){
  int n = 3;
  cout << Solution::trailingZeroes(3) << endl;
  return 0;
}