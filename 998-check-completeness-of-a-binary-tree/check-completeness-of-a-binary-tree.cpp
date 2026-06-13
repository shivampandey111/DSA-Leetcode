class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool see = false;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t==NULL){
                see = true;
            }
            else{
                if(see) return false;
                else{
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        return true;
    }
};