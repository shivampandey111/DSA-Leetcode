class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for(char x:s){
            freq[x]++;
        }
        int times = freq[s[0]];
        for(auto x:freq){
            if(x.second!=times) return false;
        }
        return true;
    }
};