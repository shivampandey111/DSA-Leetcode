class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int best = nums[0];
        for(int i=1; i<nums.size(); i++){
            int sum1 = best + nums[i];
            int sum2 = nums[i];

            best = max(sum1, sum2);
            result = max(result, best);
        }
        return result;
    }
};