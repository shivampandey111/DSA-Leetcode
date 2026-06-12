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
    int res = 0;
    void func(TreeNode* root, int s){
        if(root==NULL) return;
        s = s * 10 + root->val;
        if(root->left==NULL && root->right==NULL){
            res += s;
            return;
        }
        func(root->left, s);
        func(root->right, s);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int curNum = 0;
        func(root, curNum);
        return res;
    }
};