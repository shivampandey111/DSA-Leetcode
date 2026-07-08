class Solution {
public:
    // int fun(vector<int>& nums, int pos){
    //     int n = nums.size();
    //     // vector<vector<int>> dp(n+1);
    //     // for(int i = 0; i<=n; i++){
    //     //     vector<int> temp(pos+1, -1);
    //     //     dp[i] = temp;
    //     // }
    //     // for(int i = 0; i<=pos; i++){
    //     //     dp[n][i] = 0;
    //     //     dp[n][0] = 1;
    //     // }
    //     // for(int i = n-1; i>=0; i--){
    //     //     for(int j = 0; j<=pos; j++){
    //     //         if(j<nums[i]) dp[i][j] = dp[i+1][j];
    //     //         else{
    //     //             dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j];
    //     //         }
    //     //     }
    //     // }
    //     // return dp[0][pos];
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(sum<abs(target)) return 0;
        if((sum+target)%2!=0) return 0;
        int pos = (sum+target)/2;

        vector<vector<int>> dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int> temp(pos+1, -1);
            dp[i] = temp;
        }
        for(int i = 0; i<=pos; i++){
            dp[n][i] = 0;
            dp[n][0] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=pos; j++){
                if(j<nums[i]) dp[i][j] = dp[i+1][j];
                else{
                    dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][pos];
    }
};