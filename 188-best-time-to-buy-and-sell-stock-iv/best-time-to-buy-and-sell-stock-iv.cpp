class Solution {
public:
    int fun(vector<int>& nums, int n, int k, int i, vector<vector<int>>& dp){
        if(i==n) return 0;
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k%2==0) {
            int c1 = fun(nums, n, k-1, i+1, dp) - nums[i];
            int c2 = fun(nums, n, k, i+1, dp);
            return dp[i][k] = max(c1, c2);
        }
        else {
            int c1 = fun(nums, n, k-1, i+1, dp) + nums[i];
            int c2 = fun(nums, n, k, i+1, dp);
            return dp[i][k] = max(c1, c2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = 2*k;
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(k+1, -1);
            dp[i] = temp;
        }
        int res = fun(prices, n, k, 0, dp);
        return res;
    }
};