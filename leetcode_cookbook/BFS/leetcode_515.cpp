#include<bits/stdc++.h>

using namespace std;
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
 public:
  static void dfs(vector<int>& res, TreeNode* root, int curHeight) {
    if (curHeight == res.size()) {
      res.push_back(root->val);
    } else {
      res[curHeight] = max(res[curHeight], root->val);
    }
    if (root->left) {
      dfs(res, root->left, curHeight + 1);
    }
    if (root->right) {
      dfs(res, root->right, curHeight + 1);
    }
  }

   static vector<int> largestValues(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<int> res;
    dfs(res, root, 0);
    return res;
  }
};
// bfs
//class Solution {
// public:
//  static vector<int> largestValues(TreeNode* root) {
//    if(!root) return {};
//    vector<int> res;
//    queue<TreeNode*> qu;
//    qu.emplace(root);
//    while(!qu.empty()){
//      int n = qu.size();
//      int max = INT_MIN;
//      for(int i=0;i<n;++i){
//        TreeNode *node = qu.front();
//        qu.pop();
//        max = node->val>max?node->val:max;
//        if(node->left) qu.emplace(node->left);
//        if(node->right) qu.emplace(node->right);
//      }
//      res.emplace_back(max);
//    }
//    return res;
//  }
//};

int main(){
  TreeNode a(2),b(3);
  TreeNode root(1,&a,&b);
  vector<int> res = Solution::largestValues(&root);
  return 0;
}