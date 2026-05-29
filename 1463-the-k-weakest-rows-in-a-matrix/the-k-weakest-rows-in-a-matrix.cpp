class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            if(a.first!=b.first){
                return a.first<b.first;
            }
            else return a.second<b.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i<mat.size(); i++){
            int count = 0; 
            for(int j = 0; j<mat[i].size(); j++){
                if(mat[i][j]==1) count++;
            }
            pair<int, int> curr = {count, i};
            pq.push(curr);

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};