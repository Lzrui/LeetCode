#include<bits/stdc++.h>

using namespace std;
//双指针
class Solution {
 public:
  static int findClosest(vector<string>& words, string word1, string word2) {
    int length = words.size();
    int ans = length;
    int index1 = -1, index2 = -1;
    for (int i = 0; i < length; i++) {
      string word = words[i];
      if (words[i] == word1) {
        index1 = i;
      } else if (words[i] == word2) {
        index2 = i;
      }
      if (index1 >= 0 && index2 >= 0) {
        ans = min(ans, abs(index1 - index2));
      }
    }
    return ans;
  }
};

int main(){
  vector<string> words = {"I","am","a","student","from","a","university","in","a","city"};
  string word1("a"),word2("student");
  cout << Solution::findClosest(words,word1,word2) << endl;
  return 0;
}