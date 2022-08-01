#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static string convertToBase7(int num) {
    if (!num) return "0";
    bool is_negative = num < 0;
    if (is_negative) num = -num;
    string ans;
    while (num) {
      int a = num / 7, b = num % 7;
      ans = to_string(b) + ans;
      num = a;
    }
    return is_negative? "-" + ans : ans;
  }
};

int main(){
  int num = 100;
  string res = Solution::convertToBase7(num);
  return 0;
}