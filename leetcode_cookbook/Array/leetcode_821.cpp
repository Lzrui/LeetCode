#include <vector>
#include <queue>
#include <iostream>
using namespace std;
//两次遍历
//class Solution {
// public:
//  static vector<int> shortestToChar(string s, char c) {
//    int n = s.length();
//    vector<int> ans(n);
//
//    for (int i = 0, idx = -n; i < n; ++i) {
//      if (s[i] == c) {
//        idx = i;
//      }
//      ans[i] = i - idx;
//    }
//
//    for (int i = n - 1, idx = 2 * n; i >= 0; --i) {
//      if (s[i] == c) {
//        idx = i;
//      }
//      ans[i] = min(ans[i], idx - i);
//    }
//    return ans;
//  }
//};
//BFS
class Solution {
 public:
  static vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> res(n,-1);
    queue<int> qu;
    for(int i = 0;i <n;++i){
      if(s[i] == c){
        qu.emplace(i);
        res[i] = 0;
      }
    }
    int lr[2] = {-1,1};
    while(!qu.empty()){
      int idx = qu.front();
      qu.pop();
      for(auto &dir:lr){
        int curr = idx+dir;
        if(curr >= 0 && curr<n && res[curr] == -1){
          res[curr] = res[idx] + 1;
          qu.emplace(curr);
        }
      }
    }
    return res;
  }
};
int main(){
    string s("loveleetcode");
    char c = 'e';
    vector<int> res = Solution::shortestToChar(s,c);
    return 0;
}