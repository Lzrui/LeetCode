#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool checkLength(vector<int>& v1, vector<int>& v2) {
    return (v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]);
  }

  static bool checkMidPoint(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return (p1[0] + p2[0]) == (p3[0] + p4[0]) && (p1[1] + p2[1]) == (p3[1] + p4[1]);
  }

  static int calCos(vector<int>& v1, vector<int>& v2) {
    return (v1[0] * v2[0] + v1[1] * v2[1]) == 0;
  }

  static bool help(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<int> v1 = {p1[0] - p2[0], p1[1] - p2[1]};
    vector<int> v2 = {p3[0] - p4[0], p3[1] - p4[1]};
    if (checkMidPoint(p1, p2, p3, p4) && checkLength(v1, v2) && calCos(v1, v2)) {
      return true;
    }
    return false;
  }

  static bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    if (p1 == p2) {
      return false;
    }
    if (help(p1, p2, p3, p4)) {
      return true;
    }
    if (p1 == p3) {
      return false;
    }
    if (help(p1, p3, p2, p4)) {
      return true;
    }
    if (p1 == p4) {
      return false;
    }
    if (help(p1, p4, p2, p3)) {
      return true;
    }
    return false;
  }
};

int main(){
  int a = 5;
  vector<int> p1{0, 0}, p2{1, 1}, p3{1, 0}, p4{0, 1};
  cout << Solution::validSquare(p1, p2, p3, p4) << endl;
  return 0; 
}