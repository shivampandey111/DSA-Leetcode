class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; 
        int fast = 0;
        int count = 0;
        while(slow<=fast && fast<nums.size()){
            if(nums[fast]==val){
                fast++;
            }
            else{
                swap(nums[slow],nums[fast]);
                slow++;
                fast++;
                count++;
            }
        }
        return count;
    }
};