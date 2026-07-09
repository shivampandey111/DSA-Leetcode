class Solution {
public:
    // int fun(string& text1, string& text2, int n, int m, int i, int j, vector<vector<int>>& dp){
    //     if(i==n || j==m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] = 1 + fun(text1, text2, n, m, i+1, j+1, dp);
        
    //         int c1 = fun(text1, text2, n, m, i+1, j, dp);
    //         int c2 = fun(text1, text2, n, m, i, j+1, dp);
    //         return dp[i][j] = max(c1, c2) ;
        
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(m+1, -1);
            dp[i] = temp;
        }
        for(int i = 0; i<=m; i++) dp[n][i] = 0;
        for(int i = 0; i<=n; i++) dp[i][m] = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    int c1 = dp[i+1][j];
                    int c2 = dp[i][j+1];
                    dp[i][j] = max(c1, c2);
                }
            }
        }
        return dp[0][0];
        // return fun(text1, text2, n, m, 0, 0, dp);
    }
};