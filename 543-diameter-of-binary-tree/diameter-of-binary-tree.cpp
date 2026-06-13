class Solution {
public:
    int res = -1;
    int func(TreeNode* root){
        if(root==NULL){
            return 0;
        };
        int left = func(root->left);
        int right = func(root->right);
        int sum = left+right;
        res = max(sum, res);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        func(root);
        return res;
    }
};