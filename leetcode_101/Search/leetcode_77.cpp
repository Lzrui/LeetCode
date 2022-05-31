#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curr;
    dfs(res,curr,n,k,1);
    return res;
  }

  void dfs(vector<vector<int>>& res,vector<int>& curr,int n,int k,int pos){
    if(curr.size() == k){
      res.emplace_back(curr);
      return;
    }
    for(int i = pos;i<=n;++i){
      curr.emplace_back(i);
      dfs(res,curr,n,k,i+1);
      curr.pop_back();
    }
  }
};
int main(){
  int n = 4,k =2;
  Solution test;
  vector<vector<int>> res = test.combine(n,k);
  return 0;
}