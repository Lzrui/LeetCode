#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int calculate(string s) {
    vector<int> stk;
    char presign = '+';
    int num = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i]))
        num = 10 * num + (s[i] - '0');
      if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
        switch (presign) {
          case '+':
            stk.emplace_back(num);
            break;
          case '-':
            stk.emplace_back(-num);
            break;
          case '*':
            stk.back() *= num;
            break;
          case '/':
            stk.back() /= num;
        }
        presign = s[i];
        num = 0;
      }
    }
    return accumulate(stk.begin(), stk.end(), 0);
  }
};

int main() {
  string s("3+5 / 2 ");
  int res = Solution::calculate(s);
  return 0;
}

