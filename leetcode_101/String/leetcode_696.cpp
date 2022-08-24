#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, count = 0;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i-1]) {
        ++cur;
      } else {
        pre = cur;
        cur = 1;
      }
      if (pre >= cur) {
        ++count;
      } }
    return count;
  }
};

int main() {
  string s("00110011");
  int res = Solution::countBinarySubstrings(s);
  return 0;
}

