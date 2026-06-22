class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> list(n+1);
        vector<int> dist(n+1, 1e9);
        for(int i = 0; i<times.size(); i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            list[s].push_back({d, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            pair<int, int> node = pq.top();
            pq.pop();
            int d = node.first;
            int curr = node.second;
            if(d>dist[curr]) continue;
            for(int i = 0; i<list[curr].size(); i++){
                int neigh = list[curr][i].first;
                int weigh = list[curr][i].second;
                if(d+weigh<dist[neigh]){
                    dist[neigh] = d+weigh;
                    pq.push({d+weigh, neigh});
                }
            }
        }
        int res = -1e9;
        for(int i = 1; i<dist.size(); i++){
            if(dist[i]==1e9){
                return -1;
            }
            else{
                res = max(res, dist[i]);
            }
        }
        return res;
    }
};