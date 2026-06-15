class Solution {
public:
    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;

        bool left = check(p->left, q->left);
        bool right = check(p->right, q->right);
        
        if(left && right) return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = check(p, q);
        return res;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(subRoot==NULL) return true;
        if(isSameTree(root, subRoot)){
            return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        if(left || right) return true;
        return false; 
    }
};