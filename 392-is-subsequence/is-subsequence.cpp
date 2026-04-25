class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slow = 0;
        int fast = 0;
        if(s.length()==0){
            return true;
        }
        while(fast<t.length()){
            if(s[slow]==t[fast]){
                if(slow==s.length()-1){
                    return true;
                }
                slow++;
                fast++;
            }
            else{
                fast++;
            }
        }
        return false;
    }
};