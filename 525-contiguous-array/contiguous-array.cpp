class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int diff = 0;
        int noOne = 0;
        int noZero = 0;
        int len = 0;
        int resultLen = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) noZero++;
            if(nums[i]==1) noOne++;

            diff = (noZero - noOne);
            if(diff==0){
                resultLen = max(resultLen, i+1);
                continue;
            }
            if(freq[diff]==0){
                freq[diff] = i+1;
            } 
            else if(freq[diff]!=0){
                len = i+1-freq[diff];
                resultLen = max(resultLen, len);
            }
        }
        return resultLen;
    }
};