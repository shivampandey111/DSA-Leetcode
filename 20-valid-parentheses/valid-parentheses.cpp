class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char> st;

        for(char ch : s){
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            } 
            else if(ch==')' || ch==']' || ch=='}'){
                if(st.empty() || st.top() != bracket[ch]) return false;
                 st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};