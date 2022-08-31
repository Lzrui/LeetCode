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
  int pathSum(TreeNode* root, int targetSum) {
    return root? pathSumWithRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum): 0;
  }

  long long pathSumWithRoot(TreeNode *root, int targetSum) {
    if (!root)
      return 0;
    long long count = root->val == targetSum? 1: 0;
    count += pathSumWithRoot(root->left, targetSum - root->val);
    count += pathSumWithRoot(root->right, targetSum - root->val);
    return count;
  }

};


int main() {
  return 0;
}

