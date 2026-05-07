class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> rev;

        for(int i =0; i<s.size(); i++){
            rev.push(s[i]);
        }
        int i=0;
            while((!rev.empty()) && i<s.size()){
                s[i] = rev.top();
                rev.pop();
                i++;
            }
        
    }
};