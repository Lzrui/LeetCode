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
//BFS
//class Solution {
// public:
//  int deepestLeavesSum(TreeNode* root) {
//    queue<TreeNode*> qu;
//    qu.emplace(root);
//    int res = 0;
//    while (!qu.empty()) {
//      int n = qu.size();
//      res = 0;
//      for (int i = 0; i < n; ++i) {
//        TreeNode * node = qu.front();
//        res += node->val;
//        qu.pop();
//        if (node->left) qu.emplace(node->left);
//        if (node->right) qu.emplace(node->right);
//      }
//    }
//    return res;
//  }
//};

//DFS
class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    dfs(root, 1);
    return sum;
  }

  void dfs(TreeNode *node, int depth) {
    if (node == nullptr)
      return;
    if (depth > Max_Level) {
      Max_Level = depth;
      sum = node->val;
    }
    else if (depth == Max_Level) {
      sum += node->val;
    }
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  }

 private:
  int Max_Level = -1;
  int sum = 0;
};

int main() {
  return 0;
};

