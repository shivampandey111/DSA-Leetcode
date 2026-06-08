class Solution {
public:
    void func(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->val);
        func(root->left, res);
        func(root->right, res);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return res;
    }
};