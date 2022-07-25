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

class CBTInserter {
 public:
  TreeNode *root;
  queue<TreeNode*> qu;

  CBTInserter(TreeNode* root) {
    this->root = root;
    qu.emplace(root);
    while(!qu.empty()){
      TreeNode *curr = qu.front();
      if(!curr->left || !curr->right)
        break;
      qu.pop();
      if(curr->left) qu.emplace(curr->left);
      if(curr->right) qu.emplace(curr->right);
    }
  }

  int insert(int val) {
    TreeNode *parent = qu.front();
    if(!parent->left){
      TreeNode *cld = new TreeNode(val);
      parent->left = cld;
    }
    else{
      TreeNode *cld = new TreeNode(val);
      parent->right = cld;
      qu.emplace(parent->left);
      qu.emplace(parent->right);
      qu.pop();
    }
    return parent->val;
  }

  TreeNode* get_root() {
    return root;
  }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */