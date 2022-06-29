#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  unsigned char key;
  int idx;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    srand((unsigned)time(NULL));
    key = rand()%256;
    idx = longUrl.find_last_of('/');
    string dest;
    for(int i=idx+1;i< longUrl.size();++i){
      dest.push_back(longUrl[i] ^ key);
    }
    return longUrl.substr(0,idx+1)+dest;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string res = shortUrl.substr(0,idx+1);
    for(int i=idx+1;i<shortUrl.size();++i){
      res.push_back(shortUrl[i] ^ key);
    }
    return res;
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(){
  string url = "https://leetcode.com/problems/design-tinyurl";
  Solution solution;
  string res = solution.decode(solution.encode(url));
  return 0;
}