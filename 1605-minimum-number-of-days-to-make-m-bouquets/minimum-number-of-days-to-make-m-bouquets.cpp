class Solution {
public:
    bool exists(vector<int>& nums, int m, int k, int mid){
        int f = 0;
        int b = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<=mid){
                f++;
            }
            else f = 0;
            if(f==k){
                b++;
                f=0;
            }
            if(b>=m) return true;
        }
        return false;
    }


    int minDays(vector<int>& nums, int m, int k) {
        long long low = 1e9;
        long long high = 0;
        int res = 0;
        if(nums.size()<((long long)m*k)) return -1;
        for(int i = 0; i<nums.size(); i++){
            low = min(low, (long long)nums[i]);
            high = max(high, (long long)nums[i]);
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(exists(nums, m, k, mid)){
                res = mid; 
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;

    }
};