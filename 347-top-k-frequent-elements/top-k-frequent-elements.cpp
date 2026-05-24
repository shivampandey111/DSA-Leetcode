class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> freq;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<int> res;
        for(auto i:freq){
            int element = i.first;
            int f = i.second;
            pair<int, int> curr = {f, element};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first>pq.top().first){
                pq.pop();
                pq.push(curr);
            }
            else continue;
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};