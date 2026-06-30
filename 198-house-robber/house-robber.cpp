class Solution {
public:
    int fun(vector<int>& nums, int i, int n, int free, vector<vector<int>>& f){
        if(i==n) return 0;
        if(f[i][free]!=-1) return f[i][free];
        if(free==0) return f[i][free] = fun(nums, i+1, n, 1, f);
        int a = nums[i] + fun(nums, i+1, n, 0, f);
        int b = fun(nums, i+1, n, 1, f);
        return f[i][free] = max(a, b);

        // if(i==0) return nums[0];
        // if(i==1) return max(nums[0], nums[1]);
        // if(freq.find(i)!=freq.end()){
        //     return freq[i];
        // }
        // dp[i] = max(nums[i] + fun(nums, dp, i-2), fun(nums, dp, i-1));
        // freq[i] = dp[i];
        // return dp[i];
         
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 0);
        int free = 0;
        // dp[n-1] = fun(nums, dp, n-1);
        vector<vector<int>> f(n);
        for(int i = 0; i<n; i++){
            vector<int> t(2, -1);
            f[i] = t;
        }
        int ans = fun(nums, 0, n, 1, f);
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
        return ans;
    }
};