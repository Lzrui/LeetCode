//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
//找到每一个单词 + 模拟
class Solution {
 public:
  static string toGoatLatin(string sentence) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int n = sentence.size();
    int i = 0, cnt = 1;
    string ans;

    while (i < n) {
      int j = i;
      while (j < n && sentence[j] != ' ') {
        ++j;
      }

      ++cnt;
      if (cnt != 2) {
        ans += ' ';
      }
      if (vowels.count(sentence[i])) {
        ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
      }
      else {
        ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
      }

      i = j + 1;
    }

    return ans;
  }
};
int main(){
  string s = "The quick brown fox jumped over the lazy dog";
  cout << Solution::toGoatLatin(s) << endl;
  return 0;
}



