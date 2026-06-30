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
        // vector<int> dp(n+1, 0);
        if(n==0 || n==1) return n;
        // dp[1] = 0;
        // int i = 1;
        int p = 1;
        int pp = 0;
        int i = 2;
        int ans = 0;
        while(i<=n){
            ans = p + pp;
            pp = p;
            p = ans;
            i++;
        }
        return ans;
    }
};