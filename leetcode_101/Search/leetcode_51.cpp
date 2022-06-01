#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
// 主函数
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if (n == 0) {
      return ans;
    }
    vector<string> board(n, string(n, '.'));
    vector<bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
    backtracking(ans, board, column, ldiag, rdiag, 0, n);
    return ans;
  }

  // 辅函数
  void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<
      bool> &column, vector<bool> &ldiag, vector<bool> &rdiag, int row, int n) {
    if (row == n) {
      ans.push_back(board);
      return; }
    for (int i = 0; i < n; ++i) {
      if (column[i] || ldiag[n-row+i] || rdiag[row+i]) {
        continue; }
// 修改当前节点状态
      board[row][i] = 'Q';
      column[i] = ldiag[n-row+i] = rdiag[row+i] = true;
// 递归子节点
      backtracking(ans, board, column, ldiag, rdiag, row+1, n);
// 回改当前节点状态
      board[row][i] = '.';
      column[i] = ldiag[n-row+i] = rdiag[row+i] = false; } }
};

int main(){
  int n = 4;
  Solution test;
  vector<vector<string>> res = test.solveNQueens(n);
  return 0;
}