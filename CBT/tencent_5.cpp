//
// Created by l50021384 on 2022/4/25.
//
#include<bits/stdc++.h>
using namespace std;
long long dp[2020][2020],a[2222];
int main(){
  int n,m,i,j;
  cin >> n >> m;
  for(i=0;i<=n+1;++i)
    for(j=0;j<=n+1;++j)
      dp[i][j] = -1e16;
  dp[0][0] = m;
  for(i=1;i<=n;++i)
    cin >> a[i];
  for(i=1;i<=n;++i){
    for(j=0;j<=n;++j){
      //持有不动的情况
      dp[i][j] = dp[i-1][j];
      //如果j大于0且前一天的现金数目大于今天的股票价格，则有可能是持有不动或者买入一只股票转化而来的状态
      if(j && dp[i-1][j-1] >= a[i])
        dp[i][j] = max(dp[i][j],dp[i-1][j-1]-a[i]);
      //前一天卖出一只股票，和暂时最优结果比较，哪个现金数目多
      dp[i][j] = max(dp[i][j],dp[i-1][j+1]+a[i]);
    }
  }
  long long res = 0;
  for(i=0;i<=n;++i)
    res = max(res,dp[n][i]+i*a[n]);
  cout << res << endl;
  return 0;
}