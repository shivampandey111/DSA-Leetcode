class Solution {
public:
    int minimum(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        int mini = 0;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=nums[high]){
                if(nums[mid]<nums[mini])
                mini = mid;
                low = mid +1;
            }
            else if(nums[mid]<=nums[high]){
                high = mid -1;
                if(nums[mini]>nums[mid])
                mini = mid;
            }
        }
        return mini;
    }

    int search(vector<int>& nums, int target) {
        int mini = minimum(nums);
        int n = nums.size()-1;
        int low = 0;
        int high= n;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[mid]>target && target>=nums[low]){
                    high = mid -1;
                }
                else{
                    low= mid +1;
                }
            }
            else{
                if(nums[mid]<target && target<=nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        // int sL = 0;
        // int hH = low -1;
        // if(low==0){
        //     while(low<=high){
        //         int mid = (low+high)/2;
        //         if(nums[mid]==target) return mid;
        //         else if(nums[mid]>target) high = mid -1;
        //         else{
        //             low = mid +1;
        //         }
        //     }
        //     return -1;
        // }
        // while(low<=high){
        //         int mid = (low+high)/2;
        //         if(nums[mid]==target) return mid;
        //         else if(nums[mid]>target) high = mid -1;
        //         else{
        //             low = mid +1;
        //         }
        //     }
        
        // while(sL<=hH){
        //     int mid = sL + (hH-sL)/2;
        //     if(nums[mid]==target){
        //         return mid;
        //     } 
        //     else if(nums[mid]>target) hH = mid -1;
        //     else{
        //         sL = mid +1;
        //     }
        // }

        return -1;
    }
};