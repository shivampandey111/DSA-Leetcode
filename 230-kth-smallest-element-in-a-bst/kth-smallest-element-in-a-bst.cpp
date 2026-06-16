class Solution {
public:
#define null NULL
    int res = 0;
    int count = 0;
    void func(TreeNode* root, int k){
        if(root==null) return;
        func(root->left, k);
        count++;
        if(count==k){
            res = root->val;
        }
        func(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==null) return 0;
        func(root, k);
        return res;
    }
};