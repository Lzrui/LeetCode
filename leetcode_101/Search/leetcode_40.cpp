#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int target,n;
  vector<vector<int>> res;

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> curr;
    n = candidates.size();
    this->target = target;
    dfs(candidates,curr,0,0);
    return res;
  }

  void dfs(vector<int>& candidates, vector<int> &curr,int idx,int val){
    if(val == target){
      res.emplace_back(curr);
      return;
    }
    for(int i=idx;i<n;++i){
      if(i>idx && candidates[i] == candidates[i-1]) continue;
      int rs = candidates[i]+val;
      if(rs<=target){
        curr.emplace_back(candidates[i]);
        dfs(candidates,curr,i+1,rs);
        curr.pop_back();
      }
      else break;
    }
    }

};

int main(){
  vector<int> candidates = {1,2,2,2,5};
  int target = 5;
  Solution test;
  vector<vector<int>> res = test.combinationSum2(candidates,target);
  return 0;
}