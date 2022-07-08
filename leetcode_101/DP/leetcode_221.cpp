#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
 public:
  static int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    int m = matrix.size(),n = matrix[0].size();
    int max_edge = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=1;i<=m;++i)
      for(int j=1;j<=n;++j){
        if(matrix[i-1][j-1] == '1'){
          dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
          max_edge = max(dp[i][j],max_edge);
        }
      }
    return max_edge * max_edge;
  }
};

int main(){
  vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  cout << Solution::maximalSquare(matrix) << endl;
  return 0;
}