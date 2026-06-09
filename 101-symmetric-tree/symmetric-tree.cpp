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
    bool func(TreeNode* first, TreeNode* second){
        if(first==NULL && second==NULL) return true;
        if(first==NULL || second==NULL) return false;
        if(first->val!=second->val) return false;
        bool left = func(first->left, second->right);
        bool right = func(first->right, second->left);
        if(left && right) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return func(root->left, root->right);
    }
};