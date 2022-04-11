//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
//哈希表
const static string MORSE[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};

class Solution {
public:
    static int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> seen;
        for (auto &word: words) {
            string code;
            for (auto &c: word) {
                code.append(MORSE[c - 'a']);
            }
            seen.emplace(code);
        }
        return seen.size();
    }
};

int main(){
    vector<string> words{"gin", "zen", "gig", "msg"};
  cout << Solution::uniqueMorseRepresentations(words) << endl;
  return 0;
}



