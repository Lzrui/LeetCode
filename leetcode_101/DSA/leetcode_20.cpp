#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool isValid(string s) {
    stack<char> parsed;
    for (auto & ch : s) {
      if (ch == '(' || ch == '[' || ch == '{')
        parsed.emplace(ch);
      else {
        if (parsed.empty())
          return false;
        char top = parsed.top();
        if ((top == '(' && ch == ')') ||
            (top == '[' && ch == ']') ||
            (top == '{' && ch == '}'))
          parsed.pop();
        else
          return false;
      }
    }
    return parsed.empty();
  }
};

int main() {
  string s("()[]{}");
  cout << Solution::isValid(s) << endl;
  return 0;
}