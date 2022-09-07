#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reorderSpaces(string text) {
    int n = text.size();
    vector<string> words = split(text, ' ');
    int cntSpace = n;
    int wordCount = 0;
    for (auto & word : words) {
      if (word.size() > 0) {
        cntSpace -= word.size();
        ++wordCount;
      }
    }

    string ans;
    if (words.size() == 1) {
      ans.append(words[0]);
      ans.append(cntSpace, ' ');
      return ans;
    }
    int preSpace = cntSpace / (wordCount - 1);
    int restSpace = cntSpace % (wordCount - 1);
    for (auto & word : words) {
      if (ans.size() > 0) {
        ans.append(preSpace, ' ');
      }
      ans.append(word);
    }
    ans.append(restSpace, ' ');
    return ans;
  }

  vector<string> split(string &str, char ch) {
    int n = str.size();
    vector<string> ans;
    int pos = 0;
    while (pos < n) {
      while (pos < n && str[pos] == ch) {
        ++pos;
      }
      if (pos < n) {
        int curr = pos;
        while (pos < n && str[pos] != ch) {
          ++pos;
        }
        ans.emplace_back(str.substr(curr, pos - curr));
      }
    }
    return ans;
  }
};

int main() {
  Solution test;
  string text(" practice   makes   perfect");
  string ans = test.reorderSpaces(text);
  return 0;
}

