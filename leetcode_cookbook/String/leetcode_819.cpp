//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//哈希表 + 计数
class Solution {
public:
    static string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (auto & word : banned) {
            bannedSet.emplace(word);
        }
        int maxFrequency = 0;
        unordered_map<string, int> frequencies;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++) {
            if (i < length && isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } else if (!word.empty()) {
                if (!bannedSet.count(word)) {
                    frequencies[word]++;
                    maxFrequency = max(maxFrequency, frequencies[word]);
                }
                word = "";
            }
        }
        string mostCommon;
        for (auto &value : frequencies) {
            if (value.second == maxFrequency) {
                mostCommon = value.first;
                break;
            }
        }
        return mostCommon;
    }
};

int main(){
  string paragraph("Bob hit a ball, the hit BALL flew far after it was hit.");
  vector<string> banned = {"hit"};
  cout << Solution::mostCommonWord(paragraph,banned) << endl;
  return 0;
}



