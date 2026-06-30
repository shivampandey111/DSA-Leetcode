class Solution {
public:
// unordered_map<int, int> dp;
//     int fun(int n){
//         if(n==0) return 0;
//         if(n==1) return 1;
        
//         if(dp.find(n)!=dp.end()) return dp[n];

//         int ans1 = fun(n-1);
//         int ans2 = fun(n-2);

//         dp[n] = ans1+ans2;
        
//         return ans1 + ans2;
//     }
    int fib(int n) {
        vector<int> dp(n+1, 0);
        if(n==0) return 0;
        dp[1] = 0;
        int i = 1;
        while(i<=n){
            if(i==1) dp[1] = i + dp[i-1];
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
            i++;
        }
        return dp[n];
    }
};