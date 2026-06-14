class Solution {
public:
    unordered_map<int, int> freq;
    TreeNode* func(vector<int>& nums, int low, int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        int id = freq[node->val];
        node->left = func(nums, low, id-1);
        node->right = func(nums, id+1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]] = i;
        }
        return func(nums, 0, nums.size()-1);
    }
};