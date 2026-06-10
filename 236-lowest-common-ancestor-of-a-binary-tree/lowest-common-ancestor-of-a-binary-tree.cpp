/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int func(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return 0;
        int left = func(root->left, p, q);
        int right = func(root->right, p, q);
        int self = 0;
        if(p==root || q==root) self++;
        int total = self + left + right;
        if(total == 2 && ans == NULL){
            ans = root;
            return total;
        }
        return total;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root, p, q);
        return ans;
    }
};