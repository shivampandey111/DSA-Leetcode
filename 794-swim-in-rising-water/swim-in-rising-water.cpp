class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>>& grid, int mid, int n, int m){
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n);
        q.push({0,0});
        for(int i = 0; i<n; i++){
            vector<int> temp(m, 0);
            visited[i] = temp;
        }
        visited[0][0] = 1;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            int row = curr.first;
            int col = curr.second;
            q.pop();
            if(row==n-1 && col==m-1){
                return true;
            }
            for(int k = 0; k<4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(valid(r, c, n, m) && visited[r][c]!=1 && grid[r][c]<=mid){
                    visited[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = 0;
        vector<vector<int>> visited(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                high = max(high, grid[i][j]);
            }
        }
        int res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(bfs(grid, mid, n, m)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};