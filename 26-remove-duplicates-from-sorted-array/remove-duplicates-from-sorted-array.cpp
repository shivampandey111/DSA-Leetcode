class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        int res=1;
        int fast=1;
        while(fast<nums.size()){
            if(nums[fast]==nums[fast-1]){
                fast++;
            }
            else{
                nums[slow+1]=nums[fast];
                res++;
                slow++;
                fast++;
            }
        }
        return {res};
    }
};