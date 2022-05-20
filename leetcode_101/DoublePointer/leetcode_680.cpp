#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool checkPalindrome(const string& s, int low, int high) {
    for (int i = low, j = high; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  static bool validPalindrome(string s) {
    int low = 0, high = s.size() - 1;
    while (low < high) {
      char c1 = s[low], c2 = s[high];
      if (c1 == c2) {
        ++low;
        --high;
      } else {
        return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
      }
    }
    return true;
  }
};

int main(){
  string s("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
  cout << Solution::validPalindrome(s) << endl;
  return 0;
}