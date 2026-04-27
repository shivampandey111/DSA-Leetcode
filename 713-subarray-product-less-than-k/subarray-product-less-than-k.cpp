class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int product = 1;
        int result = 0;
        int high = low;
        while(high<nums.size() && low<nums.size()){
            
            product *= nums[high];
            if(product<k){
                result++;
                high++;
                if(high == nums.size() && low<nums.size()){
                    high = low+1;
                    low++;
                    product = 1;
                }
            }
            else{
                low++;
                product = 1;
                high = low;
            }

        }
        return result;
    }
};