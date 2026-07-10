class Solution {
public:
    int fun(vector<int>& nums, int i, int k, int n, vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==0){
            return dp[i][k] = fun(nums, i, 2, n, dp);
        }
        if(k==2){
            int c1 = fun(nums, i+1, 1, n, dp) - nums[i];
            int c2 = fun(nums, i+1, 2, n, dp);
            return dp[i][k] = max(c1, c2);
        }
        else {
            int c1 = fun(nums, i+1, 0, n, dp) + nums[i];
            int c2 = fun(nums, i+1, 1, n, dp);
            return dp[i][k] = max(c1, c2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(3, -1);
            dp[i] = temp;
        }
        int res = fun(prices, 0, 2, n, dp);
        return max(res, 0);
    }
};