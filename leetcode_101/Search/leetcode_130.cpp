#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:

  void solve(vector<vector<char>>& board) {
    int m = board.size(),n = board[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;++i){
      dfs(board,visited,i,0);
      dfs(board,visited,i,n-1);
    }
    for(int i=1;i<n;++i){
      dfs(board,visited,0,i);
      dfs(board,visited,m-1,i);
    }
    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j){
        if(board[i][j] == 'O' && !visited[i][j])
          board[i][j] = 'X';
      }
  }

  void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j){
    if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j] == 'X' || visited[i][j])
      return;
    visited[i][j] = true;
    dfs(board,visited,i+1,j);
    dfs(board,visited,i-1,j);
    dfs(board,visited,i,j+1);
    dfs(board,visited,i,j-1);
  }
};

int main(){
  vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
  Solution test;
  test.solve(board);
  return 0;
}