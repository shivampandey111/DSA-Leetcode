class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int low = 0;
        int product = 1;
        int result = 0;
        for(int high = 0; high<nums.size(); high++){
            product *= nums[high];
            while(product>=k){
              product /= nums[low]; 
              low++; 
            }
        
                result += high-low +1;
                
        }
        return result;
    }
};