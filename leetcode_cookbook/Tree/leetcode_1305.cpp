//
// Created by l50021384 on 2022/4/6.
//
#include <bits/stdc++.h>
#include <functional>
using namespace std;
//中序遍历+归并排序
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
    static vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        auto inorder =
        [](TreeNode* root,vector<int>& res){
            stack<TreeNode*> st;
            while(root || !st.empty()){
                while(root){
                    st.emplace(root);
                    root = root->left;
                }
                TreeNode* node = st.top();
                res.emplace_back(node->val);
                st.pop();
                root = node->right;
            }
        };

        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> merged;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (true) {
            if (p1 == nums1.end()) {
                merged.insert(merged.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                merged.insert(merged.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                merged.push_back(*p1++);
            } else {
                merged.push_back(*p2++);
            }
        }
        return merged;
    }
};
int main(){
    TreeNode node3 = TreeNode(1);
    TreeNode node4 = TreeNode(4);
    TreeNode node1 = TreeNode(2, &node3,&node4);
    TreeNode node5 = TreeNode(0);
    TreeNode node6 = TreeNode(3);
    TreeNode node2 = TreeNode(1, &node5,&node6);
    vector<int> res = Solution::getAllElements(&node1,&node2);
    return 0;
}



