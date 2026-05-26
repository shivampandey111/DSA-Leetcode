class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int> pq;
        vector<vector<int>> sorted;
        for(int i = 0; i<p.size(); i++){
            int profit = p[i];
            int capital = c[i];
            vector<int> res = {capital, profit};
            sorted.push_back(res);
        }
        sort(sorted.begin(), sorted.end());
        int idx=0;
        while(k--){
            while(idx<sorted.size()){
                if(sorted[idx][0]>w) break;
                else{
                    pq.push(sorted[idx][1]);
                    idx++;
                }
            }
            if(pq.empty()) return w;
            else{
                w = w + pq.top();
                pq.pop();
            }
        }
        return w;
    }
};