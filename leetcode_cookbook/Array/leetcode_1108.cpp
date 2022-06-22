#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
   static string defangIPaddr(string address) {
     string res;
     for(auto ch:address){
       if(ch != '.')
         res += ch;
       else res.append("[.]");
     }
     return res;
  }
};

int main(){
  string address("255.100.50.0");
  cout << Solution::defangIPaddr(address) << endl;
  return 0;
}