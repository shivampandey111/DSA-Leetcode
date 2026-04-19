class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(sum - target);
                
                if(min_diff>diff){
                    min_diff = diff;
                    res = sum;  
                }

                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                j++;
                }
                else{
                k--;
                } 
            }
        }
        return res;
    }
};