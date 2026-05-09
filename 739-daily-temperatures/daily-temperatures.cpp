class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n);
        stack<int> st;
        st.push(n-1);
        res[n-1] = 0;

        for(int i = n-2; i>=0; i--){
            while( !(st.empty()) && t[i]>=t[st.top()] ){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                res[i] = 0;
            }
            else{
                int len = st.top() - i;
                res[i] = len;
                st.push(i);
            }
        }
        return res;
    }
};