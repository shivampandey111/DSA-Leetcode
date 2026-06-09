class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        bool ltr = 1;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            int start = 0;
            int last = q.size()-1;
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                if(ltr){
                    temp[start] = t->val;
                    start++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            ltr = 1 - ltr;
            res.push_back(temp);
        }
        return res;
    }
};