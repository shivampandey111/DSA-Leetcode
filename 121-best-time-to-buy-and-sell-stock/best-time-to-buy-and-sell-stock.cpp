class Solution {
public:
    int fun(vector<int>& nums, int n, int i, int k, vector<vector<int>>& dp){
        if(i==n) return 0;
        if(k==0) return 0; //Can do nothing
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==2) { // Buy, can't sell
            int c1 = fun(nums, n, i+1, 1, dp) - nums[i];
            int c2 = fun(nums, n, i+1, 2, dp);
            return dp[i][k] = max(c1, c2);
        }
        else { // Sell only, can't buy
            int c1 = fun(nums, n, i+1, 0, dp) + nums[i];
            int c2 = fun(nums, n, i+1, 1, dp);
            return dp[i][k] = max(c1, c2);
        }
        // if(i==n) return 0;
        // if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        // if(prev!=-1){
        //     int diff = nums[i] - nums[prev];
        //     res = max(res, diff);
        //     return dp[i][prev+1] = fun(nums, n, i+1, prev, dp);
        // }
        // int c1 = fun(nums, n, i+1, i, dp);
        // int c2 = fun(nums, n, i+1, prev, dp);
        // return dp[i][prev+1] = max(c1, c2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(3, -1);
            dp[i] = temp;
        }
        for(int i = 0; i<3; i++){
            dp[n][i] = 0;
        }
        int res = fun(prices, n, 0, 2, dp);
        return max(0, res);
    }
};