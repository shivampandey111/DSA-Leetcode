class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    bool valid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n);
        for(int i = 0; i<n; i++){
            vector<int> temp(m, 1e9);
            dist[i] = temp;
        }
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();
            int d = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            if(d>dist[row][col]) continue;
            for(int k = 0; k<4; k++){
                int r = row + x[k]; 
                int c = col + y[k];
                if(!valid(r, c, n, m)) continue;
                int absDiff = abs(heights[row][col] - heights[r][c]);
                int newW = max(absDiff, d);
                if(newW<dist[r][c]){
                    dist[r][c] = newW;
                    pq.push({newW, {r, c}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};