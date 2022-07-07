#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
 public:
  string replaceWords(vector<string>& dictionary, const string& sentence) {
    sort(dictionary.begin(),dictionary.end(),[](const string &a,const string &b){return a.size() < b.size();});
    string res,temp;
    istringstream words(sentence);
    while(words >> temp){
        add_sub(temp,res,dictionary);
      }
    return res.substr(0,res.size()-1);
    }

    void add_sub(const string &temp,string &res,vector<string>& dictionary){
    for(auto &str:dictionary){
      if(str.size()>=temp.size()){
        res.append(temp+" ");
        return;
      }
      int i=0,j=0;
      while(i<str.size()){
        if(str[i] == temp[j]){
          ++i;
          ++j;
        }
        else break;
      }
      if(i == str.size()){
        res.append(str+" ");
        return;
      }
    }
    res.append(temp+" ");
 }
};

int main(){
  vector<string> dictionary = {"cat","bat","rat"};
  string sentence("the cattle was rattled by the battery");
  Solution test;
  cout << test.replaceWords(dictionary,sentence) << endl;
  return 0;
}