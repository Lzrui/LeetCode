#include<bits/stdc++.h>

using namespace std;
//贪心
class Solution {
 public:
  static vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
      return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
    });
    int n = people.size();
    vector<vector<int>> ans(n);
    for (const vector<int>& person: people) {
      int spaces = person[1] + 1;
      for (int i = 0; i < n; ++i) {
        if (ans[i].empty()) {
          --spaces;
          if (!spaces) {
            ans[i] = person;
            break;
          }
        }
      }
    }
    return ans;
  }
};


int main(){
  vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  vector<vector<int>> res = Solution::reconstructQueue(people);
  return 0;
}