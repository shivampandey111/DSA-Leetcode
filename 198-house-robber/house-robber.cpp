class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int i = 0;
        while(i<n){
            if(i==0){
                dp[i] = nums[0];
            }
            else if(i==1){
                dp[i] = max(nums[0], nums[1]);
            }
            else{
                dp[i] = max( nums[i] + dp[i-2], dp[i-1] );
            }
            i++;
        }
        return dp[n-1];
    }
};