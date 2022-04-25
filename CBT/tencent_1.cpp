//
// Created by l50021384 on 2022/4/25.
//
#include<bits/stdc++.h>
using namespace std;
string s[111111],t[11];
int a[101010];
int main(){
  int n,i,j;
  cin >> n;
  for(i=0;i<n;++i) cin >> t[i];
  for(i=0;i<n;++i){
    for(j=0;j<t[i].size();++j){
      s[j] += t[i][j];
    }
  }
  for(i=0;i<t[0].size();++i) a[i] = stoi(s[i]);
  sort(a,a+t[0].size());
  for(i=0;i<t[0].size();++i) cout << a[i] << ' ';
  return 0;
}