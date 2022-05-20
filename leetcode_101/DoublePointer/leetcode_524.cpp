#include<bits/stdc++.h>

using namespace std;
//双指针
class Solution {
  public:
  static string findLongestWord(string s, vector<string>& dictionary) {
    string max_str;
    int m = s.size();
    for(auto &str:dictionary){
      int i = 0,j = 0,n=str.size();
      while(i < m && j < n){
        if(s[i] == str[j])
          ++j;
        ++i;
      }
      if(j == n){
        if(n > max_str.size() || (n == max_str.size() && str < max_str))
          max_str = str;
      }
    }
    return max_str;
  }
};

int main(){
  string s("abpcplea");
  vector<string> dictionary = {"ale","apple","monkey","plea"};
  cout << Solution::findLongestWord(s,dictionary) << endl;
  return 0;
}