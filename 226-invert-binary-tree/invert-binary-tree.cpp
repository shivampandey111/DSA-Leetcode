/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode*& t){
        if(t==NULL) return;
        swap(t->left, t->right);
        func(t->left);
        func(t->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        func(root);
        return root;
    }
};