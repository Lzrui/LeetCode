#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int mySqrt(int x) {
    int l = 1,r = x;
    while(l <= r){
      int mid = l+(r-l)/2;
      if(mid * mid == x)
        return  mid;
      else if(mid *mid > x)
        r = mid-1;
      else l = mid+1;
    }
    return r;
  }
};

int main(){

  int x = 16;
  cout << Solution::mySqrt(x) << endl;
  return 0;
}