class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, 1e9);
        vector<int> temp(n, 1e9);
        res[src] = 0;
        temp[src] = 0;
        
        for(int i = 0; i<k+1; i++){
            for(int j = 0; j<flights.size(); j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];

                if(temp[s]!=1e9 && temp[d]>res[s]+w){
                    temp[d] = res[s] + w;
                }
            }
            for(int i = 0; i<n; i++){
                res[i] = temp[i];
            }
        }
        if(temp[dst]==1e9) return -1;
        return temp[dst];

    }
};