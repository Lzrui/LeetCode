#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> dirs = {-1,0,1,0,-1};

  bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,string &word,int idx,int i,int j){
    if(i < 0 || j < 0 || i == board.size() ||
    j == board[0].size() || visited[i][j] || board[i][j] != word[idx])
    return false;
    if(idx == word.size()-1) return true;
    visited[i][j] = true;
    for(int k=0;k<4;++k){
      int dx=i+dirs[k],dy=j+dirs[k+1];
      if(dfs(board,visited,word,idx+1,dx,dy))
        return true;
    }
    visited[i][j] = false;
    return false;
  }


  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(),n = board[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;++i){
      for(int j=0;j<n;++j){
          if(dfs(board,visited,word,0,i,j))
            return true;
        }
      }
    return false;
    }
};

int main(){
  vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word("ABCCED");
  Solution test;
  cout << test.exist(board,word) << endl;
  return 0;
}