//
// Created by l50021384 on 2022/4/6.
//
#include<vector>
#include <stack>
#include <iostream>
using namespace std;
//栈
class Solution {
 public:
   static int lengthLongestPath(string input) {
    int n = input.size();
    int pos = 0, res = 0;
    stack<int> st;
    while(pos < n){
      //统计当前文件深度
      int depth = 0;
      while(pos < n && input[pos] == '\t'){
        ++pos;
        ++depth;
      }
      //统计当前文件长度
      bool isFile = false;
      int len = 0;
      while(pos < n && input[pos] != '\n'){
        if(input[pos] == '.')
          isFile = true;
        ++pos;
        ++len;
      }
      //跳过换行符
      ++pos;
      //如果文件深度小于栈深度，目录出栈
      while(depth < st.size()){
        st.pop();
      }
      //统计当前路径长度
      if(!st.empty()){
        len += st.top()+1;
      }
      //如果是文件则统计绝对路径长度，否则将目录长度入栈
      if(isFile){
        res = max(res,len);
      }
      else{
        st.emplace(len);
      }
    }
    return res;
  }
};

int main(){
    string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout << Solution::lengthLongestPath(s) << endl;
    return 0;
}
