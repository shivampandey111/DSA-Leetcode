class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> f;
        
        for(int i = 0; i<text.size(); i++){
            if(text[i]=='b'||text[i]=='a'||text[i]=='l'||text[i]=='o'||text[i]=='n'){
                f[text[i]]++;
            } 
        }
        
         return min({
        f['b'],
        f['a'],
        f['l'] / 2,
        f['o'] / 2,
        f['n']
    });
        return 0;
    }
};