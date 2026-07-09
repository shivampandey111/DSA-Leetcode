class Solution {
public:
    int fun(vector<vector<int>>& nums, int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(i == n || j == m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1 = fun(nums, n, m, i+1, j, dp);
        int c2 = fun(nums, n, m, i, j+1, dp);
        return dp[i][j] = c1+c2;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> nums(n);
        for(int i = 0; i<n; i++){
            vector<int> temp(m, 0);
            nums[i] = temp;
        }
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(m+1, -1);
            dp[i] = temp;
        }

        return fun(nums, n, m, 0, 0, dp);
    }
};