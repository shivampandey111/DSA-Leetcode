class Solution {
public:
    int fun(vector<int>& nums, int n, int amt, int i, vector<vector<int>>& dp){
        if(amt==0) return 0;
        if(i==n || amt<0) return 1e9;
        if(dp[i][amt]!=-1) return dp[i][amt];
        if(nums[i]>amt) dp[i][amt] = fun(nums, n, amt, i+1, dp);
        int c1 = 1 + fun(nums, n, amt-nums[i], i, dp);
        int c2 = fun(nums, n, amt, i+1, dp);

        return dp[i][amt] = min(c1, c2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1) ;
        for(int i = 0; i<=n; i++){
            vector<int> temp(amount+1, -1);
            dp[i] = temp; 
        }
        int res = fun(coins, n, amount, 0, dp) ;
        if(res==1e9) return -1;
        return res;
        
    }
};