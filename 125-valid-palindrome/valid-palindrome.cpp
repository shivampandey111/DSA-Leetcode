class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        string newS = "";
        for(int i = 0; i<size; i++){
            if(s[i]>='a' && s[i]<='z'){
                newS += s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                char c = s[i] - 'A' + 'a';
                newS += c;
            }
            else if(s[i]>=48 && s[i]<=57){
                newS += s[i];
            }
            else continue;
        }
        int low = 0; 
        int high = newS.size()-1;

        while(low<=high){
            if(newS[low]!=newS[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};