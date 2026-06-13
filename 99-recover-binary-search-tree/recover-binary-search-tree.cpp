class Solution {
public:
    TreeNode* prev = NULL;
    int count = 0;
    TreeNode* ff = NULL;
    TreeNode* fs = NULL;
    TreeNode* sf = NULL;
    TreeNode* ss = NULL;
    void func(TreeNode*& root){
        if(root==NULL) return;
        func(root->left);
        if(prev==NULL){
            prev = root;
        }
        else{
            if(root->val<prev->val){
                if(count==0){
                    ff = prev;
                    fs = root;
                    count++;
                }
                else{
                    sf = prev;
                    ss = root;
                    count++;
                }
            }
            prev = root;
        }
        func(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        func(root);
        if(count==1){
            swap(ff->val, fs->val);
        }
        else{
            swap(ff->val, ss->val);
        }
    }
};