#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited) {
    visited[i] = true;
    for (int k = 0; k < friends.size(); ++k) {
      if (friends[i][k] == 1 && !visited[k]) {
        dfs(friends, k, visited);
      } }
  }

  int findCircleNum(vector<vector<int>>& friends) {
    int n = friends.size(), count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(friends, i, visited);
        ++count;
      } }
    return count;
  }
};

int main(){
  vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
  Solution test;
  cout << test.findCircleNum(isConnected) << endl;
  return 0;
}