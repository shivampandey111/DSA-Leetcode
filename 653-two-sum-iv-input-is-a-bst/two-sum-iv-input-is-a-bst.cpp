class Solution {
public:
    vector<int> temp;
    void func(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL){
            func(root->left);
        }
        temp.push_back(root->val);
        if(root->right!=NULL){
            func(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        func(root);
        int i = 0;
        int j = temp.size()-1;
        while(i<j){
            int sum = temp[i] + temp[j];
            if(sum==k) return true;
            if(sum<k) i++;
            if(sum>k) j--;
        }
        return false;
    }
};