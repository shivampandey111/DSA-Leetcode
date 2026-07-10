class Solution {
public:
    int fun(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 1e9;
        for(int k = i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1];
            int r = cost + fun(cuts, i, k-1, dp) + fun(cuts, k+1, j, dp);
            dp[i][j] = min(res, r);
            res = min(res, r);
        }
        return res;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int> cut;
        cut.push_back(0);
        for(int i = 0; i<cuts.size(); i++){
            cut.push_back(cuts[i]);
        }
        cut.push_back(n);
        sort(cut.begin(), cut.end());
        int s = cut.size();
        vector<vector<int>> dp(s-1);
        for(int i = 0; i<=s-2; i++){
            vector<int> temp(s-1, -1);
            dp[i] = temp;
        }
        return fun(cut, 1, s-2, dp);
    }
};