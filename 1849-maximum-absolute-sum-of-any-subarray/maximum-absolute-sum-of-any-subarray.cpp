class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxBest = nums[0];
        int minBest = nums[0];
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            int maxi = max(maxBest+nums[i], nums[i]);
            int mini = min(minBest+nums[i], nums[i]);
            int curr = nums[i];

            maxBest = max(maxi, curr);
            minBest = min(mini, curr);

            result = max(result, max(abs(maxBest), abs(minBest)));
        }
        if(nums.size()==1){
            result = abs(nums[0]);
        }
        return result;
    }
};