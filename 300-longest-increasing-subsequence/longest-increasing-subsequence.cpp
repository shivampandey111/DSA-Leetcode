class Solution {
public:
    // int fun(vector<int>& nums, int prev, int n, int i, vector<vector<int>>& dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     if(prev==-1 || nums[i]>nums[prev]){
    //         int c1 = 1 + fun(nums, i, n, i+1, dp);
    //         int c2 = fun(nums, prev, n, i+1, dp);
    //         return dp[i][prev+1] = max(c1, c2);
    //     }
        
    //     return dp[i][prev+1] = fun(nums, prev, n, i+1, dp);
        
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1);
        // for(int i = 0; i<=n; i++){
        //     vector<int> temp(n+1, -1);
        //     dp[i] = temp;
        // }
        int res = 0;
        vector<int> dp(n);
        for(int i = 0; i<n; i++){
            dp[i] = 1;
            for(int j = 0; j<i; j++){
                if(nums[j]<nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        for(int i = 0; i<n; i++){
            res = max(res, dp[i]);
        }
        return res;
        // return fun(nums, -1, n, 0, dp);
    }
};