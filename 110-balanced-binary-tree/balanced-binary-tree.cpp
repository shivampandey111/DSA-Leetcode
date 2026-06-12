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
    bool res = true;
    int func(TreeNode* root){
        if(root==NULL) return 0;
        int left = func(root->left);
        int right = func(root->right);
        int diff = abs(left-right);
        if(diff>1 && res){
            res = false;
            return 0;
        }
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        func(root);
        if(res) return true;
        return false;
    }
};