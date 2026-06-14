class Solution {
public:
    unordered_map<int, int> freq;
    int idx = 0;
    TreeNode* func(vector<int>& p, int low, int high){
        if(low>high) return NULL;
        TreeNode* node = new TreeNode(p[idx]);
        idx--;
        int id = freq[node->val];
        node->right = func(p, id+1, high);
        node->left = func(p, low, id-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        idx = p.size()-1;
        for(int i = 0; i<in.size(); i++){
            freq[in[i]] = i;
        }
        return func(p, 0, p.size()-1);
    }
};