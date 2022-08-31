#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
  }

  int dfs(TreeNode *root) {
    if (!root)
      return 0;
    int left = dfs(root->left), right = dfs(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)
      return -1;
    return max(left, right) + 1;
  }

};


int main() {
  Solution test;
  bool res = test.isBalanced(nullptr);
  return 0;
}

