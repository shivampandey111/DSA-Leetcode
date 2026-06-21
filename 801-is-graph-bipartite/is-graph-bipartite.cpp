class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c){
        color[node] = c;
        for(int i = 0; i<graph[node].size(); i++){
            int neigh = graph[node][i];
            if(color[neigh]!=-1 && color[neigh]==c){
                res = false;
            }
            if(color[neigh]==-1){
                dfs(graph, color, neigh, 1-c);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            if(color[i]==-1){
                dfs(graph, color, i, 0);
            }
        }
        return res;
    }
};