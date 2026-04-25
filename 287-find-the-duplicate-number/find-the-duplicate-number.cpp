class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast){
                slow = 0;
                while(slow!=fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
        
        
        
        
    //     unordered_map<int, int> freq;
    //     int result = 0;
    //     for(int val:nums){
    //         freq[val]++;
    //         if(freq[val]>1){
    //             result = val;
    //         }
    //     }
    //    return result; 
    }
};