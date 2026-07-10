class Solution {
public:
    int count = 0;
    int fun(vector<int>& nums, int n, int i, int k, vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==0){
            return 0;
        }
        if(k==4) {
            int c1 = fun(nums, n, i+1, 3, dp) - nums[i];
            int c2 = fun(nums, n, i+1, 4, dp);
            return dp[i][k] = max(c1, c2);
        }
        else if(k==3) {
            int c1 = fun(nums, n, i+1, 2, dp) + nums[i];
            int c2 = fun(nums, n, i+1, 3, dp);
            return dp[i][k] = max(c1, c2);
        }
        else if(k==2) {
            int c1 = fun(nums, n, i+1, 1, dp) - nums[i];
            int c2 = fun(nums, n, i+1, 2, dp);
            return dp[i][k] = max(c1, c2);
        }
        else {
            int c1 = fun(nums, n, i+1, 0, dp) + nums[i];
            int c2 = fun(nums, n, i+1, 1, dp);
            return dp[i][k] = max(c1, c2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(5, -1);
            dp[i] = temp;
        }
        int res = fun(prices, n, 0, 4, dp);

        return res;
    }
};