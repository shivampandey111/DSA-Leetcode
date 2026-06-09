/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* p, TreeNode* q, bool& is){
        if(p==NULL && q==NULL){
            is = true;
            return;
        }
        if(p==NULL || q==NULL){
            is = false;
            return;
        }
        if(p->val!=q->val){
            is = false;
            return;
        }
        if(!is) return;
        check(p->left, q->left, is);
        if(!is) return;
        check(p->right, q->right, is);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is = true;
        check(p, q, is);
        return is;
    }
};