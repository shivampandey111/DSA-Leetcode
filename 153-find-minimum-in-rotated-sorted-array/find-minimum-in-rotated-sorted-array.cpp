class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int res = 1e9;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid]>=nums[high]){
                res = min(nums[mid], res);
                low = mid +1;
            }
            else if(nums[mid]<=nums[high]){
                high = mid -1;
                res = min(nums[mid], res);
            }
        }
        return res;
    }
};