class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        int result = 0;
        for(int val:nums){
            freq[val]++;
            if(freq[val]>1){
                result = val;
            }
        }
       return result; 
    }
};