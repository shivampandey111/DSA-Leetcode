class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            if(res!=nums[i]){
                if(count==0){
                    res = nums[i];
                    count++;
                }
                else count--;
            }
            else count++;
        }
        return res;
    }
};