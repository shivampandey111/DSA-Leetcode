class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        unordered_map<int, int> freq;
        for(int i = 0; i<stones.size(); i++){
            freq[stones[i]]++;
        }
        for(auto val:freq){
            int weight = val.first;
            int f = val.second;
            pair<int, int> curr = {weight, f};
            pq.push(curr);
        }
        while(!pq.empty()){
            if(pq.top().second>1){
                pair<int, int> element = {pq.top().first, pq.top().second};
                pq.pop();
                element.second -= 2;
                if(element.second>1){
                    pq.push(element);
                }
                if(pq.size()==0 && element.second==0) return 0;\
            }
            else{
                if(pq.size()==1){
                    return pq.top().first;
                }
                else{
                    pair<int, int> first= {pq.top().first, pq.top().second};
                    pq.pop();
                    pair<int, int> second = {pq.top().first, pq.top().second};
                    pq.pop();
                    if(second.second>1){
                        second.second--;
                        pq.push(second);
                    }
                    int remaining = first.first - second.first;
                    if(remaining>0){
                        pair<int, int> res = {remaining, 1};
                        pq.push(res);
                    }
                    else{
                        if(pq.size()==0) return 0;
                    }
                }
            }
        }
        return pq.top().first;
    }
};