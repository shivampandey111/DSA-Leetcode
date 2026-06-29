class Solution {
public:
unordered_map<int, int> dp;
    int fun(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp.find(n)!=dp.end()) return dp[n];
        int ans = fun(n-1) + fun(n-2);
        dp[n] = ans;
        return ans;
    }
    int climbStairs(int n) {
        int res = fun(n);
        return res;
    }
};