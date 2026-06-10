class Solution {
public:
    TreeNode* ans = NULL;
    void func(TreeNode* root, TreeNode* p, TreeNode*q){
        if(root==NULL) return;
        if(root->val==p->val || root->val==q->val){
            ans = root;
            return;
        }
        if(root->val<p->val){
            func(root->right, p, q);
        }
        else if(root->val>q->val){
            func(root->left, p, q);
        }
        else{
            ans = root;
            return;
        }
    }


    // int func(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if(root==NULL) return 0;
    //     int left = 0;
    //     int right = 0;
    //     if(root->val>p->val && root->val<q->val){
    //         left = func(root->left, p, q);
    //         right = func(root->right, p, q);
    //     }
    //     else if(root->val>p->val || root->val>q->val){
    //         left = func(root->left, p, q);
    //     }
    //     else if(root->val<p->val || root->val<q->val){
    //         right = func(root->right, p, q);
    //     }
    //     int self = 0;
    //     if(root->val == p->val || root->val == q->val){
    //         self++;
    //     }
    //     int total = left + self + right;
    //     if(total==2 && ans ==NULL){
    //         ans = root;
    //         return total;
    //     }
    //     return total;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            func(root, q, p);
        }
        else func(root, p, q);
        return ans;
    }
};