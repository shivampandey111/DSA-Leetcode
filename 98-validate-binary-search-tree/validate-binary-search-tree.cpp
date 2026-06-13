class Solution {
public:
    bool res = true;
    TreeNode* prev = NULL;
    void func(TreeNode* root, TreeNode*& prev){
        if(root==NULL) return;
        func(root->left, prev);
        if(prev && root->val<=prev->val){
            res = false;
        }
        prev = root;
        func(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        func(root, prev);
        return res;
    }
};