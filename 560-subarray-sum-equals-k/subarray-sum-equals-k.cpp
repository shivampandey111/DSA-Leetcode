class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int result = 0;
        int sum = 0;
        freq[0] = 1;

        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
    
                result += freq[sum-k];
            
            freq[sum]++;
        }
        return result;
    }
};