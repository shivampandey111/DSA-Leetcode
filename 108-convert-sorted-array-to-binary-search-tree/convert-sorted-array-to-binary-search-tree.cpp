class Solution {
public:
    unordered_map<int, int> freq;
    TreeNode* func(vector<int>& nums, int low, int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = func(nums, low, mid-1);
        node->right = func(nums, mid+1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);
    }
};