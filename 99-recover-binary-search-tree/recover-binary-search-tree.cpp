class Solution {
public:
    #define null NULL
    int count = 0;
    TreeNode* prev = null;
    TreeNode* ff = null;
    TreeNode* fs = null;
    TreeNode* sf = null;
    TreeNode* ss = null;
    void func(TreeNode* root){
        if(root==null) return;
        func(root->left);
        if(prev==null) prev = root;
        else{
            if(prev->val>root->val){
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
        if(root==null) return;
        func(root);
        if(count==1){
            swap(ff->val, fs->val);
        }
        else{
            swap(ff->val, ss->val);
        }

    }
};