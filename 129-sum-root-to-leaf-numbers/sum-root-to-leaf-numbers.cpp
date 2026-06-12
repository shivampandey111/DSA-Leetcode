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
    int getInt(string s){
        int num = 0;
        for(char c:s){
            num = num * 10 + (c - '0');
        }
        return num;
    }
    int res = 0;
    void func(TreeNode* root, string s){
        if(root==NULL) return;
        s += root->val + '0';
        if(root->left==NULL && root->right==NULL){
            res += getInt(s);
            return;
        }
        func(root->left, s);
        func(root->right, s);
        return;
    }
    int sumNumbers(TreeNode* root) {
        string s;
        func(root, s);
        return res;
    }
};