class Solution {
public:
    bool exists(vector<int>& nums, int mid){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=mid) count++;
            if(count==mid) return true;
        }
        return false;
    }

    int hIndex(vector<int>& citations) {
        #define nums citations
        int low = 1;
        int high = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            high = max(high, nums[i]);
        }
        while(low<=high){
            int mid = (high+low)/2;
            if(exists(nums, mid)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};