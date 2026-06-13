class Solution {
public:
    bool res = true;
    void func(TreeNode* root, vector<int>& temp){
        if(root==NULL) return;
        func(root->left, temp);
        if(!temp.empty()){
            int last = temp.back();
            if(root->val<=last) res = false;
        }
        temp.push_back(root->val);
        func(root->right, temp);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        vector<int> temp;
        func(root, temp);
        return res;
    }
};