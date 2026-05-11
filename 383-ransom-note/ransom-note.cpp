class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;

        for(char c:a){
            f1[c]++;
        }
        for(char c:b){
            f2[c]++;
        }
        int i = 0;
        while(i<f1.size()){
            if(f1[i]>f2[i]){
                return false;
            }
            i++;
        }
        return true;
    }
};