#include<bits/stdc++.h>

using namespace std;

// dfs
class Solution {
 public:
  void dfs(TreeNode *root, int height, int &curVal, int &curHeight) {
    if (root == nullptr) {
      return;
    }
    height++;
    dfs(root->left, height, curVal, curHeight);
    dfs(root->right, height, curVal, curHeight);
    if (height > curHeight) {
      curHeight = height;
      curVal = root->val;
    }
  }

  int findBottomLeftValue(TreeNode* root) {
    int curVal, curHeight = 0;
    dfs(root, 0, curVal, curHeight);
    return curVal;
  }
};
// bfs
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int ret;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p->right) {
        q.push(p->right);
      }
      if (p->left) {
        q.push(p->left);
      }
      ret = p->val;
    }
    return ret;
  }
};
