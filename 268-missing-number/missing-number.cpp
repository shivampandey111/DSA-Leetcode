class Solution {
public:
    int getSum(vector<int>& nums, int sum){
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int currSum = getSum(nums, sum);
        int totalSum = 0;
        for(int i = 1; i<=nums.size(); i++){
            totalSum += i;
        }
        return totalSum-currSum;
    }
};