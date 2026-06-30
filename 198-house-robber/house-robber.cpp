class Solution {
public:
unordered_map<int, int> freq;
    int fun(vector<int>& nums, vector<int>& dp, int i){
        if(i==0) return nums[0];
        if(i==1) return max(nums[0], nums[1]);
        if(freq.find(i)!=freq.end()){
            return freq[i];
        }
        dp[i] = max(nums[i] + fun(nums, dp, i-2), fun(nums, dp, i-1));
        freq[i] = dp[i];
        return dp[i];
         
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = fun(nums, dp, n-1);
        // int i = 0;
        // while(i<n){
        //     if(i==0){
        //         dp[i] = nums[0];
        //     }
        //     else if(i==1){
        //         dp[i] = max(nums[0], nums[1]);
        //     }
        //     else{
        //         dp[i] = max( nums[i] + dp[i-2], dp[i-1] );
        //     }
        //     i++;
        // }
        return dp[n-1];
    }
};