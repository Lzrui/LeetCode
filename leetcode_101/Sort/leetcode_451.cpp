#include<bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
class Solution {
 public:
  static string frequencySort(string s) {
    vector<int> counts(128);
    int max_count = 0;
    for(auto &ch:s){
      max_count = max(max_count,++counts[ch]);
      }
    string res;
    vector<vector<int>> freqs(max_count+1);
    for(int i = 0;i<counts.size();++i){
      freqs[counts[i]].emplace_back(i);
    }
    for(int i = max_count;res.size() < s.size();--i){
      for(auto &ch:freqs[i]){
        res.append(string(i,ch));
      }
    }
    return res;
  }
};

int main(){
  string s("tRee1333");
  cout << Solution::frequencySort(s) << endl;
  return 0;
}