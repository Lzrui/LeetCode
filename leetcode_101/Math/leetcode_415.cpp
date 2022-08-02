#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static string addStrings(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0) {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int result = x + y + add;
      ans.push_back('0' + result % 10);
      add = result / 10;
      i -= 1;
      j -= 1;
    }
    // 计算完以后的答案需要翻转过来
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(){
  string num1("456"), num2("77");
  string res = Solution::addStrings(num1, num2);
  return 0;
}