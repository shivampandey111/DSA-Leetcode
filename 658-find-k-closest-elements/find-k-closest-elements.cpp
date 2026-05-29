class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        if(x<=arr[0]){
            for(int i = 0; i<k; i++){
                res.push_back(arr[i]);
            }
            return res;
        }
        for(int i = 0; i<k; i++){
            int first = abs(arr[i]-x);
            int second = arr[i];
            pair<int, int> curr = {first, second};
            pq.push(curr);
        }
        for(int i = k; i<arr.size(); i++){
            int diff = abs(arr[i]-x);
            int maxi = pq.top().first;
            if(diff<pq.top().first || diff==pq.top().first && arr[i]<pq.top().second){
                pq.pop();
                pq.push({diff, arr[i]});
            }
        }
        while(!pq.empty()){
            int element = pq.top().second;
            res.push_back(element);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};