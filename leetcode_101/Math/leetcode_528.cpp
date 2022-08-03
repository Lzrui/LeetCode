#include<bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> sums;
 public:
  Solution(vector<int>& w) : sums(std::move(w)) {
    partial_sum(sums.begin(), sums.end(), sums.begin());
  }

  int pickIndex() {
    int pos = rand() % sums.back() + 1;
    return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
  }
};

int main(){
  vector<int> w = {1, 3, 5};
  Solution *obj = new Solution(w);
  for (int i = 0; i < 10; ++i) {
    cout << obj->pickIndex() << endl;
  }
  return 0;
}