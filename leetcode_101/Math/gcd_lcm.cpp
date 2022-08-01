#include<bits/stdc++.h>

using namespace std;

//最大公因数
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

//最小公倍数
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

//扩展欧几里得算法
int xGCD(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1, gcd = xGCD(b, a % b, x1, y1);
  x = y1, y = x1 - (a / b) * y1;
  return gcd;
}

int main(){
  int a = 6, b = 8;
  int temp = gcd(a, b);
  temp = lcm(a, b);
  return 0;
}