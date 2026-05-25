class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        unordered_map<char, int> freq;
        string res = "";
        for(int i = 0; i<s.size(); i++){
            freq[s[i]]++;
        }
        for(auto val:freq){
            int first = val.second;
            char second = val.first;
            pair<int, char> curr = {first, second};
            pq.push(curr);
        }
        while(!pq.empty()){
            pair<int, char> p = {pq.top().first, pq.top().second};
            pq.pop();
            if((res.size()==0) || (res[res.size()-1]!=p.second)){
                res += p.second;
                p.first--;
                if(p.first>0)
                pq.push(p);
            }
            else{
                if(pq.empty()){
                    return "";
                }
                else{
                    pair<int, char> p2 = {pq.top().first, pq.top().second};
                    pq.pop();
                    res += p2.second;
                    p2.first--;
                    if(p2.first>0){
                        pq.push(p2);
                    }
                    pq.push(p);
                }
            }
        }
        return res;
    }
};