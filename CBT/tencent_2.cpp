//
// Created by l50021384 on 2022/4/25.
//
#include<bits/stdc++.h>
using namespace std;
class Solution{
 public:
  int prime[201010];
  vector<int> reduce(vector<int> &a){
    vector<int> res;
    for(int i=2;i<=a.size();++i){
      if(!prime[i]) res.push_back(a[i-1]);
    }
    return res;
  }

  int getNumber(vector<int> &a){
    int i,j;
    for(i=2;i<=2e5;i++){
      if(!prime[i])
        for(j=2*i;j<=2e5;j+=i)
          prime[j]=1;
    }
    while(a.size()>1) a = reduce(a);
    return a[0];
  }
};

int main(){
  Solution test{};
  vector<int> a = {1,2,3,4,5,6,7,8};
  cout << test.getNumber(a) << endl;
  return 0;
}