//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
using namespace std;
//模拟
//class Solution {
// public:
//  static bool rotateString(string s, string goal) {
//    int m = s.size(), n = goal.size();
//    if (m != n) {
//      return false;
//    }
//    for (int i = 0; i < n; i++) {
//      bool flag = true;
//      for (int j = 0; j < n; j++) {
//        if (s[(i + j) % n] != goal[j]) {
//          flag = false;
//          break;
//        }
//      }
//      if (flag) {
//        return true;
//      }
//    }
//    return false;
//  }
//};
//搜索字符串
class Solution {
 public:
  static bool rotateString(string s, string goal) {
    return s.size() == goal.size() && (s + s).find(goal) != string::npos;
  }
};
int main(){
  string s = "abcde",goal = "cdeab";
  cout << Solution::rotateString(s,goal) << endl;
  return 0;
}



