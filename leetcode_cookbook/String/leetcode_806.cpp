//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <vector>
using namespace std;
//直接遍历
const int MAX_WIDTH = 100;

class Solution {
 public:
  static vector<int> numberOfLines(vector<int>& widths, string s) {
    int lines = 1;
    int width = 0;
    for (auto & c : s) {
      int need = widths[c - 'a'];
      width += need;
      if (width > MAX_WIDTH) {
        lines++;
        width = need;
      }
    }
    return {lines, width};
  }
};
int main(){
  string s = "abcdefghijklmnopqrstuvwxyz";
  vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
  vector<int> res =  Solution::numberOfLines(widths,s);
  return 0;
}



