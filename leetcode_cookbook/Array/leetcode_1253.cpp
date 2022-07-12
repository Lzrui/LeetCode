#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
 public:
  static int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<int> rows(m), cols(n);
    for (auto & index : indices) {
      rows[index[0]]++;
      cols[index[1]]++;
    }
    int oddx = 0, oddy = 0;
    for (int i = 0; i < m; i++) {
      if (rows[i] & 1) {
        oddx++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (cols[i] & 1) {
        oddy++;
      }
    }
    return oddx * (n - oddy) + (m - oddx) * oddy;
  }
};


int main(){
  int m = 2, n= 3;
  vector<vector<int>> indices = {{0,1},{1,1}};
  cout << Solution::oddCells(m,n,indices) << endl;
  return 0;
}