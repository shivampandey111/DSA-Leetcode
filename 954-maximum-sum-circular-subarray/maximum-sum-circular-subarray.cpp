class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxBest = nums[0];
        int minBest = nums[0];
        int result = nums[0];
        int globalMax = nums[0];
        int globalMin = nums[0];
        int totalSum = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxBest = max(nums[i]+maxBest, nums[i]);
            minBest = min(nums[i]+minBest, nums[i]);
            globalMax = max(globalMax, maxBest);
            globalMin = min(globalMin, minBest);
            totalSum += nums[i];
        }
        int circular = totalSum - globalMin;
        if(globalMax<0) return globalMax;
        result = max(globalMax, circular);
        return result;
    }
};