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
    int res = -1e9;
    int count = 0;
    void func(TreeNode* root, int count){
        if(root==NULL) return;
        count++;
        if(root->left==NULL && root->right==NULL){
            res = max(count, res);
            return;
        }
        func(root->left, count);
        func(root->right, count);
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        func(root, count);
        return res;
    }
};