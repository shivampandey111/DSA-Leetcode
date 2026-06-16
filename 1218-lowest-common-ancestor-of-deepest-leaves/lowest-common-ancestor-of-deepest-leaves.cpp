class Solution {
public:
#define null NULL
    TreeNode* res = null;
    int func(TreeNode* root){
        if(root==null) return 0;
        int left = func(root->left);
        int right = func(root->right);
        if(left>right){
            func(root->left);
        }
        if(right>left){
            func(root->right);
        }
        if(left==right){
            res  = root;
        }
        return 1 + max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==null) return root;
        func(root);
        return res;
    }
};