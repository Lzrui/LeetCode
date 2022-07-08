#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
 public:
  static int minCostToMoveChips(vector<int>& position) {
    int even = 0,odd = 0;
    for(auto &idx:position){
      if((idx & 1) == 0) ++odd;
      else ++even;
    }
    return min(odd,even);
  }
};

int main(){
  vector<int> position = {2,2,2,3,3};
  cout << Solution::minCostToMoveChips(position) << endl;
  return 0;
}