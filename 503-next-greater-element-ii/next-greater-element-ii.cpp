class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n);
        for(int i = nums.size()-2; i>=0; i--){
            st.push(nums[i]);
        }
        //Search space is the whole array except the last element
        for(int i = nums.size()-1; i>=0; i--){
            while( !(st.empty()) && nums[i]>=st.top() ){
                st.pop();
            }
            if(st.empty()){
                result[i] = -1;
                st.push(nums[i]);
            }
            else{
                result[i] = st.top();
                st.push(nums[i]);
            }
        }
        return result;
    }
};