class Solution {
public:
    // int fun(vector<vector<int>>& nums, int n, int m, int i, int j, vector<vector<int>>& dp){
    //     if(i == n-1 && j == m-1){
    //         return 1;
    //     }
    //     if(i == n || j == m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int c1 = fun(nums, n, m, i+1, j, dp);
    //     int c2 = fun(nums, n, m, i, j+1, dp);
    //     return dp[i][j] = c1+c2;
    // }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(m+1);
            dp[i] = temp;
        }
        dp[n-1][m-1] = 1;
        for(int i = 0; i<=n; i++) dp[i][m] = 0;
        for(int i = 0; i<=m; i++) dp[n][i] = 0;

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i==n-1 && j==m-1) continue;
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
        // return fun(nums, n, m, 0, 0, dp);
    }
};