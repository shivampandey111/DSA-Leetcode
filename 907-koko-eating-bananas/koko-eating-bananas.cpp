class Solution {
public:
    long long fun(vector<int>& nums, int speed, int n){
        long long h = 0;
        for(int i = 0; i<n; i++){
            h = h + nums[i]/speed;
            if((nums[i])%speed!=0) h++;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        #define nums piles
        int low = 1;
        int high = 0;
        int res = -1;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            high = max(nums[i], high);
        }
        while(low<=high){
            int speed = low+ (high-low)/2;
            long hour = fun(nums, speed, n);
            if(hour>h){
                low = speed + 1;
            }
            else{
                res = speed;
                high = speed -1;
            }
        }
        return res;
    }
};