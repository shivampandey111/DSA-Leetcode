class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& nI) {
        vector<vector<int>> res;
        int n = interval.size();
        vector<vector<int>> newArr;

        bool insert = false; 
        
        for(int i = 0; i<interval.size(); i++){
            if(insert == false && interval[i][0]>=nI[0]){
                newArr.push_back({nI[0],nI[1]});
                insert = true;
            }
            newArr.push_back({interval[i][0], interval[i][1]});
        }
        if(insert==false){
            newArr.push_back({nI[0], nI[1]});
        }

        int s1 = newArr[0][0];
        int e1 = newArr[0][1];

        for(int i = 1; i<newArr.size(); i++){
            int s2 = newArr[i][0];
            int e2 = newArr[i][1];

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