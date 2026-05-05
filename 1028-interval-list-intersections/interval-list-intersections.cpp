class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> res;
       
        if(fl.size()==0 || sl.size()==0){
            return res;
        }
        
        int i = 0;
        int j = 0;
        while(i<fl.size() && j<sl.size()){
            int start = max(fl[i][0],sl[j][0]);
            int end = min(fl[i][1], sl[j][1]);

            if(start<=end) res.push_back({start, end});

            if(fl[i][1]<sl[j][1]) i++;
            else j++;
        }

        sort(res.begin(), res.end());

        return res;
    }
};