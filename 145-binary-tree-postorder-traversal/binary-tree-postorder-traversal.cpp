class Solution {
public:
    void func(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        func(root->left, res);
        func(root->right, res);
        res.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return res;
    }
};