class Solution {
public:
    bool exists(int map1[], int map2[]){
            for(int i=0; i<256; i++){
               if(map1[i]<map2[i]){
                return false;
               }
            }
            return true;
        }
    string minWindow(string s, string t) {
        int low =0;
        int result[256]={0};
        int mini[256]={0};
        int resultlen = INT_MAX;
        int start =0;
        for(char val:t){
            mini[val]++;
        }
        for(int high =0; high<s.length(); high++){
            result[s[high]]++;
            while(exists(result, mini)){
                int len = high - low +1;
                if(resultlen>len){
                    resultlen = len;
                    start = low;
                }
                result[s[low]]--;
                low++;
            }
        }
        if(resultlen == INT_MAX) return "";

        return s.substr(start, resultlen);
    }
};
