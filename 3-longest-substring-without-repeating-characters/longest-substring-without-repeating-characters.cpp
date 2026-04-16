class Solution {
public:
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int low = 0;
    int result = 0;

    for(int high = 0; high<s.size(); high++){
        freq[s[high]]++;

        int len = high - low + 1;

        if(freq.size()==len){
            result = max(result, len);
        }

        while(freq.size()<len){
            freq[s[low]]--;
            if(freq[s[low]]==0){
                freq.erase(s[low]);
            }
            low++;
            len = high - low + 1;
        }
       
    }
    return result;
}
};