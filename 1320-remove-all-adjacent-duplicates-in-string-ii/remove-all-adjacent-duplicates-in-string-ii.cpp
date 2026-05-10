class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        int n = s.size();
        for(int i = 0; i<s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
                continue;
            }
            if(st.top().first != s[i]){
                st.push({s[i], 1});
                continue;
            }
            if(st.top().first==s[i]){
                if(st.top().second<k-1){
                    pair<char, int> p = st.top();
                    st.pop();
                    st.push({p.first, p.second+1});
                }
                else{
                    st.pop();
                }
            }
        }
        string res = "";
        while(!(st.empty())){
            pair<char, int> p = st.top();
            while(p.second!=0){
                  res += p.first;
                  p.second--;
            }
          
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};