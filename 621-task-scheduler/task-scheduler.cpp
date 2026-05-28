class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i = 0; i<tasks.size(); i++){
            freq[tasks[i]]++;
        }
        int maxi = 0;
        for(auto val:freq){
            maxi = max(maxi, val.second);
        }
        // priority_queue<pair<char, int>> pq;
        // for(auto val:freq){
        //     int first = val.second;
        //     char second = val.first;
        //     pair<int, char> curr = {first, second};
        //     pq.push(curr);
        // }
        // int maxi = pq.top().first;

        int countMax = 0;
        for(auto val:freq){
            if(val.second==maxi){
                countMax++;
            }
        }
        // while(!pq.empty()){
        //     int curr = pq.top().first;
        //     pq.pop();
        //     if(curr==maxi){
        //         countMax++;
        //     }
        // }
        int res =max((int)tasks.size(), (maxi-1)*(n+1)+countMax);
        return res;
    }
};