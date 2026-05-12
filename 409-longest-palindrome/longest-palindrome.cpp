class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int res = 0;
        bool odd = false;
        for(char ch:s){
            freq[ch]++;
        }
        for(auto val:freq){
            if((val.second)%2 == 0){
                res = res + val.second;
            }
            else{
                res = res + val.second-1;
                odd = true;
            }
        }
        if(odd)
        res = res + 1;
        return res;
    }
};