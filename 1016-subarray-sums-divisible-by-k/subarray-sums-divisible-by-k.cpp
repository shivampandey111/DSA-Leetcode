class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            int div = sum % k;
            if(div<0) div = div + k;
            result += freq[div];
            freq[div]++;
        }
        return result;
    }
}; 