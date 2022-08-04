#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool isPowerOfFour(int n) {
    return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
  }
};

int main(){
  int n = 256;
  cout << Solution::isPowerOfFour(n) << endl;
  return 0;
}