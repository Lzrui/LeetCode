#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int candy(vector<int>& ratings) {
    int n = ratings.size();
    if(n < 2){
      return n;
    }
    vector<int> res(n,1);
    for(int i = 1;i<n;++i){
      if(ratings[i] > ratings[i-1]){
        res[i] = res[i-1]+1;
      }
    }
    for(int i = n-1;i>0;--i){
      if(ratings[i] < ratings[i-1]){
        res[i-1] = max(res[i]+1,res[i-1]);
      }
    }
    return accumulate(res.begin(),res.end(),0);
  }
};

int main()
{
  vector<int> ratings = {1,0,2};
  cout << Solution::candy(ratings) << endl;
  system("pause");
  return 0;
}