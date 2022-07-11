#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class MagicDictionary {
 public:
  unordered_map<string, int> data;

  MagicDictionary() {}

  void buildDict(vector<string> dictionary) {
    for (auto s : dictionary) {
      ++data[s];
      const int n = s.size();
      for (int i = 0;i < n;++i) {
        const char c = s[i];
        s[i] = '*';
        ++data[s];
        s[i] = c;
      }
    }
  }

  bool search(string word) {
    const int n = word.size();
    const auto it = data.find(word);
    const int cnt = it != data.end() ? it->second : 0;
    for (int i = 0;i < n;++i) {
      const char c = word[i];
      word[i] = '*';
      const auto it = data.find(word);
      if (it != data.end() && it->second > cnt)
        return true;
      word[i] = c;
    }
    return false;
  }
};
int main(){
  vector<string> dictionary = {"hello", "leetcode"};
  MagicDictionary* obj = new MagicDictionary();
  obj->buildDict(dictionary);
  bool param_2 = obj->search("hello");
  return 0;
}