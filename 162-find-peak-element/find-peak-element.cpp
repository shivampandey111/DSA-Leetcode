class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-2;
        if(nums.size()==1) return 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if((nums[mid]>nums[mid+1]) && (nums[mid]>nums[mid-1])) return mid;
            if(nums[mid]<nums[mid+1]) low = mid + 1;
            else if(nums[mid]<nums[mid-1]){
                high = mid -1;
            }
        }
        if(nums[0]>nums[nums.size()-1]) return 0;
        else return nums.size()-1;
    }
};