class Solution {
public:
    int getIdx(vector<int>& nums, int fast){
        int n = nums.size();
        return (((fast + nums[fast]) % n + n) % n);
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                continue;
            }
            int slow = i;
            int fast = i;
            int curr = nums[i];
            while(true){
                if((nums[slow]*curr)<=0) break;
                if((nums[fast]*curr)<=0) break;
                int nextFast = getIdx(nums, fast);
                if((nums[nextFast]*curr)<=0) break;
                slow = getIdx(nums,slow);
                fast = getIdx(nums, nextFast);
                if(slow==fast){
                    if(slow != getIdx(nums,slow)) return true;
                    else break;
                }
            }
            int current = i;
            while(nums[current]*current>0){
                int next = getIdx(nums, current);
                nums[current] = 0;
                current = next;
            }
        }
        return false;
    }
};