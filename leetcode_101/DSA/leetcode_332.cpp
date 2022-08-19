#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    unordered_map<string, multiset<string>> hash;
    for (auto & ticket : tickets) {
      hash[ticket[0]].emplace(ticket[1]);
    }
    stack<string> s;
    s.push("JFK");
    while (!s.empty()) {
      string str = s.top();
      if (hash[str].empty()) {
        ans.emplace_back(str);
        s.pop();
      }
      else {
        s.emplace(*hash[str].cbegin());
        hash[str].erase(hash[str].begin());
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  vector<string> res = Solution::findItinerary(tickets);
  return 0;
}

