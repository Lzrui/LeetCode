#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int maxChunksToSorted(vector<int>& arr) {
    int max_val = -1, n = arr.size(), res = 0;
    for (int i = 0; i < n; ++i) {
      max_val = max(max_val, arr[i]);
      if (i == max_val)
        ++res;
    }
    return res;
  }
};

int main(){
  vector<int> arr = {1, 0, 2, 3, 4};
  cout << Solution::maxChunksToSorted(arr) << endl;
  return 0;
}