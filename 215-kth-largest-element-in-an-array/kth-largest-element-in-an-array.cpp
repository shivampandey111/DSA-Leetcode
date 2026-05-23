class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int small = nums.size()-k;
        for(int i = 0; i<=small; i++){
            pq.push(nums[i]);
        }
        for(int i = small+1; i<nums.size(); i++){
            if(nums[i]>=pq.top()){
                continue;
            }
            else{
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};