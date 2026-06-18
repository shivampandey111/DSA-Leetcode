class Solution {
public:
    int res = 0;
    void dfs(vector<vector<int>>& list,int node, vector<bool>& visited){
        visited[node] = 1;
        for(int i = 0; i<list[node].size(); i++){
            int neigh = list[node][i];
            if(visited[neigh]==0)
            dfs(list, neigh, visited);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        vector<vector<int>> list(n);
        for(int i = 0; i<n; i++){
            vector<int> t = c[i];
            for(int j = 0; j<t.size(); j++){
                if(t[j]==1){
                    list[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, 0);
        for(int i = 0; i<n; i++){
            if(visited[i]==0){
                dfs(list, i, visited);
                res++;
            }
        }
        return res;
    }
};