#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  const int add = -1;
  const int sub = -2;
  const int multi = -3;

  vector<int> dfs(vector<vector<vector<int>>> &dp,int l,int r,const vector<int> &ops){
    if(dp[l][r].empty()){
      if(l == r) dp[l][r].emplace_back(ops[l]);
      else{
        for(int i=l;i<r;i+=2){
          auto left = dfs(dp,l,i,ops);
          auto right = dfs(dp,i+2,r,ops);
          for(auto &u:left)
            for(auto &v:right){
              if(ops[i+1] == add){
                dp[l][r].emplace_back(u+v);
              }
              else if(ops[i+1] == sub){
                dp[l][r].emplace_back(u-v);
              }
              else
                dp[l][r].emplace_back(u*v);
            }
        }
      }
    }
    return dp[l][r];
  }

  vector<int> diffWaysToCompute(string expression) {
    vector<int> ops;
    int n = expression.size();
    for(int i=0;i<n;){
      if(!isdigit(expression[i])){
        if(expression[i] == '+')
          ops.emplace_back(add);
        else if(expression[i] == '-')
          ops.emplace_back(sub);
        else
          ops.emplace_back(multi);
        ++i;
      }
      else{
        int temp = 0;
        while(i<n && isdigit(expression[i])){
          temp = temp*10 + expression[i]-'0';
          ++i;
        }
        ops.emplace_back(temp);
      }
    }
    int len = ops.size();
    vector<vector<vector<int>>> dp(len,vector<vector<int>>(len));
    return dfs(dp,0,len-1,ops);
  }
};

int main(){
  string  expression("2*3-4*5");
  Solution test;
  vector<int> res =  test.diffWaysToCompute(expression);
  return 0;
}