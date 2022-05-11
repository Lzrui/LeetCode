//
// Created by lzr on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Codec {
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res;
    vector<int> arr;
    postorder(root,arr);
    if(arr.empty())
      return res;
    for(int i= 0;i<arr.size()-1;++i)
      res.append(to_string(arr[i])+',');
    res.append(to_string(arr.back()));
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(const string& data) {
    if(data.empty())
      return nullptr;
    vector<int> arr = split(data,',');
    stack<int> st;
    for(auto &num:arr)
      st.emplace(num);
    return construct(INT_MIN, INT_MAX,st);
  }

  void postorder(TreeNode *root,vector<int> &arr){
    if(root == nullptr)
      return;
    postorder(root->left,arr);
    postorder(root->right,arr);
    arr.emplace_back(root->val);
  }

  static vector<int> split(const string& data,char c){
    vector<int> res;
    int start,pos = 0;
    while(pos < data.size()){
      while(pos < data.size() && data[pos] == c)
        ++pos;
      start = pos;
      while(pos < data.size() && data[pos] != c)
        ++pos;
      res.emplace_back(stoi(data.substr(start,pos-start)));
    }
    return res;
  }

  TreeNode* construct(int lower,int upper,stack<int> &st){
    if(st.empty() || st.top() < lower || st.top() > upper)
      return nullptr;
    int val = st.top();
    st.pop();
    auto *root = new TreeNode(val);
    root->right = construct(val,upper,st);
    root->left = construct(lower,val,st);
    return root;
  }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
int main(){
  TreeNode ll(2),lr(4),left(3);
  left.left = &ll;
  left.right =&lr;
  TreeNode rl(6),rr(8),right(7);
  right.left = &rl;
  right.right =&rr;
  TreeNode root(5);
  root.left = &left;
  root.right = &right;
  auto* ser = new Codec();
  auto* deser = new Codec();
  string tree = ser->serialize(&root);
  TreeNode* ans = deser->deserialize(tree);
  return 0;
}
