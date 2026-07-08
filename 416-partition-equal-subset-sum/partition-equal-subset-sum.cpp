class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(sum+1, -1);
            dp[i] = temp;
        }
        for(int i = 0; i<=sum; i++){
            dp[n][i] = 0;
            dp[n][0] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=sum; j++){
                if(j<arr[i]) dp[i][j] = dp[i+1][j];
                else{
                    dp[i][j] = dp[i+1][j] || dp[i+1][j-arr[i]];
                }
            }
        }
        return dp[0][sum];
    }
};