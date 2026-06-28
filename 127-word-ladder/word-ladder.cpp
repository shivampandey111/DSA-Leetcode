class Solution {
public:
    int ladderLength(string b, string e, vector<string>& l) {
        unordered_map<string, int> freq;
        for(string c:l){
            freq[c]++;
        }
        queue<pair<string, int>> q;
        q.push({b, 1});
        if(freq[b]==0) freq[b]++;
        if(freq[e]==0) return 0;

        while(!q.empty()){
            pair<string, int> curr = q.front();
            q.pop();
            string s = curr.first;
            int val = curr.second;
            if(s==e) return val;
            freq.erase(s);
            for(int i = 0; i<s.size(); i++){
                char c = s[i];
                for(int j = 97; j<=122; j++){
                    if(c==j) continue;
                    s[i] = j;
                    if(freq[s]){
                        q.push({s, val+1});
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};