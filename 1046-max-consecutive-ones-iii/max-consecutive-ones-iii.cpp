class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int result = 0;
        int count = 0;


        for(int high = 0; high<nums.size(); high++){

            if(nums[high]==0){
                count++;
            }
            while(count>k){
                if(nums[low]==0){
                    count--;
                }
                low++;
            }
            int len = high - low +1;
            result = max(result, len);
        }
        return result;
    }
};