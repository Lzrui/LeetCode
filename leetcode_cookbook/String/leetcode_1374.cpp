#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static string generateTheString(int n) {
    if (n % 2 == 1) {
      return string(n, 'a');
    }
    return string(n - 1, 'a') + 'b';
  }
};


int main(){
  int n = 7;
  string res = Solution::generateTheString(n);
  return 0;
}