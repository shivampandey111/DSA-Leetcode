class Solution {
public:
    void func(vector<int>& cand, int idx, int size, int sum, int target, vector<int>& curr, vector<vector<int>>& res){
        if(idx==size){
            if(sum==target){
                res.push_back(curr);
            }
            return;
        }
        func(cand, idx+1, size, sum, target, curr, res);

        if(sum + cand[idx] <= target){
            curr.push_back(cand[idx]);

            func(cand, idx, size, sum + cand[idx], target, curr, res);

            curr.pop_back();
        }
        return;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        #define cand candidates
        int idx = 0;
        int size = cand.size();
        int sum = 0;
        vector<int> curr;
        vector<vector<int>> result;
        func(cand, idx, size, sum, target, curr, result);
        return result;
    }
};