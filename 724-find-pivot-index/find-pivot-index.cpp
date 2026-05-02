class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix = 0;
        int suffix = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            suffix = suffix + nums[i+1];
        }
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(prefix==suffix) return i;
            }
            else{
                prefix = prefix + nums[i-1];
                suffix = suffix - nums[i];
            }
            if(prefix==suffix){
                return i;
            }
        }
        return -1;
    }
};