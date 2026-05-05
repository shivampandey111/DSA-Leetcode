class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> result;

        int s1 = a[0][0];
        int e1 = a[0][1];

        for(int i =1; i<a.size(); i++){
           int s2 = a[i][0];
           int e2 = a[i][1];

            if(e1>=s2){
                s1 = s1;
                e1 = max(e1, e2);
                continue;
            }
            result.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
        result.push_back({s1, e1});


        return result;
    }
};