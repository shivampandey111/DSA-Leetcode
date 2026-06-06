class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int res = -1e9;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                count = 0;
            }
            else{
                count++;   
                res = max(count, res);
            }
        }
        if(res==-1e9) return 0;
        return res;
    }
};