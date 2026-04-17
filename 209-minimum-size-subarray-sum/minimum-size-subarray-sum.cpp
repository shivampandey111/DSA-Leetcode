class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum = 0;
        int high = 0;
        int result = INT_MAX;

        while(high<nums.size()){
            sum = sum + nums[high];
            while(sum>=target){
                int len = high - low +1;
                result = min(len, result);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(result==INT_MAX){
            result = 0;
        }
        return result;
    }
};