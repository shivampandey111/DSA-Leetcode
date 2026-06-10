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
    TreeNode* ans = NULL;
    void func(TreeNode* root, int val){
        if(root==NULL) return;
        if(root->val==val){
            ans = root;
            return;
        }
        if(root->val>val){
            func(root->left, val);
        }
        else if(root->val<val){
            func(root->right, val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        func(root, val);
        return ans;
    }
};