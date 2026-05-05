class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& nI) {
        interval.push_back({nI[0], nI[1]});
        sort(interval.begin(), interval.end());

        vector<vector<int>> res;

        int s1 = interval[0][0];
        int e1 = interval[0][1];

        for(int i = 1; i<interval.size(); i++){
            int s2 = interval[i][0];
            int e2 = interval[i][1];

            if(e1>=s2){
                s1 = s1;
                e1 = max(e1, e2);
                continue;
            }
            res.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
        res.push_back({s1, e1});
        return res;
    }
};