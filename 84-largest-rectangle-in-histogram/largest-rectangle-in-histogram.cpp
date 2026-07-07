class Solution {
public:
    vector<int> nse(vector<int>& a){
        stack<int> st;
        int n = a.size();
        vector<int> prev(n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && a[i]<=a[st.top()]){
                st.pop();
            }
            if(st.empty()){
                prev[i] = n;
                st.push(i);
            }
            else{
                prev[i] = st.top();
                st.push(i);
            }
        }
        return prev;
    }
    vector<int> pse(vector<int>& a){
        stack<int> st;
        int n = a.size();
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
                st.push(i);
            }
            else{
                res[i] = st.top();
                st.push(i);
            }
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = pse(heights);
        vector<int> next = nse(heights);
        int res = 0;
        for(int i = 0; i<n; i++){
            int h = heights[i];
            int w = next[i] - prev[i] - 1;
            int area = h * w;
            res = max(res, area);
        }
        return res;
    }
};