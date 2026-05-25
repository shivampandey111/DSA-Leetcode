class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string>&a, pair<int,string>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            else{
                return a.second<b.second;
            } 
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> freq;
        for(int i = 0; i<words.size(); i++){
            freq[words[i]]++;
        }
        vector<string> res;
        for(auto i:freq){
            string element = i.first;
            int f = i.second;
            pair<int, string> curr = {f, element};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first==pq.top().first){
                if(curr.second<pq.top().second){
                    pq.pop();
                    pq.push(curr);
                }
            }
            if(curr.first>pq.top().first){
                pq.pop();
                pq.push(curr); 
            }
            else{
                continue;
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};