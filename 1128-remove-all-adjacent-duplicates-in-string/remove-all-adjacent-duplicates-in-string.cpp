class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        string result;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        for(int i =0; i<res.size(); i++){
            st.push(res[i]);
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};