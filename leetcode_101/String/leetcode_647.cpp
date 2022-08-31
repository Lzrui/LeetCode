#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int countSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      count += extendSubstrings(s, i, i);
      count += extendSubstrings(s, i, i + 1);
    }
    return count;
  }

  static int extendSubstrings(string &s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      --l;
      ++r;
      ++count;
    }
    return count;
  }
};

int main() {
  string s("aaa");
  int res = Solution::countSubstrings(s);
  return 0;
}

