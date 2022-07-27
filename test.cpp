#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static string fractionAddition(string expression) {
    long long denominator = 0, numerator = 1; // 分子，分母
    int index = 0, n = expression.size();
    while (index < n) {
      // 读取分子
      long long denominator1 = 0, sign = 1;
      if (expression[index] == '-' || expression[index] == '+') {
        sign = expression[index] == '-' ? -1 : 1;
        index++;
      }
      while (index < n && isdigit(expression[index])) {
        denominator1 = denominator1 * 10 + expression[index] - '0';
        index++;
      }
      denominator1 = sign * denominator1;
      index++;

      // 读取分母
      long long numerator1 = 0;
      while (index < n && isdigit(expression[index])) {
        numerator1 = numerator1 * 10 + expression[index] - '0';
        index++;
      }

      denominator = denominator * numerator1 + denominator1 * numerator;
      numerator *= numerator1;
    }
    if (denominator == 0) {
      return "0/1";
    }
    long long g = gcd(abs(denominator), numerator); // 获取最大公约数
    return to_string(denominator / g) + "/" + to_string(numerator / g);
  }
};

int main(){
  string expression("1/3-1/2");
  cout << Solution::fractionAddition(expression) << endl;
  return 0;
}