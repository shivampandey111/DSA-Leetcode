class Solution {
public:
    bool check(int arr1[], int arr2[]){
        for(int i=0; i<256; i++){
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int low = 0;
        int high = p.length()-1;

        vector<int> result;
        if(s.size()<p.size()) return result;
        int freq[256] = {0};
        int current[256] = {0};

        for(char c:p){
            freq[c - 'a']++;
        }
        for(int i=0; i<=high; i++){
            current[s[i]-'a']++;
        }
        while(high<s.length()){
            if(check(freq, current)){
                result.push_back(low);
            }
            low++;
            high++;
            current[s[low-1]-'a']--;
            if(high<s.length())
            current[s[high]-'a']++;
        }
        return result;
    }
};