class Solution {
public:
    long long dist(vector<int>& p){
        return p[0]*p[0] + p[1]*p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>> pq;
        unordered_map<int, long long> freq;
        for(int i = 0; i<points.size(); i++){
            long long distance = dist(points[i]);
            freq[i] = distance;
        }
        for(auto val:freq){
            int first = val.first;
            long long second = val.second;
            pair<long long, int> curr = {second, first};
            if(pq.size()<k){
                pq.push(curr);
            }
            else if(curr.first<pq.top().first){
                pq.pop();
                pq.push(curr);
            }
            else continue;
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
    }
};